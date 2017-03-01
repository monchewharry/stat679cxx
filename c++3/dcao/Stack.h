#ifndef STACK_H // prevent double-inclusion of this file
#define STACK_H

// Declare a user-defined type "Node" for use in linked list
// implementation of a Stack.
struct Node {
    int data;  // data in this node
    Node *next; // pointer to next node
};

// Declare a user-defined type "Stack" having public member functions
// and a private data member.
class Stack {
public:
    
    Stack(); // Constructor to create empty stack.

    ~Stack(); // Destructor to destroy stack.

    void push(int i); // Insert c at top of stack.

    int pop(); // Remove top item and return it (crash if empty).

    bool empty() const; // Return true if stack is empty.

private:

    Node *head; // pointer to head of linked list
};

#endif
