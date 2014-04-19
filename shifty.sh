#!/bin/bash
set -e
#cabal build
rm ./copilot-c99-codegen -rf
./dist/build/shifty/shifty
cp ./copilot-c99-codegen/copilot.c copilot.cpp
cp ./copilot-c99-codegen/copilot.h copilot.h
make upload
