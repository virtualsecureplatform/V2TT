FROM alpine

LABEL maintainer="nindanaoto <dirty.knife603@gmail.com>"

RUN apk add --no-cache -X http://dl-cdn.alpinelinux.org/alpine/edge/testing sbt nss

COPY Adder32bit /tmp

WORKDIR /tmp

RUN sbt run