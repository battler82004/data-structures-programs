/*
  Title: Exercise 17-1 (stackType ==)
  Description: This program adds an overloaded verison of the ==
    operator the stackType stack. It also has two basic tests of
    the operator.
  Author: James Taddei
  Date: 10/20/22
*/

#include <iostream>
#include "myStack.h"
using namespace std;

int main() {
  stackType<int> stack1, stack2;

  // Don't equal
  stack1.push(7);
  stack1.push(9);
  stack1.push(8);
  stack2.push(7);
  stack2.push(9);
  stack2.push(7);
  cout << (stack1 == stack2) << endl;

  // Do equal
  stack2.pop();
  stack2.push(8);
  cout << (stack1 == stack2) << endl;

  return 0;
}
