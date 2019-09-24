circuit:
	docker run --rm -v ${shell pwd}/../../rv16k-aquamarine:/build chisel-tfhe /bin/sh -c "cd /build &&  sed -i -e 's/new .*)/new ExUnit)/g' ./src/main/scala/Main.scala && sbt run && rm *.anno *.fir"
	docker run --rm -v /tmp/.X11-unix/:/tmp/.X11-unix -v ${shell pwd}/../../:/build yosys:0.9 /bin/sh -c "cd /build/rv16k-aquamarine && yosys ../test/ExUnit/build.ys && mv *.json ../"

V2TT:
	docker run --rm -v $(shell pwd)/../../../../src:/src -v $(shell pwd)/../../:/build networkx-ninja2-python3 /bin/sh -c "cd /src && python3 V2TT.py /build/ExUnit.json && mv /build/cloud.cpp /build/test/ExUnit/"

tfhe: cloud.cpp
	docker run -it --rm -v  $(shell pwd):/build chisel-tfhe /bin/sh -c "cd /build && clang++ -O3 -ltfhe-fftw -fopenmp -o cloud cloud.cpp && clang++ -ltfhe-fftw client.cpp -o client && clang++ -ltfhe-fftw -o verify verify.cpp && sbt test"

docker-aquamarine:
	 docker build -t aquamarine-chisel:latest -f aquamarine-chisel.Dockerfile .

.PHONY: clean
clean :
	sudo rm */*.v */*.fir */*.ann