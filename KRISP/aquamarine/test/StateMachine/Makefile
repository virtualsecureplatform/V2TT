circuit:
	docker run --rm -v ${shell pwd}/../../rv16k-aquamarine:/build chisel-tfhe /bin/sh -c "cd /build && sed -i -e 's/new .*)/new StateMachine)/g' ./src/main/scala/Main.scala && sbt run && rm *.anno *.fir"
	docker run --rm -v /tmp/.X11-unix/:/tmp/.X11-unix -v ${shell pwd}/../../:/build yosys:0.9 /bin/sh -c "cd /build/rv16k-aquamarine && yosys ../test/StateMachine/build.ys && mv *.json ../ && mv *.svg ../"
	xdg-open ../../StateMachine.svg

V2TT:
	docker run --rm -v $(shell pwd)/../../../../src:/src -v $(shell pwd)/../../:/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 V2TT.py /build/StateMachine.json && mv /build/cloud.cpp /build/test/StateMachine/"
	docker run --rm -v $(shell pwd)/../../../../src:/src -v $(shell pwd)/../../:/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 PortOnlyGen.py /build/StateMachine.json && mv /build/client.cpp /build/test/StateMachine/ && mv /build/verify.cpp /build/test/StateMachine/"

tfhe: cloud.cpp
	docker run -it --rm -v  $(shell pwd):/build chisel-tfhe /bin/sh -c "cd /build && clang++ -O3 -ltfhe-spqlios-fma -fopenmp -o cloud cloud.cpp && clang++ -ltfhe-spqlios-fma client.cpp -o client && clang++ -ltfhe-spqlios-fma -o verify verify.cpp && ./client && ./cloud 4 && ./verify"

.PHONY: clean
clean :
	sudo rm */*.v */*.fir */*.ann