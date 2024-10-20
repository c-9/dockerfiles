#!/bin/bash
apt-get install -y build-essential g++-4.8 scons automake autoconf m4 perl flex bison byacc
apt-get install -y libconfig-dev libconfig++-dev libhdf5-dev libelf-dev libxerces-c-dev
apt-get install -y libboost-all-dev libbz2-dev zlib1g-dev libc6-dev libicu-dev
apt-get install -y python3 python3-pip
apt-get install -y libgoogle-glog-dev
pip3 install scons==4.0.0
ln -s /usr/include/asm-generic /usr/include/asm
