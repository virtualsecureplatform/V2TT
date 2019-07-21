FROM alpine

LABEL maintainer="nindanaoto <dirty.knife603@gmail.com>"

RUN apk add --no-cache make cmake fftw-dev git g++ clang libgomp

RUN git clone --depth 1 https://github.com/tfhe/tfhe.git

WORKDIR tfhe/build

RUN cmake ../src -DENABLE_FFTW=on -DENABLE_NAYUKI_PORTABLE=on -DENABLE_NAYUKI_AVX=on -DENABLE_SPQLIOS_AVX=off -DENABLE_SPQLIOS_FMA=off -DCMAKE_BUILD_TYPE=optim && make install