// Bit_Vector.h declares a class that extends the STL's
// vector<unsigned char> class to allow binary reading
// and writing of bit vectors.
//
// Since this new Bit_Vector class extends vector<unsigned char>,
// it has these operations (among others):
// - operator[] for usual array access
// - size()
// - push_back() to insert at the back (position size())
// It will resise itself automatically if its capacity is exceeded.
//
// Bit_Vector extends the vector<unsigned char> class by adding
// write(), read(), and operator<<(), below.

#ifndef BIT_VECTOR_H
#define BIT_VECTOR_H

#include <vector>      // for STL's vector class

using namespace std;

class Bit_Vector: public vector<unsigned char> {
public:

    // Write Bit_Vector as binary data to the output stream "os".
    // First write the length n of the vector as an ASCII integer,
    // then a newline, and then a sequence of (n+7)/8 (that's n/8,
    // rounded up) bytes containing the appropriate bits.
    void write(ostream &os);

    // Read a Bit_Vector from the input stream "is", using the format
    // specified in the write() function.
    void read(istream &is);

    // Write Bit_Vector b as ASCII data: each bit is represented by a
    // '0' or '1' so that the vector is easy to see for debuggging.
    friend ostream & operator<<(ostream &os, const Bit_Vector &b);
};

#endif
