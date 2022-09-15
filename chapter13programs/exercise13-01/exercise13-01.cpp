/*
  Title: Exercise 13-1 (Overloading Operators)
  Description: This program overloads several default operators so that
    they work with the 'rectangleType' class.
  Author: James Taddei
  Date: 9/15/21
*/

#include <iostream>
#include "rectangleType.h"
using namespace std;

int main() {
  // Code to test the overloaded operators
  cout << "Test" << endl;

  rectangleType rect1(7,5), rect2(3,4);
  rect1 = rect1 + rect2;
  cout << rect1.getLength() << " " << rect1.getWidth();

  return 0;
}
