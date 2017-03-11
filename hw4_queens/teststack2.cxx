#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
  Stack<int> s;
  s.push(0);//initial (0,0)
  //s.push(1);
 int * mypointer;
mypointer = s;  
cout << mypointer <<endl;
  cout << "helloworld"<<endl;
  return 0;
}
