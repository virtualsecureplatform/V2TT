FROM ubuntu:19.04

LABEL maintainer="nindanaoto <dirty.knife603@gmail.com>"

RUN apt-get update && apt-get upgrade -y && apt install && apt-get install -y build-essential cmake libfftw3-dev clang libomp-dev git && git clone  --depth 1 https://github.com/tfhe/tfhe.git

WORKDIR tfhe/build

RUN cmake ../src -DENABLE_FFTW=on -DENABLE_NAYUKI_PORTABLE=on -DENABLE_NAYUKI_AVX=on -DENABLE_SPQLIOS_AVX=off -DENABLE_SPQLIOS_FMA=off -DCMAKE_BUILD_TYPE=optim && make install

ENV LD_LIBRARY_PATH $LD_LIBRARY_PATH:/usr/local/lib