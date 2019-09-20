FROM ubuntu:19.04

LABEL maintainer="nindanaoto <dirty.knife603@gmail.com>"

ENV APT_KEY_DONT_WARN_ON_DANGEROUS_USAGE=1

RUN apt-get update && apt-get upgrade -y && apt-get install -y gnupg ca-certificates && echo "deb https://dl.bintray.com/sbt/debian /" | tee -a /etc/apt/sources.list.d/sbt.list && apt-key adv --no-tty --keyserver hkp://keyserver.ubuntu.com:80 --recv 2EE0EA64E40A89B84B2DF73499E82A75642AC823 && apt-get update && apt-get install -y sbt default-jre build-essential cmake libfftw3-dev clang libomp-dev git python3 python3-pip && git clone  --depth 1 https://github.com/tfhe/tfhe.git

WORKDIR tfhe/build

RUN sed -i '79c\    inline void add4(double * res, const double * a, const double * b) {' ../src/libtfhe/fft_processors/spqlios/spqlios-fft-impl.cpp && sed -i '83c\    inline void sub4(double * res, const double * a, const double * b) {' ../src/libtfhe/fft_processors/spqlios/spqlios-fft-impl.cpp && cmake ../src -DENABLE_FFTW=on -DENABLE_NAYUKI_PORTABLE=on -DENABLE_NAYUKI_AVX=on -DENABLE_SPQLIOS_AVX=on -DENABLE_SPQLIOS_FMA=on -DCMAKE_BUILD_TYPE=optim && make install

ENV LD_LIBRARY_PATH $LD_LIBRARY_PATH:/usr/local/lib

COPY ./rv16k-aquamarine /build

WORKDIR /build

RUN sbt run && pip3 install cupy-cuda101 && rm -r /build 