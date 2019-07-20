all: client.cpp verify.cpp cloud.cpp
	clang++ -ltfhe-fftw client.cpp -o client
	clang++ -ltfhe-fftw cloud.cpp -o cloud
	clang++ -ltfhe-fftw verify.cpp -o verify
	./client
	./cloud
	./verify

chisel: build.sbt
	docker run --rm -v $(PWD):/build chisel /bin/sh -c "cd /build && sbt run && rm *.anno *.fir"

yosys:
	xhost local:
	docker run --rm -v /tmp/.X11-unix/:/tmp/.X11-unix -v $(PWD):/build yosys:0.8 /bin/sh -c "cd /build && yosys build.ys && rm circuit.dot"
	gpicview circuit.svg

tfhe: cloud.cpp
	docker run -it --rm -v  $(PWD):/build tfhe-gcc /bin/sh -c "cd /build && clang++ -ltfhe-fftw -o cloud cloud.cpp && clang++ -ltfhe-fftw client.cpp -o client && clang++ -ltfhe-fftw -o verify verify.cpp && ./client && ./cloud && ./verify"

V2TT: 
	docker run --rm -v $(PWD)/../../src:/src -v $(PWD):/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 V2TT.py /build/circuit.json"

.PHONY: clean
clean :
	sudo rm cloud.cpp client cloud verify *.key *.data *.svg *.json *.v