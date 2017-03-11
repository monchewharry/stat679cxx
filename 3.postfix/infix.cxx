// infix.cxx: Use the Stack class to convert an infix arithmetic
// expression to the equivalent postfix expression.

#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack operators;
    char c;

    cout << "Enter an infix expression like ((3+4)*(1+2))"
	 << " for conversion to postfix: " << endl;

    while ((c = cin.get()) != '\n') {
	if (c == ')') {
	    cout << operators.pop() << " ";
	} else if ((c == '+') || (c == '*') || (c == '-') || (c == '/')) {
	    operators.push(c);
	} else if ((c >= '0') && (c <= '9')) {
	    cout << c << " ";
	}
    }
    cout << endl;

    return 0;
}       
