circuit:
	docker run --rm -v ${shell pwd}/rv16k-aquamarine:/build chisel-tfhe /bin/sh -c "cd /build && sed -i -e 's/new .*)/new TopUnit)/g' ./src/main/scala/Main.scala && sbt run && rm *.anno *.fir"
	docker run --rm -v /tmp/.X11-unix/:/tmp/.X11-unix -v ${shell pwd}:/build yosys:0.9 /bin/sh -c "cd /build/rv16k-aquamarine && yosys ../build.ys && mv *.json ../"

V2TT:
	docker run --rm -v $(shell pwd)/../../src:/src -v $(shell pwd):/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 V2TT.py /build/circuit.json && python3 PortOnlyGen.py /build/circuit.json"

tfhe: cloud.cpp
	docker run -it --rm -v  $(shell pwd):/build chisel-tfhe /bin/sh -c "cd /build && clang++ -O3 -ltfhe-spqlios-fma -fopenmp -o cloud cloud.cpp && clang++ -ltfhe-spqlios-fma client_edited.cpp elf_parser.c -o client && clang++ -ltfhe-spqlios-fma -o verify verify.cpp && ./client fib.exe && ./cloud 1000 && ./verify"

run: client cloud verify
	docker run -it --rm -v  $(shell pwd):/build chisel-tfhe /bin/sh -c "cd /build && ./client fib.exe && ./cloud 1000 && ./verify"

.PHONY: clean
clean :
	sudo rm */*.v */*.fir */*.anno *.key *.data client cloud verify *.svg
