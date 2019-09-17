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

wire_set = set() #This hold all gate output

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
            CircuitGraph.add_edge("In",cell_json[1]["connections"]["Q"][0],weight = 0) #connect input port to output wire
            input_array.append(cell_json[1]["connections"]["Q"][0]) #Add output wire to input port
            DFF_array.append([cell_json[1]["connections"]["Q"][0],cell_json[1]["connections"]["D"][0]])

        elif gate_name == "NOT":
            CircuitGraph.add_edge(cell_json[1]["connections"]["A"][0],cell_json[0],weight = -1) #connect input wire to gate
            CircuitGraph.add_edge(cell_json[0],cell_json[1]["connections"]["Y"][0],weight = 0) #connect gate to output wire
            wire_set.add(cell_json[1]["connections"]["Y"][0])

        elif gate_name == "MUX":
            CircuitGraph.add_edge(cell_json[1]["connections"]["A"][0],cell_json[0],weight = -1) #connect input wire to gate
            CircuitGraph.add_edge(cell_json[1]["connections"]["B"][0],cell_json[0],weight = -1) #connect input wire to gate
            CircuitGraph.add_edge(cell_json[1]["connections"]["S"][0],cell_json[0],weight = -1) #connect input wire to gate
            CircuitGraph.add_edge(cell_json[0],cell_json[1]["connections"]["Y"][0],weight = 0) #connect gate to output wire
            wire_set.add(cell_json[1]["connections"]["Y"][0])
            
        else:
            CircuitGraph.add_edge(cell_json[1]["connections"]["A"][0],cell_json[0],weight = -1) #connect input wire to gate
            CircuitGraph.add_edge(cell_json[1]["connections"]["B"][0],cell_json[0],weight = -1) #connect input wire to gate
            CircuitGraph.add_edge(cell_json[0],cell_json[1]["connections"]["Y"][0],weight = 0) #connect gate to output wire
            wire_set.add(cell_json[1]["connections"]["Y"][0])

wire_array = list(wire_set - set(output_array)) #To map wires to c++ array, give an order to wires.

#print(list(nx.DiGraph.predecessors(CircuitGraph,"$abc$49$auto$blifparse.cc:371:parse_blif$50")))
#nx.draw(CircuitGraph,labels=gate_type)
#plt.show()

total_step = -nx.algorithms.shortest_paths.weighted.bellman_ford_path_length(CircuitGraph,"In","Out") #Knowing Maximal stage may be simplify algorithm.
#print(total_step)

#Initialize
gate_array = [[] for i in range(total_step)] #This array records which gates will be evaluated in each stage.
wire_generate_dict = {i:total_step-2 for i in wire_array}
wire_delete_dict = {i:0 for i in wire_array}

for gate in dict(nx.algorithms.shortest_paths.weighted.single_source_bellman_ford_path_length(CircuitGraph,"In")).items(): #Analyzing gates' stage.
    if type(gate[0]) is str and gate[0] != "In" and gate[0] != "Out":
        stage = -gate[1]-1
        gate_array[stage].append(gate[0])
        out_wire = list(CircuitGraph.successors(gate[0]))[0]
        if not(out_wire in output_array):
            wire_generate_dict[out_wire] = min(stage,wire_generate_dict[out_wire]) #When is the wire's first use.
        input_wires = list(CircuitGraph.predecessors(gate[0]))
        for input_wire in input_wires:
            if not(input_wire in input_array) and not(input_wire in output_array):
                wire_delete_dict[input_wire] = max(wire_delete_dict[input_wire],stage) #When is the wire's last use

wire_generate_array = [[] for i in range(total_step-1)] #Hold when wires should be generated
wire_delete_array = [[] for i in range(total_step)] #Hold when wires should be deleted

for i in wire_array:
    wire_generate_array[wire_generate_dict[i]].append(i)
    wire_delete_array[wire_delete_dict[i]].append(i)

#print(input_array)
#print(output_array)
#print(wire_array)
#print(gate_array)
#print(gate_type)

gate_template_array = [[] for i in range(total_step)]  #This array record output string for c++ code template.
current_wire = []

#record output strings based on previous analyzing. Currentry,parallelization is implemented by openMP per stage.
for i in range(total_step):
    gate_stage = gate_array[i]

    if i != total_step-1:
        for gen_wire in wire_generate_array[i]:
            if -1 in current_wire:
                current_wire[current_wire.index(-1)] = gen_wire #If there are empty space which is freed by deleting, use it for memory efficiency.
            else:
                current_wire.append(gen_wire) #If wires array are full, add new space.

    for gate in gate_stage:
        result = ""
        ca = ""
        cb = ""
        cc = ""

        wire = module_netlist["cells"][gate]["connections"]["Y"][0]
        if wire in output_array:
            result = "cipherout[" + str(output_array.index(wire)) + "]"
        else :
            result = "cipherwire["+ str(current_wire.index(wire)) + "]"

        #MUX's wires' notations are not same between Yosys and TFHE.
        if gate_type[gate] == "MUX":
            wire = module_netlist["cells"][gate]["connections"]["S"][0]
        else:
            wire = module_netlist["cells"][gate]["connections"]["A"][0]
        if wire in input_array:
            ca = "cipherin[" + str(input_array.index(wire)) + "]"
        elif wire in output_array:
            ca = "cipherout[" + str(output_array.index(wire)) + "]"
        else :
            ca = "cipherwire[" + str(current_wire.index(wire)) + "]"
        if gate_type[gate] != "NOT":
            wire = module_netlist["cells"][gate]["connections"]["B"][0]
            if wire in input_array:
                cb = "&cipherin["  + str(input_array.index(wire)) +"],"
            elif wire in output_array:
                cb = "&cipherout[" + str(output_array.index(wire)) + "],"
            else :
                cb = "&cipherwire[" + str(current_wire.index(wire)) + "],"
        
            if gate_type[gate] == "MUX":
                wire = module_netlist["cells"][gate]["connections"]["A"][0]
                if wire in input_array:
                    cc = "&cipherin["  + str(input_array.index(wire)) +"],"
                elif wire in output_array:
                    cc = "&cipherout[" + str(output_array.index(wire)) + "],"
                else :
                    cc = "&cipherwire[" + str(current_wire.index(wire)) + "],"

        gate_template_array[i].append([gate_type[gate],result,ca,cb,cc])
    for delete_wire in wire_delete_array[i]:
        current_wire[current_wire.index(delete_wire)] = -1 #deleted wires are marked as deleted

DFF_template_array=[]
for DFF in DFF_array:
    DFF_template_array.append([input_array.index(DFF[0]),output_array.index(DFF[1])])

#print(template_array)
#print(len(current_wire))

data ={"input_width":len(input_array), "output_width":len(output_array), "wire_max":len(current_wire), "gate_template_array":gate_template_array,"DFF_array":DFF_template_array,"number_of_DFF":len(DFF_template_array)} #Map recorded arrays to template's input.
cloud_template_result = Environment(loader=FileSystemLoader('.')).get_template("cloud.cpp.template").render(data) #Load template
#print(str(cloud_template_result))
with open(dirname(sys.argv[1])+"/cloud.cpp","w") as f:
    f.write(cloud_template_result) #generate c++ code