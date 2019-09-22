OBJECTS = main.cpp CrimeRecord.cpp StaticHash.cpp
STD = -std=c++17
MYFLAGS = -g -Wall 
CXX = g++
EXEC = main

all: $(OBJECTS)
	$(CXX) $(STD) $(MYFLAGS) $(OBJECTS) -o $(EXEC)

clean: 
	rm $(EXEC)

