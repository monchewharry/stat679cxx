// Stack.cxx: implementation file for Stack class declared in Stack.h.

#include <cassert>
#include <cstdlib> // for NULL
#include "Stack.h"

using namespace std;

Stack::Stack() {
    head = NULL;
}

Stack::~Stack() {
    while (head) { // delete list
        Node *p = head;
        head = head->next;
        delete p;
    }
}

void Stack::push(char c) {
    Node *p = new Node;
    p->data = c;
    p->next = head;
    head = p;
}

char Stack::pop() {
    Node *p = head;
    assert(!empty());
    char c = head->data;
    head = head->next;
    delete p;
    return c;
}

bool Stack::empty() const {
    return head == 0;
}
