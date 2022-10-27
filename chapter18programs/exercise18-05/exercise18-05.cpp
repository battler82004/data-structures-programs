/*
  Title: Exercise 18-5 (Bubble Sort)
  Description: This program implements and tests a bubble
    sort algorithm function.
  Author: James Taddei
  Date: 10/27/22
*/

#include <iostream>
#include "searchSortAlgorithms.h"
using namespace std;

// Named constants
const int LEN_OF_ARRAY = 6;

// Function prototypes
void printArray(int[], int);
  // Prints out all of the elements in the inputted
  // array.

int main() {
  // Variable declarations
  int array[LEN_OF_ARRAY] = {1,3,5,4,2,3};

  // Sorting test
  cout << "Pre-sort: ";
  printArray(array, LEN_OF_ARRAY);

  modifiedBubbleSort(array, LEN_OF_ARRAY);
  cout << "Post-sort: ";
  printArray(array, LEN_OF_ARRAY);

  return 0;
}

// Prints out all of the elements in the inputted array.
void printArray(int list[], int length) {
  for (int i = 0; i < length; i++) {
    cout << list[i] << " ";
  }
  cout << endl;
}
