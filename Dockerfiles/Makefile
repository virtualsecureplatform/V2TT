all: networkx-ninja2-python3 chisel-tfhe yosys

yosys:
	docker build -t yosys:0.9 -f yosys.Dockerfile .

networkx-ninja2-python3:
	docker build -t networkx-ninja2-python3:latest -f networkx-ninja2-python3.Dockerfile .

chisel-tfhe:
	cd ../KRISP/aquamarine;docker build -t chisel-tfhe:latest -f ../../Dockerfiles/chisel-tfhe.Dockerfile .