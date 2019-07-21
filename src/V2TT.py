#!/bin/python3
import networkx as nx
import json
import sys
from os.path import dirname
#import matplotlib.pyplot as plt
from jinja2 import Template, Environment, FileSystemLoader #jinja2 is used to prduce c++ source code

'''
PROGRAM FLOW
1. Analyze Cicuit's netlist as a Directed Acyclic Graph.(stage, gate type, wire)
2. Generatae C++ code based on previous analysis.
'''
#Initialize arrays
gate_type={}
input_array = []
output_array = []
DFF_array = []

#Initialze a graph
CircuitGraph = nx.DiGraph()
CircuitGraph.add_node("In")
CircuitGraph.add_node("Out")

json_netlist = json.load(open(sys.argv[1], 'r'))["modules"]

for module_netlist in json_netlist.values():
    for port_json in module_netlist["ports"].values(): #Analyze circuit's input and output, then record it to arrays.
        if port_json["direction"] == "input":
            for bit in port_json["bits"]:
                CircuitGraph.add_edge("In",bit,weight = 0,type="input")
                input_array.append(bit)
        elif port_json["direction"] == "output":
            for bit in port_json["bits"]:
                CircuitGraph.add_edge(bit,"Out",weight = 0,type="output")
                output_array.append(bit)
        else:
            print("Port Definition Error") # For Debug.
            sys.exit(1)

    for cell_json in module_netlist["cells"].items(): #Analyze circuit itself to analyze how gates are connected.
        CircuitGraph.add_node(cell_json[0])
        gate_name = cell_json[1]["type"][2:-1]
        if gate_name == "ANDNOT": #Yosys's ANDNOT is equivalent to TFHE's ANDYN
            gate_name = "ANDYN"
        elif gate_name == "ORNOT": #Yosys's ORNOT is equivalent to TFHE's ORYN
            gate_name = "ORYN"
        gate_type[cell_json[0]] = gate_name #record gate type to array

        #record gates' connefcions to the graph.
        if gate_name == "DFF_P":
            CircuitGraph.add_edge(cell_json[1]["connections"]["D"][0],"Out",weight = 0) #Connect input wire to output port
            output_array.append(cell_json[1]["connections"]["D"][0]) #Add input wire to output array
            CircuitGraph.add_edge(cell_json[0],cell_json[1]["connections"]["Q"][0],weight = 0) #connect DFF to output wire
            input_array.append(cell_json[1]["connections"]["Q"][0]) #Add output wire to input port
            DFF_array.append([cell_json[1]["connections"]["Q"][0],cell_json[1]["connections"]["D"][0]])
        else:
            CircuitGraph.add_edge(cell_json[1]["connections"]["A"][0],cell_json[0],weight = -1) #connect input wire to gate
            CircuitGraph.add_edge(cell_json[1]["connections"]["B"][0],cell_json[0],weight = -1) #connect input wire to gate
            CircuitGraph.add_edge(cell_json[0],cell_json[1]["connections"]["Y"][0],weight = 0) #connect gate to output wire

#print(list(nx.DiGraph.predecessors(CircuitGraph,"$abc$49$auto$blifparse.cc:371:parse_blif$50")))
#nx.draw(CircuitGraph,labels=gate_type)
#plt.show()

total_step = -nx.algorithms.shortest_paths.weighted.bellman_ford_path_length(CircuitGraph,"In","Out") #Knowing Maximal stage may be simplify algorithm.

#Initialize
wire_set = set() #Currently, this implementation holding all wire's data all time. So, order is not important. This is subjecto to change.
gate_array = [[] for i in range(total_step)] #This array records which gates will be evaluated in each stage.
#print(total_step)

for stage in dict(nx.algorithms.shortest_paths.weighted.single_source_bellman_ford_path_length(CircuitGraph,"In")).items(): #Analyzing gates' stage.
    #print(stage)
    if type(stage[0]) is str and stage[0] != "In" and stage[0] != "Out":
        gate_array[-stage[1]-1].append(stage[0])
        out_wire = CircuitGraph.successors(stage[0])
        if not(out_wire in output_array):
            wire_set.add(list(CircuitGraph.successors(stage[0]))[0])

wire_array = list(wire_set) #To map wires to c++ array, give an order to wires.

#print(input_array)
#print(output_array)
#print(wire_array)
#print(gate_array)
#print(gate_type)

gate_template_array = [[] for i in range(total_step)]  #This array record output string for c++ code template.

#record output strings based on previous analyzing. Currentry,parallelization is implemented by openMP per stage.
for i in range(total_step):
    gate_stage = gate_array[i]
    for gate in gate_stage:
        result = ""
        ca = ""
        cb = ""

        wire = module_netlist["cells"][gate]["connections"]["Y"][0]
        if wire in output_array:
            result = "cipherout[" + str(output_array.index(wire)) + "]"
        else :
            result = "cipherwire["+ str(wire_array.index(wire)) + "]"

        wire = module_netlist["cells"][gate]["connections"]["A"][0]
        if wire in input_array:
            ca = "cipherin[" + str(input_array.index(wire)) + "]"
        else :
            ca = "cipherwire[" + str(wire_array.index(wire)) + "]"

        wire = module_netlist["cells"][gate]["connections"]["B"][0]
        if wire in input_array:
            cb = "cipherin["  + str(input_array.index(wire)) +"]"
        else :
            cb = "cipherwire[" + str(wire_array.index(wire)) + "]"

        gate_template_array[i].append([gate_type[gate],result,ca,cb])

DFF_template_array=[]
for DFF in DFF_array:
    DFF_template_array.append([input_array.index(DFF[0]),output_array.index(DFF[1])])

#print(template_array)

data ={"input_width":len(input_array), "output_width":len(output_array), "wire_max":len(wire_array), "gate_template_array":gate_template_array,"DFF_array":DFF_template_array,"number_of_DFF":len(DFF_template_array)} #Map recorded arrays to template's input.
cloud_template_result = Environment(loader=FileSystemLoader('.')).get_template("cloud.cpp.template").render(data) #Load template
#print(str(cloud_template_result))
with open(dirname(sys.argv[1])+"/cloud.cpp","w") as f:
    f.write(cloud_template_result) #generate c++ code