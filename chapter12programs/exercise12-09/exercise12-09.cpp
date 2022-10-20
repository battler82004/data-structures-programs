 /*
  Title: Exercise 12-9 (Min in Array)
  Description: This program was mostly a pre-written
    version of 12-8. The assignment was to add the
    'min' method which returns the lowest value in the
    inputted list.
  Author: James Taddei
  Date: 7/8/22
*/
 
#include <iostream>
#include <string>
#include "unorderedArrayListType.h"
using namespace std;

int main() {
  // Variable declaration
  string curr;
  unorderedArrayListType unoArrayList;

  // Variable input
  for (int i = 0; i < unoArrayList.maxListSize(); i++) {
    getline(cin, curr);

    // If nothing is stored in curr, then the list is over
    if (curr.empty()) {
      break;
    }

    unoArrayList.insertEnd(stoi(curr));
  }

  cout << "The smallest number in intList: " <<
    unoArrayList.min() << endl;

  return 0;
}
