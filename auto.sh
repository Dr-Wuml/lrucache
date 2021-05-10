#/bin/sh
rm -rf lru.o
g++ lrucache.cpp main.cpp -o lru.o -std=c++11
