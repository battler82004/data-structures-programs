/*
  Title: Exercise 14-5 (Numeric to Standard DOB)
  Description: This program takes in a numeric date (1980-8-27) and
    then converts it to the 'standard' form (August 27, 1980). It will
    also throw an error and ask the user to reenter the month/day if
    it's invalid.
  Author: James Taddei
  Date: 9/23/22
*/

#include <iostream>
#include <string>
#include "invalidDay.h"
#include "invalidMonth.h"
using namespace std;

// Function prototypes
bool isDayInvalid(int, int, int);
  // Checks if the entered number of days is invalid given the month
  // and year
string numToMonth(int);
  // Takes in a number and returns the associated month

int main() {
  // Variable declaration
  string dateOfBirth;
  int year, month, day;

  // User input
  cout << "Enter your date of birth numerically (8-27-1980):" << endl;
  cin >> year;

  while(true) { // Month input
    cin >> month;
    try { // Checks if the number of months is invalid
      if ((month < 1) || (month > 12)) {
        throw invalidMonth();
      }
      break; // Don't ask for reentry
    }
    catch(invalidMonth invalidMonthObj) {
      cout << invalidMonthObj.what() << endl;
    }
  }

  while(true) { // Day input
    cin >> day;
    try { // Checks if the number of days is invalid
      if (isDayInvalid(month, day, year)) {
        throw invalidDay();
      }
      break; // Don't ask for reentry
    }
    catch(invalidDay invalidDayObj) {
      cout << invalidDayObj.what() << endl;
    }
  }

  // Final output
  cout << numToMonth(month) << ' ' << day << ", " << year << endl;

  return 0;
}

// Checks if the entered number of days is invalid given the month
// and year
bool isDayInvalid(int m, int d, int y) {
  // If >31 or <1 day
  if ((d > 31) || (d < 1))
    return true;

  // Months with 30 days
  if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
    if (d == 31) // 31 days in 30 day month
      return true;
    else
      return false;
  }

  if (m != 2) // Not Feb
    return false;
  else { // Feb
    if (d > 29) // 30 or 31 days
      return true;
    if (d == 29) { // need to check for leap year
      if (y % 4 != 0)
        return true; // common year
      if (y % 100 != 0)
        return false; // leap year
      if (y % 400 != 0)
        return true; // common year
    }
    return false; // <29 days or leap year at 29
  }
}

// Takes in a number and returns the associated month
string numToMonth(int num) {
  switch(num) {
    case 1:
      return "January";
      break;
    case 2:
      return "February";
      break;
    case 3:
      return "March";
      break;
    case 4:
      return "April";
      break;
    case 5:
      return "May";
      break;
    case 6:
      return "June";
      break;
    case 7:
      return "July";
      break;
    case 8:
      return "August";
      break;
    case 9:
      return "September";
      break;
    case 10:
      return "October";
      break;
    case 11:
      return "November";
      break;
    case 12:
      return "December";
      break;
  }
  return "Error"; // Entered number is invalid
}
