#!/bin/python3
import networkx as nx
import json
import sys
import matplotlib.pyplot as plt

gate_type={}
input_array = []
output_array = []

CircuitGraph = nx.DiGraph()
CircuitGraph.add_node("In")
CircuitGraph.add_node("Out")

json_netlist = json.load(open(sys.argv[1], 'r'))["modules"]

for module_netlist in json_netlist.values():
    for port_json in module_netlist["ports"].values():
        if port_json["direction"] == "input":
            CircuitGraph.add_edge("In",port_json["bits"][0],weight = 0,type="input")
            input_array.append(port_json["bits"][0])
        elif port_json["direction"] == "output":
            CircuitGraph.add_edge(port_json["bits"][0],"Out",weight = 0,type="output")
            output_array.append(port_json["bits"][0])
        else:
            print("Port Definition Error")
            sys.exit(1)

    for cell_json in module_netlist["cells"].items():
        CircuitGraph.add_node(cell_json[0],type = cell_json[1]["type"][2:])
        gate_type[cell_json[0]] = cell_json[1]["type"][2:]

        for direction_json in cell_json[1]["port_directions"].items():
            if direction_json[1] == "input":
                CircuitGraph.add_edge(cell_json[1]["connections"][direction_json[0]][0],cell_json[0],weight = -1)
            elif direction_json[1] == "output":
                CircuitGraph.add_edge(cell_json[0],cell_json[1]["connections"][direction_json[0]][0],weight = 0)

            else:
                print("Cell Port Definition Error")
                sys.exit(1)

#print(list(nx.DiGraph.predecessors(CircuitGraph,"$abc$49$auto$blifparse.cc:371:parse_blif$50")))
#nx.draw(CircuitGraph,labels=gate_type)
#plt.show()

total_step = -nx.algorithms.shortest_paths.weighted.bellman_ford_path_length(CircuitGraph,"In","Out")
wire_array = [[] for i in range(total_step-1)]
gate_array = [[] for i in range(total_step)]

for stage in dict(nx.algorithms.shortest_paths.weighted.single_source_bellman_ford_path_length(CircuitGraph,"In")).items():
    #print(stage)
    if type(stage[0]) is str and stage[0] != "In" and stage[0] != "Out":
        gate_array[-stage[1]-1].append(stage[0])
        if -stage[1] != total_step:
            wire_array[-stage[1]-1].append(CircuitGraph[stage[0]].successors()[0])

#print(input_array)
#print(output_array)
#print(gate_array)
#print(gate_type)

template_array = [[] for i in range(total_step)]

for i in range(total_step):
    for gate_stage in gate_array:
        for gate in gate_stage:
            result = ""
            ca = ""
            cb = ""

            wire = list(CircuitGraph.successors(gate))[0]
            if wire in output_array:
                result = "cipherout[" + str(output_array.index(wire)) + "]"
            else :
                result = "cipherwireout["+ str(wire_array[i].index(wire)) + "]"
            
            wire = list(CircuitGraph.predecessors(gate))[0]
            if wire in input_array:
                ca = "cipherin[" + str(input_array.index(wire)) + "]"
            else :
                ca = "cipherwirein[" + str(wire_array[i-1].index(wire)) + "]"

            wire = list(CircuitGraph.predecessors(gate))[1]
            if wire in input_array:
                cb = "cipherin["  + str(input_array.index(wire)) +"]"
            else :
                cb = "cipherwirein[" + str(wire_array[i-1].index(wire)) + "]"

            template_array[i].append([gate_type[gate],result,ca,cb])

print(template_array)