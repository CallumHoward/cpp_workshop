# standard flags
CXX=clang++
CPPFLAGS=-Wall -Wextra -pedantic -std=c++14
LDFLAGS=
RELEASE_FLAGS=-O2

# debug
DEBUG_FLAGS=-g -O0
DEBUG_MEMORY_FLAGS=-fsanitize=address -fno-omit-frame-pointer
DEBUG_ADDRESS_FLAGS=-fsanitize=memory -fPIE -pie -fno-omit-frame-pointer

# coverage
GCOVR_FLAGS=-fprofile-arcs -ftest-coverage -fPIC
LLVM_PATH=/usr/local/opt/llvm/bin
LLVM_COV_COMPILE_FLAGS=-fprofile-instr-generate -fcoverage-mapping
LLVM_COV_FLAGS=-format=html -Xdemangler c++filt -Xdemangler -n

# add source files to be compiled together here (one main function only)
SOURCES=hello.cpp

# set command for opening directories and html files
UNAME_S:=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
	OPEN=xdg-open
endif
ifeq ($(UNAME_S),Darwin)
	OPEN=open
endif

# these commands perform actions rather than produce a compiled file
.PHONY: clean run_test test_coverage

all: $(SOURCES)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(RELEASE_FLAGS) -o bin/main $(SOURCES)

bin/testMemory:
	mkdir -p `dirname $@`
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(DEBUG_FLAGS) $(DEBUG_MEMORY_FLAGS) -o $@ $(SOURCES)

bin/testAddress:
	mkdir -p `dirname $@`
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(DEBUG_FLAGS) $(DEBUG_MEMORY_FLAGS) -o $@ $(SOURCES)

bin/coverage/gcovr/testCoverage:
	mkdir -p `dirname $@`
	g++ $(CPPFLAGS) $(LDFLAGS) $(DEBUG_FLAGS) $(GCOVR_FLAGS) -o $@ $(SOURCES)
	./$@
	gcovr -r . --html --html-details -o $@.html

bin/coverage/llvm-cov/testCoverage:
	# http://clang.llvm.org/docs/SourceBasedCodeCoverage.html
	mkdir -p `dirname $@`
	clang++ $(LLVM_COV_COMPILE_FLAGS) -o $@ $(SOURCES)
	LLVM_PROFILE_FILE="$@.profraw" ./$@
	$(LLVM_PATH)/llvm-profdata merge -sparse $@.profraw -o $@.profdata
	$(LLVM_PATH)/llvm-cov show $@ -instr-profile=$@.profdata $(LLVM_COV_FLAGS) > $@.html

test_coverage: bin/coverage/gcovr/testCoverage bin/coverage/llvm-cov/testCoverage
	$(OPEN) bin/coverage/gcovr/testCoverage.html
	$(OPEN) bin/coverage/llvm-cov/testCoverage.html

test: bin/testMemory bin/testAddress test_coverage

run_test: test
	./bin/testMemory
	./bin/testAddress

clean:
	rm -rf a.out *.dSYM *.gcno *gcda *.o bin/* $(subst .cpp,,$(SOURCES))
