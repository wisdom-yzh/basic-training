CC=g++
SOURCES=$(wildcard *.cc)
PROGS=$(patsubst %.cc, %, $(SOURCES))

all: BIN $(PROGS)

BIN:
	mkdir -p bin

$(PROGS): %: %.cc
	$(CC) $^ -std=c++11 -o bin/$@

.PHONY: clean

clean:
	rm -r bin
