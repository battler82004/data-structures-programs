/*
  Title: Exercise 19-10 (Binary Tree Post and Pre Copy)
  Description: This program takes in a binary tree before output it
    in postorder while coppying it, outputs that tree in preorder
    while copying it, outputs that tree in inorder, and outputs the
    height and leaves of the trees.
  Author: James Taddei
  Date: 11/9/22
*/

#include <iostream>
#include "binarySearchTree.h"
using namespace std;

// Sample input 1: 10, 5, 7, -999
// Sample input 2: 9 -10 3 14 -8 6 -999

int main() {
  // Variable declaration
  bSearchTreeType<int> tree1, tree2, tree3;
  int num;

  // Part A (building T1)
  cout << "Enter numbers ending with -999: ";
  cin >> num;

  while (num != -999) {
    tree1.insert(num);
    cin >> num;
  }
  cout << endl;

  // Part B (Postorder T1 + T2 creation)
  cout << "tree1 nodes in postorder: ";
  tree2.postOrderCopy(tree1);
  cout << endl;

  // Part C (Preorder T2 + T3 creation)
  cout << "tree2 nodes in preorder: ";
  tree3.preOrderCopy(tree2);
  cout << endl;

  // Part D (Inorder T3)
  cout << "tree3 nodes in inorder: ";
  tree3.inorderTraversal();
  cout << endl;

  // Part E (Heights and Leaves)
  cout << endl << "tree1 height: " << tree1.treeHeight() << endl;
  cout << "tree1 leaves: " << tree1.treeLeavesCount() << endl;
  cout << "tree2 height: " << tree2.treeHeight() << endl;
  cout << "tree2 leaves: " << tree2.treeLeavesCount() << endl;
  cout << "tree3 height: " << tree3.treeHeight() << endl;
  cout << "tree3 leaves: " << tree3.treeLeavesCount() << endl;

  return 0;
}
