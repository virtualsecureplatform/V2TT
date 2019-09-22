import pickle
import json
import sys
from os.path import dirname
from jinja2 import Template, Environment, FileSystemLoader #jinja2 is used to prduce c++ source code

input_offset = 2
output_offset = 0
input_template_array = []
output_template_array = []

for module_netlist in json.load(open(sys.argv[1], 'r'))["modules"].values():
    for name,port in module_netlist["ports"].items():
        if port["direction"] == "input":
            if name == "clock" or name == "reset":
                continue
            input_template_array.append([name,len(port["bits"]),input_offset])
            input_offset +=  len(port["bits"])

        elif port["direction"] == "output":
            output_template_array.append([name,len(port["bits"]),output_offset])
            output_offset +=  len(port["bits"])
        else:
            print("Port Definition Error") # For Debug.
            sys.exit(1)

with open('bitwidth.pickle', mode='rb') as f:
    bitwidth = pickle.load(f)

data ={"input_width":bitwidth["input_bit_width"], "input_ports":input_template_array, "number_of_ports":input_offset}
client_template_result = Environment(loader=FileSystemLoader('.')).get_template("PortOnlyClient.cpp.template").render(data) #Load template
#print(str(cloud_template_result))
with open(dirname(sys.argv[1])+"/client.cpp","w") as f:
    f.write(client_template_result) #generate c++ code

data ={"output_bit_width":bitwidth["output_bit_width"], "output_ports":output_template_array}
verify_template_result = Environment(loader=FileSystemLoader('.')).get_template("PortOnlyVerify.cpp.template").render(data) #Load template
with open(dirname(sys.argv[1])+"/verify.cpp","w") as f:
    f.write(verify_template_result) #generate c++ code