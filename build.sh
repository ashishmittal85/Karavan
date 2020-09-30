#!/bin/bash


# Make appropriate directories
mkdir `pwd`/bin
mkdir `pwd`/lib
export LD_LIBRARY_PATH=`pwd`/lib:$LD_LIBRARY_PATH
export PATH=`pwd`/bin:$PATH

# Clone submodules
git submodule update --init

# Cmake
cmake .
make
make install
