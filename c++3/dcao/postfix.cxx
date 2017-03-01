#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
  Stack operators;
  char c;
  
  cerr << "Enter an postfix expression like 3 4 - 4 2 / *" << endl;
  
  while ((c = cin.get()) != '\n'){
    if ((c >= '0') && (c <= '9')) {
      int i;
      i = c - '0';
      operators.push(i);
    } else if (c == '+') {
      int a1;
      int a2;
      int result;      
      a1=operators.pop();
      a2=operators.pop();
      result = a2 + a1;
      operators.push(result);      
    } else if (c == '*') {
      int a1;
      int a2;
      int result;      
      a1=operators.pop();
      a2=operators.pop();
      result = a1 * a2;
      operators.push(result);
    } else if (c == '-') {
      int a1;
      int a2;
      int result;
      a1=operators.pop();
      a2=operators.pop();
      result = a2 - a1;
      operators.push(result);
    } else if (c == '/') {
      int a1;
      int a2;
      int result;
      a1=operators.pop();
      a2=operators.pop();
      result = a2 / a1;
      operators.push(result);
    }
  }  
  cout << "the result is "<<operators.pop()  << endl;
  return 0;
}
