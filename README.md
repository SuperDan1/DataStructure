[TOC]
# Introduction
This repository is a realization of basic data structure based on C++  

# Getting the Source
```bash
git clone git@github.com:SuperDan1/DataStructure.git
```

# Building
## Download Google Gtest and Build
```bash
cd tests
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cmake ..
make
sudo make install
```
## Build 
This project uses `cmake` to compile.

```bash
mkdir -p build && cd build
cmake ..
make -j
```
# Run
```bash
cd tests
./data-structure
```
# Performance——TODO