/*
  Title: Exercise 13-20 (Cash Register Overloading)
  Description: This program overloaded the + and - operators for the
    'cashRegister' type and the ++ and -- operator for the clsas
    'dispenserType'.
  Author: James Taddei
  Date: 9/15/21
*/

#include <iostream>
#include "cashRegister.h"
#include "dispenserType.h"
using namespace std;

int main() {
  // Code to test the overloaded operators
  cashRegister reg1(300), reg2(450);
  reg2 = reg2 - reg1; // Testing - operator
  cout << reg2 << endl;

  reg2 = reg2 + reg1; // Testing + operator
  cout << reg2 << endl;

  dispenserType dis1(12);
  dis1--; // Testing the decrement operators
  --dis1;
  cout << dis1 << endl;

  dis1++; // Testing the increment operators
  ++dis1;
  cout << dis1 << endl;

  return 0;
}
