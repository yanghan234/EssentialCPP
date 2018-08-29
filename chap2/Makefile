CXX=icpc

all : by_reference.x static_mem.x

by_reference.x : by_reference.cpp
	${CXX} -o $@ $^

local_static_obj.x : local_static_obj.cpp
	${CXX} -o $@ $^

clean :
	rm *.x


