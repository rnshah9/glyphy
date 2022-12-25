FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y automake autoconf libtool pkg-config libfreetype-dev build-essential clang

COPY . /repo
WORKDIR /repo
RUN ./autogen.sh
RUN ./configure --prefix=/install
RUN make -j8
RUN make install
RUN clang++ /repo/mayhem/fuzz_contains_in_span.cpp -fsanitize=fuzzer,address -I /repo/src/ -o /fuzz

FROM ubuntu:22.04 as package
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libfreetype-dev
COPY --from=builder /install /install
COPY --from=builder /repo/demo/.libs/glyphy-validate /
COPY --from=builder /fuzz /fuzz_contains_in_span
