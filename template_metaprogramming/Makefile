# define your compiler
#CC = g++-mp-9
# CC = g++-8
CC = g++
CCMPI = mpicxx
CCTBB = g++
DPCPP = dpcpp

# compilation flags
CCFLAGS = -std=c++17 -O0

# linker flags
LFLAGS = -L/export/home/cucui/Documents/UniHeidelberg/benchmark/build/src -lbenchmark -lpthread

all: cppcon2014_p1 \
	OOP


cppcon2014_p1: cppcon2014_p1.cpp Makefile
	$(CC) $(CCFLAGS) -o $@ $< $(LFLAGS)
OOP: OOP.cc Makefile
	$(CC) $(CCFLAGS) -o $@ $< $(LFLAGS)

clean:
	rm -f *.o \
	cppcon2014_p1
	OOP