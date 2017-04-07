// Bit_Vector.cxx implements the class declared in Bit_Vector.h.
// Note: You don't have to change this code.

#include <iostream>  // for istream, ostream
#include <climits>   // for CHAR_BIT, #bits in a char
#include <cassert>   // for assert()
#include "Bit_Vector.h"

using namespace std;

void Bit_Vector::write(ostream &os) {
    unsigned char c = 0;
    os << size() << endl;

    for (size_t i = 0; i < size(); i++) {
	if ((i > 0) && ((i % 8) == 0)) {
	    os.put(c);
	    c = 0;
	}
	c |= ((*this)[i] << (i % 8)); // Set bit number (i % 8) of c.
    }
    os.put(c);
}

void Bit_Vector::read(istream &is) {
    size_t n;
    is >> n;
    unsigned char c = is.get();
    assert(c == '\n');

    while (!is.eof()) {
	c = is.get();
	for (size_t i = 0; i < CHAR_BIT; i++)
	    push_back(1 & (c >> i));  // Add bit i of c to back of vector.
    }

    resize(n);
}

ostream & operator<<(ostream &os, const Bit_Vector &b) {
    for (size_t i = 0; i < b.size(); i++)
	os << (b[i] ? '1' : '0');
    return os;
}
