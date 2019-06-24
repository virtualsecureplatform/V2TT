#!/bin/python3
import networkx as nx
import json
import sys

CircuitGraph = nx.DiGraph()
CircuitGraph.add_node("In")
CircuitGraph.add_node("Out")

json_netlist = json.load(open(sys.argv[1], 'r'))
ports_netlist = json_netlist["modules"]["ports"]
for port_json in ports_netlist.values():
    if port_json["direction"] == "input":
        CircuitGraph.add_edge("In",port_json["bits"][0])
    if port_json["direction"] == "output":
        CircuitGraph.add_edge("Out",port_json["bits"][0])
    else:
        print("Port Definition Error")
        sys.exit(1)