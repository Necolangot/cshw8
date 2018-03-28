CC=gcc
CXX=g++
RM=rm -f

all : build archive
	
build : main.o game.o othello.o
	g++ -g -o game main.o game.o othello.o

main.o : main.cc game.h othello.h

othello.o : othello.h othello.cc

game.o : game.h game.cc

clean : 
	$(RM) game main.o game.o othello.o