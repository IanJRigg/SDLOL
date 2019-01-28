#! /bin/bash

if [ "$1" = "-c" ]
then
    rm -rf ./build/
    mkdir build
    cd build
    cmake ..
    make -j8
    cp -R ../test/test-media/ ./test-media
elif [ "$1" = "-m" ]
then
    cd build
    make -j8
    cp -R ../test/test-media/ ./test-media
elif [ "$1" = "-i" ]
then
    cd build
    make install
elif [ "$1" = "-t" ]
then
    cd build
    ./SDLOL-test
else
    echo "-c to compile, -i to install, -m to run makefiles"
fi
