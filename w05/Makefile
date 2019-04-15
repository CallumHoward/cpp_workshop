all:
	g++ -Wall -Wextra -pedantic -std=c++14 -g -E preprocessor.cpp | uniq | grep -v '^#' > preprocessor.i
