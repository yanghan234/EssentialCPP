CXX=icpc

all : by_reference.x static_mem.x

by_reference.x : by_reference.cpp
	${CXX} -o $@ $^

static_mem.x : static_mem.cpp
	${CXX} -o $@ $^

clean :
	rm *.x


