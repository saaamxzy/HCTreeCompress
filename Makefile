# A simple makefile for CSE 100 PA2

CC=g++
CXXFLAGS=-std=c++11 -g -gdwarf-2
LDFLAGS=-g

all: compress uncompress

compress:  HCNode.o BitInputStream.o BitOutputStream.o HCTree.o

uncompress:  HCNode.o BitInputStream.o BitOutputStream.o HCTree.o

HCTree.o:  HCNode.hpp BitOutputStream.hpp BitInputStream.hpp HCTree.hpp 

HCNode.o: HCNode.hpp

BitInputStream.o: BitInputStream.hpp

BitOutputStream.o: BitOutputStream.hpp

clean:
	rm -f compress uncompress *.o core*
