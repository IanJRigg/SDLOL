#! /bin/bash

if [ "$1" = "-d" ]
then
    rm -rf ./build/
    rm ./lib/*
elif [ "$1" = "-c" ]
then
    mkdir build
    cd build
    cmake ..
    make -j8
    make install
elif [ "$1" = "-h" ]
then
    echo "-d to clean the directories. -c to compile"
else
    echo "-d to clean the directories. -c to compile"
fi
