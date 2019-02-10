#! /bin/bash

if [ "$1" = "--generate" ]
then
    rm -rf ./build/
    mkdir build
    cd build
    cmake ..
elif [ "$1" = "--install" ]
then
    cd build
    make install
elif [ "$1" = "--make" ]
then
    cd build
    make -j8
    cp -R ../test/test-media/ ./test-media
elif [ "$1" = "--test" ]
then
    cd build
    ./SDLOL-test
else
    echo "-c to compile, -i to install, -m to run makefiles"
fi
