/*
  Title: Exercise 14-4 (12 hr to 24 hr Converter)
  Description: This program takes in a 12 hr notation time (to the
    second) and converts it to the 24 hr time notation while throwing
    an error if one of the times is invalid.
  Author: James Taddei
  Date: 9/22/21
*/

#include <iostream>
#include <string>
#include "invalidHr.h"
#include "invalidMin.h"
#include "invalidSec.h"
using namespace std;

int main() {
  // Variable declaration
  int hr, min, sec;
  string aOrPm;
  bool isAM;

  // User input
  cout << "Enter the time (to the second) in 12-hour notation:" << endl;
  cin >> hr >> min >> sec >> aOrPm;
  isAM = (aOrPm == "AM");

  try { // Checks for any invalid nums in the time
    if ((hr < 1) || (hr > 12))
      throw invalidHr();
    if ((min < 0) || (min >= 60))
      throw invalidMin();
    if ((sec < 0) || (sec >= 60))
      throw invalidSec();
  }
  catch(invalidHr invalidHrObj) {
    cout << invalidHrObj.what() << endl;
  }
  catch (invalidMin invalidMinObj) {
    cout << invalidMinObj.what() << endl;
  }
  catch (invalidSec invalidSecObj) {
    cout << invalidSecObj.what() << endl;
  }

  // Converting to 24 hour time notation
  if (isAM) {
    if (hr == 12) // 12 + 12 = 24 --> = 0 am
      hr = 0;
  }
  else {
    hr += 12;
  }

  cout << hr << ':' << min << ':' << sec <<  endl;

  return 0;
}
