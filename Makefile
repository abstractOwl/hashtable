# Makefile for CS130a PA1
PACKAGE	=	hashtable

all:
	g++ -std=c++0x src/*.cpp -o prog1

writeup:
	pandoc -o writeup.pdf writeup.md
