// testStack.cxx: quick interactive program to exercise Stack<T> code.

#include <iostream>
#include "Stack.h"

void print_menu() {
    cout << endl
	 << "Commands like the following are available: " << endl
	 << "   p a  (push 'a')" << endl
	 << "   o    (pop)" << endl
	 << "   e    (empty: print whether stack is empty)" << endl
	 << "   i 2  (i_th: print stack[2])" << endl
	 << "   s    (size: print size of stack)" << endl
	 << "   q    (quit)" << endl
	 << "Enter command: ";
}

template <class T>
void print_stacks(const Stack<T> &s1, const Stack<T> &s2) {
    cout << endl;
    cout << "s1 contains:" << endl;
    s1.debug();
    cout << "s2 contains:" << endl;
    s2.debug();
    cout << endl;
}

int main() {
    Stack<char> s;
    char command;

    do {
	print_menu();
	cin >> command;

	switch(command)	{
	case 'p':
	    char data;
	    cin >> data;
	    s.push(data);
	    break;
	case 'o':
	    cout << s.pop() << endl;
	    break;
	case 'e':
	    cout << s.empty() << endl;
	    break;
	case 'i':
	    char dat;
	    cin >> dat;
	    cout << s[dat - '0'] << endl;
	    break;

	case 's':
	    cout << s.size() << endl;
	    break;

	default:
	    break;
	}
	
	s.debug();
    } while (command != 'q');

    return 0;
}       
