all: client.cpp verify.cpp cloud.cpp
	clang++ -ltfhe-fftw client.cpp -o client
	clang++ -ltfhe-fftw cloud.cpp -o cloud
	clang++ -ltfhe-fftw verify.cpp -o verify
	./client
	./cloud
	./verify

chisel: build.sbt
	#docker run -v $(PWD):/build hseeberger/scala-sbt:8u212_1.2.8_2.13.0 /bin/bash -c "cd /build && sbt run"
	sbt run

yosys:
	docker run -v $(PWD):/build yosys:0.8 /bin/sh -c "cd /build && yosys build.ys"

tfhe: cloud.cpp
	docker run -v $(PWD):/build hseeberger/scala-sbt:8u212_1.2.8_2.12.8 /bin/sh -c "cd /build && g++ -ltfhe-nayuki-avx cloud.cpp"

V2TT: 
	docker run -v $PWD/../../src:/src -v $(PWD):/build networkx-ninja2-python3 /bin/sh -c "cd /build && python3 V2TT.py /build/circuit.json"

.PHONY: clean
clean :
	rm cloud.cpp client cloud verify *.key *.data
