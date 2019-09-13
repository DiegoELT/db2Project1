OBJECTS = main.cpp CrimeRecord.cpp CrimeRecord.h
STD = -std=c++17
MYFLAGS = -g -Wall
CXX = g++
EXEC = main

all: $(OBJECTS)
	$(CXX) $(STD) $(MYFLAGS) $(OBJECTS) -o $(EXEC)

clean: 
	rm $(EXEC)

