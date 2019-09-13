all: client.cpp verify.cpp build.sbt 
	docker run --rm -v ${shell pwd}:/build chisel /bin/sh -c "cd /build && sbt run && mv *.v src"
	mv src/*.v .
	docker run --rm -v /tmp/.X11-unix/:/tmp/.X11-unix -v ${shell pwd}:/build yosys:0.8 /bin/sh -c "cd /build && yosys build.ys && rm circuit.dot"
	xdg-open circuit.svg
	docker run --rm -v $(shell pwd)/../../src:/src -v $(shell pwd):/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 V2TT.py /build/circuit.json"
	docker run -it --rm -v  $(shell pwd):/build tfhe-ubuntu /bin/sh -c "cd /build && clang++ -ltfhe-fftw -fopenmp -o cloud cloud.cpp && clang++ -ltfhe-fftw client.cpp -o client && clang++ -ltfhe-fftw -o verify verify.cpp && ./client && ./cloud && ./verify"

circuit:
	docker run --rm -v ${shell pwd}:/build aquamarine-chisel /bin/sh -c "cd /build && sbt run"
	docker run --rm -v /tmp/.X11-unix/:/tmp/.X11-unix -v ${shell pwd}:/build yosys:0.9 /bin/sh -c "cd /build && yosys build.ys && rm circuit.dot"
	xdg-open circuit.svg

V2TT:
	docker run --rm -v $(shell pwd)/../../src:/src -v $(shell pwd):/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 V2TT.py /build/circuit.json"

tfhe: cloud.cpp
	docker run -it --rm -v  $(shell pwd):/build tfhe-ubuntu /bin/sh -c "cd /build && clang++ -ltfhe-fftw -fopenmp -o cloud cloud.cpp && clang++ -ltfhe-fftw client.cpp -o client && clang++ -ltfhe-fftw -o verify verify.cpp && ./client && ./cloud && ./verify"
#if you want to run binary in local, you have to install tfhe and musl.

.PHONY: clean
clean :
	sudo rm cloud.cpp client cloud verify *.key *.data *.svg *.json *.v
