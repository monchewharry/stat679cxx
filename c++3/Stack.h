// Stack.h:  header file for Stack class.

#ifndef STACK_H // prevent double-inclusion of this file
#define STACK_H

// Declare a user-defined type "Node" for use in linked list
// implementation of a Stack.
struct Node {
    char data;  // data in this node
    Node *next; // pointer to next node
};
// A C++ "struct" is a data structure. Suppose we have
//   Node n = new Node;
//   Node * p = &n;
// Then we can access the members of n via
//   - the "." operator, as in n.data and n.next
//   - the "->" operator, as in p->data and p->next

// Declare a user-defined type "Stack" having public member functions
// and a private data member.
class Stack {
public:
    
    Stack(); // Constructor to create empty stack.

    ~Stack(); // Destructor to destroy stack.

    void push(char c); // Insert c at top of stack.

    char pop(); // Remove top item and return it (crash if empty).

    bool empty() const; // Return true if stack is empty.

private:

    Node *head; // pointer to head of linked list
};

#endif
