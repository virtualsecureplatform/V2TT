FROM alpine

LABEL maintainer="nindanaoto <dirty.knife603@gmail.com>"

RUN apk add --no-cache make bison flex readline-dev gawk tcl-dev libffi-dev git graphviz pkgconfig python3 boost-dev clang g++ graphviz-dev

RUN git clone --depth=1 https://github.com/YosysHQ/yosys.git -b yosys-0.9

WORKDIR yosys

RUN make install -j4