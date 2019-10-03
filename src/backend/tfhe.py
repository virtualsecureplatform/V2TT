import networkx as nx
from jinja2 import Template, Environment, FileSystemLoader #jinja2 is used to prduce c++ source code

def Generate(json_netlist,CircuitGraph,input_array,wire_array,output_array,option):
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

    print("input_array")
    print(input_array)
    print("Length of input_array")
    print(len(input_array))
    print("output_array")
    print(output_array)
    print("Length of output_array")
    print(len(output_array))
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

    #Connect DFF's Q port and D port.
    DFF_template_array = []
    for DFF in DFF_array:
        DFF_template_array.append([input_array.index(DFF[0]),output_array.index(DFF[1])])

    #If input ports, including DFFs' D ports, are directly connected to outputs, above code do nothing. So, connecting is needed.
    direct_port_template_array = []
    for inport in input_array:
        if inport in output_array:
            direct_port_template_array.append([output_array.index(inport),input_array.index(inport)])
    
    #print(template_array)
    #print(len(current_wire))
    
    if option == "handmade" or option == "port"
        data ={"input_width":len(input_array), "output_width":len(output_array), "wire_max":len(current_wire), "gate_template_array":gate_template_array,"DFF_array":DFF_template_array,"number_of_DFF":len(DFF_template_array),"direct_port_pairs":direct_port_template_array} #Map recorded arrays to template's input.
        cloud_template_result = Environment(loader=FileSystemLoader('.')).get_template("cloud.cpp.template").render(data) #Load template
    #print(str(cloud_template_result))
    with open(dirname(sys.argv[1])+"/cloud.cpp","w") as f:
        f.write(cloud_template_result) #generate c++ code

    if option == "port":
        input_offset = 2
        output_offset = 0
        input_template_array = []
        output_template_array = []

        for module_netlist in json_netlist.values():
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

        data ={"input_width":len(input_array), "input_ports":input_template_array, "number_of_ports":input_offset}
        client_template_result = Environment(loader=FileSystemLoader('.')).get_template("PortOnlyClient.cpp.template").render(data) #Load template
        #print(str(cloud_template_result))
        with open(dirname(sys.argv[1])+"/client.cpp","w") as f:
            f.write(client_template_result) #generate c++ code

        data ={"output_bit_width":len(output_array), "output_ports":output_template_array}
        verify_template_result = Environment(loader=FileSystemLoader('.')).get_template("PortOnlyVerify.cpp.template").render(data) #Load template
        with open(dirname(sys.argv[1])+"/verify.cpp","w") as f:
            f.write(verify_template_result) #generate c++ code