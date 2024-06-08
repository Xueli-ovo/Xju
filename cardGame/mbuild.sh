#!/bin/bash

read -p "请输入编译目标(Linux/Windows) > " PLATFORM

cmake -S . -B build -DTARGET_PLATFORM=$PLATFORM && cd build ; make
