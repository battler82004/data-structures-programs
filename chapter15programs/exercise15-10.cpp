/*
  Title: Exercise 15-10 (Recursive Summation of Digits)
  Description: This program takes in a number and finds the total of
    all of the digits in the number.
  Author: James Taddei
  Date: 9/27/21
*/

#include <iostream>
using namespace std;

// Function prototypes
int sumDigits(int, int = 0);
  // This function recursively finds the total of the digits of the
  // inputted num

int main() {
  // Variable declaration
  int num;

  // User input
  cout << "Enter the integer whose digits should be added: ";
  cin >> num;

  cout << sumDigits(num) << endl; // Output and calculation

  return 0;
}

// This function recursively finds the total of the digits of the
// inputted num
int sumDigits(int num, int currTotal) {
  // Variable declaration
  int nextNum, currDigit, total;

  if (num < 10) { // Base case (only 1 digit left)
    return currTotal + num;
  }

  currDigit = num % 10; // Finds the digit in the curr ones place
  nextNum = (num - currDigit) / 10; // Num w/o the curr ones place

  return sumDigits(nextNum, currTotal+currDigit);
}
