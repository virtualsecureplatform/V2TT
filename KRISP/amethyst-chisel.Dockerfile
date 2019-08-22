FROM alpine

LABEL maintainer="nindanaoto <dirty.knife603@gmail.com>"

RUN apk add --no-cache -X http://dl-cdn.alpinelinux.org/alpine/edge/testing sbt nss && mkdir -p /build/src/main/scala

COPY ./amethyst /build

WORKDIR /build

RUN sbt run 

RUN rm -r /build
