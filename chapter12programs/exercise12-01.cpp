/*
  Title: Exercise 12-1 (Dynamic Capitalized String)
  Description: This program takes in the length of a string and the
    string itself and uses a dynamic array to capitalize every char
    in the string and output said new string.
  Author: James Taddei
  Date: 7/6/21
*/

#include <iostream>
#include <string> 
using namespace std;

int main() {
  // Variable declaration
  int lenOfStr;
  string inputtedString;
  char *inputtedStringPtr;

  // Variable input
  cout << "Enter the length of a string: ";
  cin >> lenOfStr;
  cout << "Enter the string: ";
  cin >> inputtedString;
  inputtedStringPtr = new char[lenOfStr];

  // Capitalizes every letter in the string and stores it in the
  // dynamic array 
  for (int letter = 0; letter < lenOfStr; letter++) {
    inputtedStringPtr[letter] = toupper(inputtedString[letter]);
  }

  // Outputs every char in the array
  for (int letter = 0; letter < lenOfStr; letter++) {
    cout << inputtedStringPtr[letter];
  }

  cout << endl;
  delete inputtedStringPtr;

  return 0;
}
