// bits.cxx demonstrates the C++ "bitwise" logical operators:

//    &   bitwise and              (set intersection)
//    |   bitwise or               (set union)
//    ~   bitwise not              (set complement)
//    ^   bitwise exclusive or     (set difference)
//    <<  left shift               (multiplication by 2 ^ (size of shift))
//    >>  right shift              (division by 2 ^ (size of shift);
//                                  undefined for signed integer)
//
// These operators can be applied only to integers, and they result in
// integer values, not bool values.
//
// Note that the bitwise operators aren't the same as the usual
// logical operators:
//    &&  short-circuit logical "and"
//        (applied to two boolean expressions; returns bool value)
//    ||  short-circuit logical "or"
//        (applied to two boolean expressions; returns bool value)
//    !   logical "not"
//        (applied to one boolean expression; returns bool value)

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Print the 32 bits of n and the usual (integer) value of n.
void bits(int n) {
    int i, bit;

    for(i = 31; i >= 0; i--) {
        if ((i % 4) == 3)       // print a space every 4 bits
            cout << " ";

        // To get n's bit #i, right-shift n by i ("n >> i"), which puts
        // this bit in the right-most digit.  Then do bitwise and ("&")
        // with 1 (whose bit representation is "000...001") to get n's
        // bit #i as a 0 or 1.
        bit = (n >> i) & 1;
        cout << bit;
    }

    cout << " = " << n << endl;
}

int main(int argc, char *argv[]) {
    while (true) { // infinite loop (but it includes "break", below)
        string op; // operator
        int a, b;  // operands
	int n;     // result of operation

        cout << endl << "Enter operator, or 'q' to quit:  ";
        cin >> op;
        if (op == "q")
            break;

        if (op == "&" || op == "|" || op == "^" || op == "<<" || op == ">>") {
            cout << "Enter a and b (e.g. 2 31):  ";
            cin >> a >> b;

            if (op == "&")
                n = a & b;             
            else if (op == "|")
                n = a | b;
            else if (op == "^")
                n = a ^ b;
            else if (op == "<<")
                n = a << b;
            else if (op == ">>")
                n = a >> b;

            bits(a);
            bits(b);
            bits(n);
        } else if (op == "~") {
            cout << "Enter a:  ";
            cin >> a;
            n = ~a;
            bits(a);
            bits(n);
        }
    }

    return 0;
}
