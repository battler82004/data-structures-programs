/*
  Title: Exercise 14-1 (Feet to Cm w/ Exceptions)
  Description: This program takes in the length something through 2
    inputs (the length in feet and the length in inches) and converts
    this total length to cm. If a negative number is inputted, an
    exception will be thrown.
  Author: James Taddei
  Date: 9/20/22
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Named constants
const double FEET_IN_INCHES = 12.0; // 12 in per ft
const double CM_IN_INCH = 2.54; // 2.54 cm per in

int main() {
  // Variable declaration
  double lengthInFeet = 0, lengthInInches = 0, lengthInCm;
  bool shouldRepeat = true;

  do { // User input
    try { // Error is thrown if neg value is entered for either
      cout << "Length in feet: ";
      cin >> lengthInFeet;

      cout << "Length in inches: ";
      cin >> lengthInInches;

      if ((lengthInFeet < 0) || (lengthInInches < 0)) {
        throw -1; // If neg value
      }

      shouldRepeat = false;
    }
    catch(int) {
      cout << "A non positive number is entered." << endl;
    }
  } while(shouldRepeat);

  lengthInCm = (lengthInFeet * FEET_IN_INCHES + lengthInInches) *
    CM_IN_INCH;

  cout << setprecision(2) << showpoint << fixed; // sets to something.xx
  cout << "Length in cm: " << lengthInCm << endl;

  return 0;
}
