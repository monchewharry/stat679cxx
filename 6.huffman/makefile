all: io bits d c

io: iostreamExample.cxx
	g++ -Wall -g -o io iostreamExample.cxx
compress.o: compress.cxx
	g++ -Wall -g -c compress.cxx
c: Bit_Vector.o compress.cxx
	g++ -Wall -g -o c Bit_Vector.o compress.cxx

decompress.o: decompress.cxx
	g++ -Wall -g -c decompress.cxx
d: Bit_Vector.o decompress.o
	g++ -Wall -g -o d Bit_Vector.o decompress.o
Bit_Vector.o: Bit_Vector.h Bit_Vector.cxx
	g++ -Wall -g -c Bit_Vector.cxx

bitsExample.o: bitsExample.cxx
	g++ -Wall -g -c bitsExample.cxx

bits: Bit_Vector.o bitsExample.o
	g++ -Wall -g -o bits Bit_Vector.o bitsExample.o
clean:
	rm -f io bits d c core *.o