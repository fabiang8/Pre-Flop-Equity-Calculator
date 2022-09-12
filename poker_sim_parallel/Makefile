CC=gcc
CXX=g++
TOPDIR=..
INCLUDE=${TOPDIR}/include
SRC=${TOPDIR}/src
CFLAGS=-std=c99
CXXFLAG+=-std=c++17 -fsanitize=address -g -fopenmp

all: poker_sim

poker_sim: poker_sim.cpp ../libpheval.a
	${CXX} ${CFLAGS} ${CXXFLAG} -I${INCLUDE} $^ -o $@ 

../libpheval.a:
	$(MAKE) -C ../;

%.o: %.cc
	${CXX} -c ${CXXFLAG} -I${INCLUDE} $< -o $@ 

%.o: %.c
	${CC} -c ${CFLAGS} -I${INCLUDE} $< -o $@

clean:
	rm -f *.o poker_sim 