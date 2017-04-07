all: io bits

io: iostreamExample.cxx
	g++ -Wall -g -o io iostreamExample.cxx

Bit_Vector.o: Bit_Vector.h Bit_Vector.cxx
	g++ -Wall -g -c Bit_Vector.cxx

bitsExample.o: bitsExample.cxx
	g++ -Wall -g -c bitsExample.cxx

bits: Bit_Vector.o bitsExample.o
	g++ -Wall -g -o bits Bit_Vector.o bitsExample.o

clean:
	rm -f io bits core *.o
