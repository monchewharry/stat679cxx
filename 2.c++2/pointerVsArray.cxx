// pointerVsArray.cxx shows the relationship between pointer
// arithmetic and array indexing. In particular, if A is a pointer,
// as in 
//   int *A = new int[3];
// then
//   (A + i) == &(A[i]) // (A + i) is the address of the ith element of A
// and
//  *(A + i) ==   A[i]  // *(A + i) is the                ith element of A
// An array name is a just a pointer containing the address of its 0th element.

#include <iostream>
using namespace std;

void compare_pointer_and_array() {
    int *A = new int[3];
    A[0] = 10;
    A[1] = 11;
    A[2] = 12;
    
    cout << "  compare_pointer_and_array():" << endl;
    for (int i = 0; i < 3; i++) {
	cout << "     (A + " << i << ")=" <<  (A + i)
	     << ", &(A[" << i << "])=" << &(A[i]) << endl;
	cout << "    *(A + " << i << ")=" << *(A + i)
	     << ", A[" << i << "]=" << A[i] <<  endl;
    }
    cout << endl;
    delete [] A;
}

void zero_array(int A[], int n) {
    for(int i = 0; i < n; i++) {
	A[i] = 0;
    }
}

void zero_array_via_pointer(int *A, int n) {
    for(int i = 0; i < n; i++) {
	*(A + i) = 0;
    }
}

void print_array(int A[], int n) {
    cout << "  Printing an array of length " << n << ":" << endl;
    for(int i = 0; i < n; i++) {
	cout << "    A[i=" << i << "]=" << A[i] << endl;
    }
}

int main() {
    cout << "What is the relationship between pointers and an arrays?" << endl;
    compare_pointer_and_array();

    int B[3];
    cout << "Here is B, unitialized and then set to zero by array:" << endl;
    print_array(B, 3);
    zero_array(B, 3);
    print_array(B, 3);
    cout << endl;

    int C[3];
    cout << "Here is C, unitialized and then set to zero by pointer:" << endl;
    print_array(C, 3);
    zero_array_via_pointer(C, 3);
    print_array(C, 3);

    return 0;
}
