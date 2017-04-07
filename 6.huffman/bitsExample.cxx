// This program writes the bits 01000001 to a Bit_Vector called
// "bits". Then it writes that vector to the file "bitsOut". Then it
// reads "bitsOut" into a new Bit_Vector called "moreBits". The it
// writes those bits to the standard output so that we can check them.
// It writes them once collectively using operator<<() and a second
// time individually using operator[]().
//
// Compile via "make". Then run "bits". Then use emacs to read
// "bitsOut" so you know what is in it. Then read the output of "bits"
// in your shell to confirm that it is the bit vector we created,
// "01000001".

#include <iostream>
#include <fstream>
#include <cassert>
#include "Bit_Vector.h"

using namespace std;

int main() {
    Bit_Vector bits;          // Create a bit vector containing the
                              // bits 01000001, which fit in one byte
                              // whose integer value is 65. The ASCII
                              // character with value 65 is 'A', so
                              // the byte written this bit vector
                              // should look like an 'A'.
    bits.push_back(1); // 1 * 2^0 =  1; this is like "bits[0] = 1;"
    bits.push_back(0); // 0 * 2^1 =  0
    bits.push_back(0); // 0 * 2^2 =  0
    bits.push_back(0); // 0 * 2^3 =  0
    bits.push_back(0); // 0 * 2^4 =  0
    bits.push_back(0); // 0 * 2^5 =  0
    bits.push_back(1); // 1 * 2^6 = 64; this is like "bits[6] = 1;"
    bits.push_back(0); // 0 * 2^7 =  0
    // Now bits contains 01000001.
    ofstream ofs;
    ofs.open("bitsOut");
    assert(ofs.good());
    // Now write bits to a file. This writes its length, 8 bits,
    // followed by its bytes, ASCII 65, an 'A'.
    bits.write(ofs);
    ofs << endl;
    ofs.close();

    // Now read the bit vector file and check its contents.
    ifstream ifs;
    ifs.open("bitsOut");
    assert(ifs.good());
    Bit_Vector moreBits;
    moreBits.read(ifs);
    size_t n = moreBits.size();
    cerr << moreBits << endl; // Use operator<<() from Bit_Vector.cxx.
    // Or print the bits one at a time:
    for (size_t i = 0; i < n; i++) {
	// moreBits[i] is 0 or 1, neither of which is a printable
	// character. Add '0' (ASCII 48) to it to get it to printable
	// characters '0' or '1'.
	cout << (char) ('0' + moreBits[i]) << endl;
    }
    cout << endl;

    return 0;
}
