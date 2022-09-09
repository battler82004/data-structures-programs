#include "unorderedArrayListType.h"
using namespace std;

// Returns the bool for if num is in the array
bool unorderedArrayListType::isInList(int num) {
  int *tempPtr = getList(); // Doesn't have access to list

  for (int i = 0; i < getLength(); i++) {
    if (tempPtr[i] == num) { // Found num in array
      return true;
    }
  }

  return false;
}

// Removes all instances of num from the array
void unorderedArrayListType::removeAll(int num) {
  do {
    remove(num);
  } while (isInList(num));
}

// Constructor (only needs inherited constructor)
unorderedArrayListType::unorderedArrayListType(int
  nums[8], int len): arrayListType(nums, len) {
  
  return;
}
