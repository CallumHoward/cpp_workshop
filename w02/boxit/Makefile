# standard flags
CXX=clang++
CPPFLAGS=-Wall -Wextra -pedantic -std=c++14
LDFLAGS=

# files
SOURCES=boxit.cpp testBoxit.cpp Box.cpp
OBJS=$(patsubst %.cpp, bin/%.o, $(wildcard *.cpp))
BIN=bin/main
TEST_FILES=$(patsubst test/%.in, bin/test/%.seen, $(wildcard test/*.in))

# build type
RELEASE_FLAGS=-O2
DEBUG_FLAGS=-g -O0
DEBUG_MEMORY_FLAGS=-fsanitize=address -fno-omit-frame-pointer
DEBUG_ADDRESS_FLAGS=-fsanitize=memory -fPIE -pie -fno-omit-frame-pointer
ifndef BUILD_TYPE
	BUILD_TYPE=Release
endif
ifeq ($(BUILD_TYPE),Debug)
	BUILD_TYPE_FLAGS=$(DEBUG_FLAGS)
else
	BUILD_TYPE_FLAGS=$(RELEASE_FLAGS)
endif

# coverage
TEST_ARGS=< test/test01.in > bin/test/test01.seen
GCOVR_FLAGS=-fprofile-arcs -ftest-coverage -fPIC
LLVM_PATH=/usr/local/opt/llvm/bin
LLVM_COV_COMPILE_FLAGS=-fprofile-instr-generate -fcoverage-mapping
LLVM_COV_FLAGS=-format=html -Xdemangler c++filt -Xdemangler -n

# set command for opening directories and html coverage files
UNAME_S:=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
	OPEN=xdg-open
endif
ifeq ($(UNAME_S),Darwin)
	OPEN=open
endif

# these commands perform actions rather than produce a compiled file
.PHONY: all clean run_test test_coverage

# make bin dir
$(shell mkdir -p bin bin/test)

# build target rules
all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(RELEBUILD_TYPE_FLAGS) -o $(BIN) $(OBJS)

bin/%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(BUILD_TYPE_FLAGS) -o $@ -c $<

# test target rules
test: $(TEST_FILES) bin/testMemory bin/testAddress

run_test: test bin/test/%.seen test_coverage
	./bin/testMemory $(TEST_ARGS)
	./bin/testAddress $(TEST_ARGS)

bin/test/%.seen: test/%.in test/%.out ./$(BIN)
	@echo "=== testing: $* ==="
	./$(BIN) < test/$*.in > test/$*.seen
	diff test/$*.out test/$*.seen
	@echo "======================="

bin/testMemory: $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(DEBUG_FLAGS) $(DEBUG_MEMORY_FLAGS) -o $@ $(OBJS)

bin/testAddress: $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(DEBUG_FLAGS) $(DEBUG_MEMORY_FLAGS) -o $@ $(OBJS)

# coverage target rules
bin/coverage/gcovr/testCoverage.html: $(OBJS)
	# gcovr operates on profile data from binaries compiled with GNU Compiler (g++)
	mkdir -p `dirname $@`
	g++ $(CPPFLAGS) $(LDFLAGS) $(DEBUG_FLAGS) $(GCOVR_FLAGS) -o $@ $(OBJS)
	./$@ $(TEST_ARGS)
	gcovr -r . --html --html-details -o $@.html

bin/coverage/llvm-cov/testCoverage.html: $(OBJS)
	# llvm-cov operates on profile data generated from binaries compiled with clang
	# http://clang.llvm.org/docs/SourceBasedCodeCoverage.html
	mkdir -p `dirname $@`
	clang++ $(LLVM_COV_COMPILE_FLAGS) -o $@ $(OBJS)
	LLVM_PROFILE_FILE="$@.profraw" ./$@ $(TEST_ARGS)
	$(LLVM_PATH)/llvm-profdata merge -sparse $@.profraw -o $@.profdata
	$(LLVM_PATH)/llvm-cov show $@ -instr-profile=$@.profdata $(LLVM_COV_FLAGS) > $@.html

test_coverage: test_coverage_gcovr test_coverage_llvm-cov

test_coverage_%: bin/coverage/%/testCoverage.html
	$(OPEN) $<

clean:
	$(RM) -r *.dSYM bin/*.dSYM bin/coverage bin/test
	$(RM) a.out *.gch *.gcno *.gcda *.o bin/*
	$(RM) $(subst .cpp,,$(SOURCES))
