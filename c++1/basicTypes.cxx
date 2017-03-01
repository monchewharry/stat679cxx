/*
 * Here are basic C++ types and a program to show their sizes on the
 * current computer:
 *   
 *                           basic   C++   types
 *                          ---------------------
 *                         /            \        \
 *                        /              \        \
 *                  numbers               char     bool
 *                 /       \
 *                /          \
 *            integers         \
 *        -----------------      \
 *       /     /  |    \   \       \
 *   char wchar_t short int long     \
 *   (signed or unsigned)             floating-point
 *                                    /     |       \        
 *                                  float, double, long double
 */

#include <iostream>
using namespace std;

int main() {
    cout << "Here are the sizes, in bytes, of basic C++ types:" << endl;
    cout << "  char:        " << sizeof(char) << endl;
    cout << "  wchar_t:     " << sizeof(wchar_t) << endl;
    cout << endl;
    cout << "  bool:        " << sizeof(bool) << endl;
    cout << endl;
    cout << "  short int:   " << sizeof(short int) << endl;
    cout << "  int:         " << sizeof(int) << endl;
    cout << "  long int:    " << sizeof(long int) << endl;
    cout << endl;
    cout << "  float:       " << sizeof(float) << endl;
    cout << "  double:      " << sizeof(double) << endl;
    cout << "  long double: " << sizeof(long double) << endl;
    return 0;
}
