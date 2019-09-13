circuit:
	docker run --rm -v ${shell pwd}/rv16k-aquamarine:/build amethyst-chisel /bin/sh -c "cd /build && sbt run"
	docker run --rm -v /tmp/.X11-unix/:/tmp/.X11-unix -v ${shell pwd}:/build yosys:0.9 /bin/sh -c "cd /build/rv16k-aquamarine && yosys ../build.ys"

V2TT:
	docker run --rm -v $(shell pwd)/../../src:/src -v $(shell pwd):/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 V2TT.py /build/rv16k-aquamarine/circuit.json"

docker-aquamarine:
	 docker build -t aquamarine-chisel:latest -f aquamarine-chisel.Dockerfile .

.PHONY: clean
clean :
	sudo rm */*.v */*.fir */*.anno
