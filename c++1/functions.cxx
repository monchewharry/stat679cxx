// functions.cxx demonstrates features of C++ functions and parameter
// passing. In particular, it has examples of void functions & return
// statements, functions that return values, functions that use
// parameters passed by value, functions that use parameters passed by
// pointer, and functions that use parameters passed by reference.

#include <iostream> // for cin, cout
#include <cassert>  // for assert()

using namespace std;

// Simplest function: no input parameters, no return value.
void print_hello(void);

// One input parameter, no return value.  (But there is a "return"
// statement.)
void print_hello(int n);

// Two input parameters, one return value. Returns x^n for positive
// integer n.
double baby_pow(double x, int n);

// "copy" is a "pass-by-value" parameter which is initialized to a
// copy of the caller's argument.
void set_copy_of_me_to_4(int copy);

// The "&" indicates "new_name" is a "pass-by-reference" parameter.
// This means that "new_name" is a local name for the caller's actual
// argument. Anything done to "new_name" is really done to the
// caller's underlying variable.
void set_me_to_5_by_reference(int &new_name);

// The "*" indicates that "pointer" is a pointer or memory address.
void set_me_to_6_by_pointer(int *pointer);

// A series of unrelated function calls for discussion.
int main () {
    int a = 1, b = 2, c = 3;

    print_hello();

    cout << "5 cubed is " << baby_pow(5.0, 3) << endl;

    print_hello(3);

    set_copy_of_me_to_4(a);
    cout << a << ", " << b << ", " << c << endl; // prints 1, 2, 3

    set_me_to_5_by_reference(b);
    cout << a << ", " << b << ", " << c << endl; // prints 1, 5, 3

    set_me_to_6_by_pointer(&c); // &c is the address of c.
    cout << a << ", " << b << ", " << c << endl; // prints 1, 5, 6

    return 0;
}

void print_hello(void) {
    cout << "Hello." << endl;
}

void print_hello(int n) {
    for (int i = 0; i < n; i++) {
	print_hello();
    }
}

double baby_pow(double x, int n) {
    int i;
    double answer = 1.0;
    assert(n > 0);  // means "continue if (n > 0); otherwise crash program"
    i = 1;
    while (i <= n) {
	answer *= x;
	i++;
    }
    return answer;
}

void set_copy_of_me_to_4(int copy) {
    copy = 4;
}

void set_me_to_5_by_reference(int &new_name) {
    new_name = 5;
}

void set_me_to_6_by_pointer(int *pointer) {
    *pointer = 6; // * means "dereference", or "value at address in pointer"
    cout << "  pointer=" << pointer << endl;
    cout << "  sizeof(pointer)=" << sizeof(pointer) << endl;
    cout << "  long(pointer)=" << long(pointer) << endl;
}
