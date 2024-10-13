FROM debian:stretch
MAINTAINER Siddharth Sahay (siddharthsahay9700@gmail.com)

COPY .bashrc /root/.bashrc
COPY .aliasrc /root/.aliasrc 
RUN sed -i 's/deb.debian.org/archive.debian.org/g' /etc/apt/sources.list
RUN sed -i 's/security.debian.org/archive.debian.org/g' /etc/apt/sources.list
RUN sed -i 's/stretch-updates/stretch/g' /etc/apt/sources.list
RUN apt-get update || true
RUN apt-get install -y vim git make g++ wget lsb-release gnupg2 software-properties-common libboost-all-dev
RUN git clone --recurse-submodules https://github.com/CMU-SAFARI/ramulator-pim.git
WORKDIR /ramulator-pim
RUN cd zsim-ramulator && sh setup.sh && sh compile.sh
RUN sh compileramulator.sh
