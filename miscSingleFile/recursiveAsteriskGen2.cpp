/*
  Title: Exercise 15-(1.2) (Recursive Asterisk Generator)
  Description: This program takes a number and outputs double that many
    lines of asterisks through the use of a recursive function.
  Author: James Taddei
  Date: 9/27/21
*/

#include <iostream>
using namespace std;

// Function prototype
void asteriskGenerator(int);
  // This function takes in the total number of asterisks in the first
  // line and then recursively calls itself to ouput the correct num
  // of asterisks
void deAsterisks(int);
void inAsterisks(int, int = 1);

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
void asteriskGenerator(int numOfAsterisks) {
    deAsterisks(numOfAsterisks);
    inAsterisks(numOfAsterisks);
}

void deAsterisks(int num) {
    // Output curr line
    for (int i = 0; i < num; i++) {
        cout << '*';
    }
    cout << endl;
    
    if (num != 1)
        deAsterisks(num-1);
}

void inAsterisks(int max, int curr) {
    // Output curr line
    for (int i = 0; i < curr; i++) {
        cout << '*';
    }
    cout << endl;
    
    if (curr != max)
        inAsterisks(max, curr+1);
}
