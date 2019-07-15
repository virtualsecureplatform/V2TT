all: client.cpp verify.cpp cloud.cpp
	clang++ -ltfhe-fftw client.cpp -o client
	clang++ -ltfhe-fftw cloud.cpp -o cloud
	clang++ -ltfhe-fftw verify.cpp -o verify
	./client
	./cloud
	./verify

.PHONY: clean
clean :
	rm cloud.cpp client cloud verify *.key *.data