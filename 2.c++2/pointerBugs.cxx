// pointer_bugs.cxx:  demonstration of problems introduced by pointers

#include <iostream>
#include <cstdlib>

using namespace std;

// We'll consider these bug-ridden functions.
void corrupt_my_memory();
void segmentation_fault_bad_pointer();
void segmentation_fault_array_index();
void bus_error();
void reference_to_low_memory_address();
void uninitialized_pointer();
void memory_leak();

void print_menu();

int main() {
    char bug_choice;
   
    print_menu();

    cin >> bug_choice;

    switch (bug_choice) {
    case '1':  corrupt_my_memory();               break;
    case '2':  segmentation_fault_bad_pointer();  break;
    case '3':  segmentation_fault_array_index();  break;
    case '4':  bus_error();                       break;
    case '5':  reference_to_low_memory_address(); break;
    case '6':  uninitialized_pointer();           break;
    case '7':  memory_leak();                     break;
    default:  cout << "illegal choice, use 1-7" << endl;
    }

    return 0;
}

void print_menu() {
    cout << "Here are 7 ways to ruin this program:" << endl;
    cout << "  1 corrupt_my_memory()" << endl
         << "  2 segmentation_fault_bad_pointer()" << endl
         << "  3 segmentation_fault_array_index()" << endl
         << "  4 bus_error()" << endl
         << "  5 reference_to_low_memory_address()" << endl
         << "  6 uninitialized_pointer()" << endl
         << "  7 memory_leak()" << endl;
    cout << "Enter 1-7:  ";
}

// Return sum of first n elements of A[].  This function is bug-free,
// but it will crash when it's called with a corrupted value
// (size=100000, when it should be 2) from corrupt_my_memory().
int sum(int A[], int n) {
    int answer = 0;

    cout << "sum(), a bug-free function, is running ..." << endl << endl;
    for (int i = 0; i < n; i++)
        answer += A[i];

    return answer;
}

// This function accidentally corrupts the value of it's "size"
// variable by over-running the bounds of its array "A[]".
void corrupt_my_memory() {
    cout << "Hello STAT 679 Students, This function isn't behaving" << endl
	 << "as it did when I prepared it (on desk22). I expected" << endl
	 << "A[3] = 100000 to overwrite my size variable. I'll try" << endl
	 << "to figure it out. --John" << endl;
    return;
    int i, size = 2;
    int A[2];
   
    cout << "corrupt_my_memory() ... " << endl;
    for (i = 0; i <= 2; i++) { // Oops! should be "i < 2;"
        A[i] = 100000;
    }
    cout << "size=" << size << endl; // We initialized size to 3!

    cout << endl << "What happened?  Let's check memory addresses:" << endl;
    for (i = 0; i < 3; i++) { // Now we're deliberately running past A[1].
	cout << "&A[" << i << "]=" << size_t(&A[i]) << endl;
    }
    cout << "&size   =" << size_t(&size) << endl;
    cout << "We shouldn't have used A[2]." << endl;
    cout << "size got corrupted because &[A2] == &size" << endl << endl;

    // Note that this function doesn't crash the program, even though
    // size is corrupted (we set it to 3, but now it's 100000).

    // Now we'll crash the program by passing the corrupted "size" to
    // a bug-free function, sum().
    i = sum(A, size);
}

void segmentation_fault_bad_pointer() {
    int i;
    int *ip;

    cout << "segmentation_fault_bad_pointer() ..." << endl << endl;
    // This address should be outside the memory allocated for our
    // program, so we'll get a segmentation fault, which is an access
    // to memory in violation of the operating system's memory
    // segmentation scheme.
    ip = &i + 1000000;
    *ip = 5;
}

void segmentation_fault_array_index() {
    int A[3];

    cout << "segmentation_fault_array_index() ..." << endl << endl;
    // This array element should be outside the memory allocated for
    // our program, so we'll get a segmentation fault, which is an
    // access to memory in violation of the operating system's memory
    // segmentation scheme.

    A[1000000] = 5; // Only A[0], A[1], and A[2] are valid.
}

// The memory "bus" is a (hardware) communication link between the CPU
// and memory.  It is one memory "word" wide (a "word" is typically 4
// bytes = 32 bits).  For simplicity and speed, it often allows access
// only to words at addresses divisible by the word size.  (Note: a
// bus error is not caused directly by an out-of-range array index,
// since that would still lead to a memory address divisible by 4.)
void bus_error() {
    int i = 10005;
    int *ip;

    ip = (int *) i; // Oops!  Should be "ip = &i;".  The compiler warned us.
    // (This doesn't compile on some machines; fix it by adding a cast
    // to the previous line: "ip = (int *) i;".

    cout << "bus_error() ..." << endl << endl;
    // Oops!  Now we write to memory address 10005, which the bus
    // can't handle, since 10005 isn't divisible by 4.
    *ip = 3;
}

// Pointer references to low memory addresses are so commonly bugs
// (from pointers initialized to zero, or to "i" instead of "&i") that
// the operating system has made the first 1000 or so bytes of memory
// inaccessible, to crash your program now, instead of letting it
// continue in a bad state.
void reference_to_low_memory_address() {
    double *d_ptr = 0;

    cout << "reference_to_low_memory_address() ..." << endl << endl;
    *d_ptr = 2.71;
}

void uninitialized_pointer() {
    short *s_ptr;

    cout << "unitialized_pointer() ..." << endl << endl;
    *s_ptr = 5;
    cout << "Which two bytes of memory did we just set to 5?  I have" << endl;
    cout << "no idea.  But we've caused one of the preceeding bugs." << endl;
}

void memory_leak() {
    cout << "Let's not run this one on a shared Statistics machine," << endl
	 << "as it could bog down the computer by using too much memory." << endl
	 << "Feel free to run it  on your own computer." << endl;
    return;

    int megabytes = 0;
    const int MEGABYTE = 1000000;

    while (true) {
        char *cp;

        // Each time after the first, we lose access to the previously
        // allocated array.
        cp = new char[MEGABYTE];
        megabytes++;
	if (megabytes % 10000 == 0) // cut error messages by factor of 10000
	    cout << megabytes << " MB allocated" << endl;
    }
}
