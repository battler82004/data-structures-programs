/*
  Title: Exercise 18-3 (Sequential Search)
  Description: This program implements a sequential
    search function and tests its implementation.
  Author: James Taddei
  Date: 10/27/22
*/

#include <iostream>
#include "searchSortAlgorithms.h"
using namespace std;

int main() {
  // Variable declaration, ex array
  int array[5] = {1,3,2,5,4}, x = 0;

  // Output
  cout << "Pos of '2': " << seqOrdSearch(array, 5, 2)
    << endl;
  cout << "Pos of '6': " << seqOrdSearch(array, 5, 6)
    << endl;

  // += for regex in MindTap
  x += seqOrdSearch(array, 5, 2);

  return 0;
}
