all: ASCR.so test test-dyn

CC = clang
CFLAGS = -emit-llvm -O0
CXX = g++
CXXFLAGS = -rdynamic $(shell llvm-config --cxxflags) -g -O0 -ggdb

test: fib.o ASCR.so
	opt -load ./ASCR.so -ascr -std-compile-opts $< -o fib && llvm-dis fib
	clang -g fib.ll -o fibASCR
	clang -g -O2 fib.c -o fibO2
	rm fib

test-dyn: fib.o ASCR-dyn.so
	opt -load ./ASCR-dyn.so -ascr-dyn -std-compile-opts $< -o fib && llvm-dis fib
	clang -g fib.ll -o fibASCRD
	clang -g -O2 fib.c -o fibO2
	rm fib

%.so: %.o
	$(CXX) -shared $^ -o $@

clean:
	rm -f *.o *~ *.so *.ll fibO2 fibASCR fibASCRD
