circuit:
	docker run --rm -v ${shell pwd}/../../rv16k-aquamarine:/build aquamarine-chisel /bin/sh -c "cd /build && sbt run && rm *.anno *.fir"
	docker run --rm -v /tmp/.X11-unix/:/tmp/.X11-unix -v ${shell pwd}/../../:/build yosys:0.9 /bin/sh -c "cd /build/rv16k-aquamarine && yosys ../test/ExUnit/build.ys && mv *.json ../"

V2TT:
	docker run --rm -v $(shell pwd)/../../src:/src -v $(shell pwd):/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 V2TT.py /build/circuit.json"

docker-aquamarine:
	 docker build -t aquamarine-chisel:latest -f aquamarine-chisel.Dockerfile .

.PHONY: clean
clean :
	sudo rm */*.v */*.fir */*.anno
