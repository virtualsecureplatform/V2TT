FROM alpine

LABEL maintainer="nindanaoto <dirty.knife603@gmail.com>"

RUN apk add --no-cache git python3

RUN git clone https://github.com/networkx/networkx.git

WORKDIR networkx

RUN pip3 install -e .

RUN pip3 install ninja2