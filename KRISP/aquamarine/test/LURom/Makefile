circuit:
	docker run --rm -v ${shell pwd}/../../rv16k-aquamarine:/build chisel-tfhe /bin/sh -c "cd /build && sed -i -e 's/new .*)/new LURom)/g' ./src/main/scala/Main.scala && sbt run && rm *.anno *.fir"
	docker run --rm -v /tmp/.X11-unix/:/tmp/.X11-unix -v ${shell pwd}/../../:/build yosys:0.9 /bin/sh -c "cd /build/rv16k-aquamarine && yosys ../test/LURom/build.ys && mv *.json ../"

V2TT:
	docker run --rm -v $(shell pwd)/../../../../src:/src -v $(shell pwd)/../../:/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 V2TT.py /build/MemUnit.json && mv /build/cloud.cpp /build/test/IfUnit/"
	docker run --rm -v $(shell pwd)/../../../../src:/src -v $(shell pwd)/../../:/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 PortOnlyGen.py /build/MemUnit.json && mv /build/client.cpp /build/test/MemUnit/ && mv /build/verify.cpp /build/test/MemUnit/"

tfhe: cloud.cpp
	docker run -it --rm -v  $(shell pwd):/build chisel-tfhe /bin/sh -c "cd /build && clang++ -O3 -ltfhe-fftw -fopenmp -o cloud cloud.cpp && clang++ -ltfhe-fftw client.cpp -o client && clang++ -ltfhe-fftw -o verify verify.cpp && sbt test"

.PHONY: clean
clean :
	sudo rm */*.v */*.fir */*.ann