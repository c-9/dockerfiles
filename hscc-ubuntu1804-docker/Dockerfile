FROM chunk-legion:5000/ubuntu:18.04
MAINTAINER Chunk (chunk@telos.top)

COPY .bashrc /root/.bashrc
COPY .aliasrc /root/.aliasrc 
RUN apt-get update || true
RUN apt-get install -y vim git wget lsb-release gnupg2 software-properties-common ssh
# RUN resolvectl flush-caches
# RUN git config --global http.proxy "" && git config --global http.sslVerify false
# RUN git clone https://github.com/c-9/hscc.git
COPY hscc /hscc
WORKDIR /hscc
RUN sh zsim-nvmain/setup.sh
RUN sh zsim-nvmain/compile.sh || true
