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
gate_type["In"] = "In"
CircuitGraph.add_node("Out")
gate_type["Out"] = "Out"

json_netlist = json.load(open(sys.argv[1], 'r'))["modules"]

for module_netlist in json_netlist.values():
    for port_json in module_netlist["ports"].values():
        gate_type[port_json["bits"][0]] = port_json["bits"][0]
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
        CircuitGraph.add_node(cell_json[0],type = cell_json[1]["type"][2:],input = [])
        print(CircuitGraph[cell_json[0]])
        CircuitGraph[cell_json[0]]["input"] = []
        print(CircuitGraph[cell_json[0]])
        gate_type[cell_json[0]] = cell_json[1]["type"][2:]

        loop = 0
        for direction_json in cell_json[1]["port_directions"].items():
            if direction_json[1] == "input":
                CircuitGraph.add_edge(cell_json[1]["connections"][direction_json[0]][0],cell_json[0],weight = -1)
                CircuitGraph[cell_json[0]]["input"].append(cell_json[1]["connections"][direction_json[0]][0])
            elif direction_json[1] == "output":
                CircuitGraph.add_edge(cell_json[0],cell_json[1]["connections"][direction_json[0]][0],type = "wire",weight = 0)
                CircuitGraph[cell_json[0]]["output"] = cell_json[1]["connections"][direction_json[0]][0]

            else:
                print("Cell Port Definition Error")
                sys.exit(1)

#print(list(nx.DiGraph.predecessors(CircuitGraph,"$abc$49$auto$blifparse.cc:371:parse_blif$50")))
#nx.draw(CircuitGraph,labels=gate_type)
#plt.show()

total_step = -nx.algorithms.shortest_paths.weighted.bellman_ford_path_length(CircuitGraph,"In","Out")
wire_array = [[] for i in range(total_step)]
gate_array = [[] for i in range(total_step)]

for stage in dict(nx.algorithms.shortest_paths.weighted.single_source_bellman_ford_path_length(CircuitGraph,"In")).items():
    #print(stage)
    typekey = CircuitGraph[stage[0]].get("type")
    if typekey != None and typekey != "input" and typekey != "output":
        if typekey == "wire":
            wire_array[-stage[1]-1].append(stage[0])
        else:
            gate_array[-stage[1]-1].append([stage[0],typekey,CircuitGraph[stage[0]]["input"],CircuitGraph[stage[0]]["output"]])

print(input_array)
print(output_array)
print(gate_array)