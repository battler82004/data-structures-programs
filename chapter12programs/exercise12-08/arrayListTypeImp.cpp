#include <iostream>
#include "arrayListType.h"
using namespace std;

// Removes the first occurance of num
void arrayListType::remove(int num) {
  bool hasRemoved = false;
  int *tempPtr, pos = 0;
  
  tempPtr = new int[length-1]; // Assumes num is in array
  // This array will hold the OG array minus the removed
  // num

  for (int i = 0; i < length; i++) {
    if (!hasRemoved) { // Hasn't removed occurance yet
      if (list[i] == num) { // Checks if first occurance
        hasRemoved = true;
        continue; // Stops the number from being copied
      }
    }

    tempPtr[pos] = list[i];
    pos++;
  }

  length--; //Assumes num is in OG array

  delete [] list; // Delete the list with the removed num
  list = tempPtr;

  return;
}

// Prints out the array separated by spaces
void arrayListType::print() const {
  cout << endl;

  for (int i = 0; i < length; i++) {
    cout << list[i] << " ";
  }
}

// Constructor
arrayListType::arrayListType(int nums[100], int len) {
  length = len;
  list = new int[length];

  for (int i = 0; i < length; i++) {
    list[i] = nums[i];
  }
}
