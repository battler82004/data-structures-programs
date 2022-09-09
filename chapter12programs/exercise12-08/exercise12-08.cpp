/*
  Title: Exercise 12-8 (Remove All Array List)
  Description: This program takes in a set of numbers
    separated by newlines until the user puts nothing
    before  newline. These numbers are stored in an
    array except for the last one which is the number
    to be removed. All occurances of the num are then
    removed from the array.
  Author: James Taddei
  Date: 7/8/21
*/
 
#include <iostream>
#include <string>
#include "unorderedArrayListType.h"
using namespace std;

int main() {
  // Variable declaration
  int data[100], currInt, len;
  string curr;

  // Variable input
  for (int i = 0; i < 100; i++) {
    getline(cin, curr);

    // If the string is empty, the last inputted value
    // was the number to be removed
    if (curr.empty()) {
      currInt = data[i-1]; // currInt is to be removed
      len--;
      break;
    }

    data[i] = stoi(curr);
    len = i+1;
  }

  // Declare the unordered array
  unorderedArrayListType unoArrayList(data, len);
  unoArrayList.print();

  unoArrayList.removeAll(currInt);
  unoArrayList.print();

  return 0;
}
