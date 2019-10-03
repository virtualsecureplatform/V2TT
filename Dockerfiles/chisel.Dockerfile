FROM alpine

LABEL maintainer="nindanaoto <dirty.knife603@gmail.com>"

RUN apk add --no-cache -X http://dl-cdn.alpinelinux.org/alpine/edge/testing sbt nss && apk --no-cache add sed && mkdir -p /build/src/main/scala

COPY dummy/build.sbt /build

COPY dummy/Adder32bit.scala /build/src/main/scala

WORKDIR /build

RUN sbt run 

RUN rm -r /build/src