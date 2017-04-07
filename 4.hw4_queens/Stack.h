// Stack.h:  header file for Stack<T> template class.

// Note: class (or struct) T must have operator<<() since debug()
// calls it.

#ifndef STACK_H
#define STACK_H

template <typename T>
struct Node { // for use in linked list implementation of Stack<T>
    T data;
    Node<T> *next;
};

template <typename T>
class Stack {
public:

    // Create empty stack.
    Stack();

    // Destroy stack.
    ~Stack();

    // Insert t at top of stack.
    void push(T t);

    // Remove top item and return it (crash if stack empty).
    T pop();

    // Return item [i]: [0]=bottom, [size()-1]=top (crash if no item i).
    T operator[](int i) const;

    // Return true if stack is empty.
    bool empty() const;

    // Return number of items currently in stack.
    int size() const;

    // Print stack contents.
    void debug() const;

private:

    Node<T> *head;
};

#include "Stack.template"

#endif
