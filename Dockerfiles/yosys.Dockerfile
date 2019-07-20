FROM alpine

LABEL maintainer="nindanaoto <dirty.knife603@gmail.com>"

RUN apk add --no-cache make bison flex readline-dev gawk tcl-dev libffi-dev git graphviz pkgconfig python3 boost-dev clang g++

RUN git clone --depth=1 https://github.com/YosysHQ/yosys.git -b yosys-0.8

WORKDIR yosys

RUN make install

RUN apk add --no-cache graphviz-dev