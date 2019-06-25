#!/bin/python3
import networkx as nx
import json
import sys

CircuitGraph = nx.DiGraph()
CircuitGraph.add_node("In")
CircuitGraph.add_node("Out")

json_netlist = json.load(open(sys.argv[1], 'r'))["modules"]

for module_netlist in json_netlist.values():
    for port_json in module_netlist["ports"].values():
        if port_json["direction"] == "input":
            CircuitGraph.add_edge("In",port_json["bits"][0],weight = 0)
        elif port_json["direction"] == "output":
            CircuitGraph.add_edge(port_json["bits"][0],"Out",weight = 0)
        else:
            print("Port Definition Error")
            sys.exit(1)

    for cell_json in module_netlist["cells"].items():
        CircuitGraph.add_node(cell_json[0],tyep = cell_json[1]["type"][2:])

        for direction_json in cell_json[1]["port_directions"].items():
            if direction_json[1] == "input":
                CircuitGraph.add_edge(cell_json[1]["connections"][direction_json[0]][0],cell_json[0],weight = -1)
            elif direction_json[1] == "output":
                CircuitGraph.add_edge(cell_json[0],cell_json[1]["connections"][direction_json[0]][0],weight = -1)
            else:
                print("Cell Port Definition Error")
                sys.exit(1)

nx.nx_agraph.view_pygraphviz(CircuitGraph, prog='fdp') 