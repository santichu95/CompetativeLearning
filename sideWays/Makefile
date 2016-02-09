CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -Werror -pedantic
BIN=prog

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CSS) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)
