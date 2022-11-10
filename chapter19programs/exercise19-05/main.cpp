/*
  Title: Exercise 19-5 (bSearchTreeType Test)
  Description: This program tests several features of the
    bSearchTreeType class.
  Author: James Taddei
  Date: 11/8/22
*/

#include <iostream>
#include "binarySearchTree.h"
using namespace std;

int main() {
  bSearchTreeType<int> tree; // Creation

  // Insertion
  tree.insert(1);
  tree.insert(2);
  tree.insert(7);
  tree.insert(3);
  tree.insert(9);

  tree.postorderTraversal(); // Output

  tree.destroyTree(); // Deletion

  return 0;
}
