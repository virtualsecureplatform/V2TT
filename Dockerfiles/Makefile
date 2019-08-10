docker: chisel.Dockerfile networkx-ninja2-python3.Dockerfile tfhe-gcc.Dockerfile yosys.Dockerfile
	docker build -t chisel:latest -f chisel.Dockerfile .
	docker build -t yosys:0.8 -f yosys.Dockerfile .
	docker build -t networkx-ninja2-python3:latest -f networkx-ninja2-python3.Dockerfile .
	docker build -t tfhe-ubuntu:latest -f tfhe-ubuntu.Dockerfile .
