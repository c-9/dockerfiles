FROM chunk-legion:5000/ubuntu:18.04
MAINTAINER Chunk (chunk@telos.top)

COPY .bashrc /root/.bashrc
COPY .aliasrc /root/.aliasrc 
RUN apt-get update || true
RUN apt-get install -y vim git make wget lsb-release gnupg2 software-properties-common locate
# RUN resolvectl flush-caches
RUN git config --global http.proxy "" && git config --global http.sslVerify false
RUN git clone https://github.com/c-9/hscc.git
WORKDIR /hscc
RUN sh setup.sh
RUN sh compile.sh || true
