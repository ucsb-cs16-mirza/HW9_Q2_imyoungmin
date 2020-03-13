CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=linkedListTest

all: ${BINARIES}

tests: ${BINARIES}
	./linkedListTest

linkedListTest: linkedListTest.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
