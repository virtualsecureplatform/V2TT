all: client.cpp verify.cpp cloud.cpp
	clang++ -ltfhe-fftw client.cpp -o client
	clang++ -ltfhe-fftw cloud.cpp -o cloud
	clang++ -ltfhe-fftw verify.cpp -o verify
	./client
	./cloud
	./verify

chisel: build.sbt
	docker run -v $(PWD):/build chisel /bin/sh -c "cd /build && sbt run"

yosys:
	docker run -v $(PWD):/build yosys:0.8 /bin/sh -c "cd /build && yosys build.ys && rm *.anno *fir circuit.dot circuit.dot.pid"
	gpicview circuit.svg

tfhe: cloud.cpp
	docker run -it -v  $(PWD):/build tfhe-gcc /bin/sh -c "cd /build && clang++ -ltfhe-fftw -o cloud cloud.cpp && clang++ -ltfhe-fftw client.cpp -o client && clang++ -ltfhe-fftw -o verify verify.cpp && ./client && ./cloud && ./verify"

V2TT: 
	docker run -v $(PWD)/../../src:/src -v $(PWD):/build networkx-ninja2-python3 /bin/sh -c "cd /build && python3 V2TT.py /build/circuit.json"

.PHONY: clean
clean :
	sudo rm cloud.cpp client cloud verify *.key *.data