CPP=g++
LIBS=
LFLAGS=$(LIBS)
CPPFLAGS=-ansi -Wall -pedantic-errors $(DEBUG)
DEBUG=-g -pg -fno-inline -O0
trg=robobo

all: $(trg)
   
$(trg): robobo.o socket.o
	$(CPP) $? -o $@

socket.o: socket.cpp socket.h
	$(CPP) -c $< -o $@ $(CPPFLAGS)

robobo.o: robobo.cpp robobo.h
	$(CPP) -c $< -o $@ $(CPPFLAGS)

.PHONY: clean cleanall

cleanall: clean
	rm $(trg)

clean: 
	rm -f *.o
