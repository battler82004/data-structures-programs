/*
  Title: Exercise 15-1 (Recursive Asterisk Generator)
  Description: This program takes a number and outputs double that many
    lines of asterisks through the use of a recursive function.
  Author: James Taddei
  Date: 9/27/21
*/

#include <iostream>
using namespace std;

// Function prototype
void asteriskGenerator(int, bool = true, int = 0);
  // This function takes in the total number of asterisks in the first
  // line and then recursively calls itself to ouput the correct num
  // of asterisks

int main() {
  // Variable declaration
  int numOfLines;

  // User input
  cout << "Enter the number of lines: ";
  cin >> numOfLines;

  asteriskGenerator(numOfLines); // Output

  return 0;
}

// This function takes in the total number of asterisks in the first
// line and then recursively calls itself to ouput the correct num
// of asterisks
void asteriskGenerator(int numOfAsterisks, bool isDecreasing, int max) {
  int callMax = max;
  // Since the program doesn't input max, the max is determined on the
  // initial run
  if (max == 0)
    callMax = numOfAsterisks;
  
  // Output curr line
  for (int i = 0; i < numOfAsterisks; i++) {
    cout << '*';
  }
  cout << endl;

  if (!isDecreasing && (numOfAsterisks == max)) // Base case
    return;
  else if (isDecreasing) { // Num is decreasing
    if (numOfAsterisks == 1) { // Changes from decreasing to increasing
      asteriskGenerator(numOfAsterisks, false, callMax);
    }
    else {
      asteriskGenerator(numOfAsterisks-1, true, callMax);
    }
  }
  else { // Num is increasing
    asteriskGenerator(numOfAsterisks+1, false, callMax);
  }
}
