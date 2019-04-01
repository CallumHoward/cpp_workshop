.PHONY: all process clean

all: clean process

process: hello.i

hello.i: hello.cpp hello.hpp
	g++ -Wall -Wextra -pedantic -std=c++1z -g -E hello.cpp | uniq | grep -v '^#' > hello.i

clean:
	rm -f hello.i

