/*
  Title: Exercise 18-8 (Insertion Sort)
  Description: This program implements and tests an
    insertion sort function which was pre-written.
  Author: James Taddei
  Date: 10/27/22
*/

#include <iostream>
#include "searchSortAlgorithms.h"
using namespace std;

// Named constants
const int LEN_OF_ARRAY = 10;

// Function prototypes
void printArray(const int[], int);
  // Prints out all the elements in an array on 1 line.

int main() {
  // Variable declaration
  int array[LEN_OF_ARRAY];

  // User input
  cout << "Enter 10 integers for the list: " << endl;
  for (int i = 0; i < LEN_OF_ARRAY; i++) {
    cin >> array[i];
  }

  cout << endl << endl << "Pre-sort: ";
  printArray(array, LEN_OF_ARRAY);

  // Sort + Post-sort
  insertionSort(array, LEN_OF_ARRAY);
  cout << "Post-sort: ";
  printArray(array, LEN_OF_ARRAY);

  return 0;
}

// Prints out all the elements in an array on 1 line.
void printArray(const int list[], int length) {
  for (int i = 0; i < length; i++) {
    cout << list[i] << ' ';
  }
  cout << endl;
}
