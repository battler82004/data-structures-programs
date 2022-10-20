/*
  Title: Exercise 16-13 (Circular Linked List Test)
  Description: This program takes in a list of integers (ended by -999)
    and turns them into a circular linked list that is used for testing
    the class 'circularLinkedList'. Outputs: the list, its length,
    if a number is in the list (inputted by user), the list after
    a num has been deleted (inputted by user), and the end list length.
  Author: James Taddei
  Date: 10/13/22
*/

// Test data: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -999

#include <iostream>
#include "circularLinkedList.h"
using namespace std;

int main() {
  int num = 0;
  circularLinkedList<int> list;

  cout << "Enter number ending with -999: " << endl;
  cin >> num;

  // Keep inputting until -999
  do {
    list.insertNode(num);
    cin >> num;
  } while (num != -999);

  cout << endl << "List 1: ";
  list.print();
  cout << endl << "Length List 1: " << list.length() << endl;

  cout << endl << "Enter the number to be searched: ";
  cin >> num;
  if (list.search(num)) // Found
    cout << num << " found in the list." << endl;
  else // Not found
    cout << num << " not in the list." << endl;

  cout << endl << "Enter the number to be deleted: ";
  cin >> num;
  list.deleteNode(num);
  cout << "After deleting the node, List 1: ";
  list.print();
  
  cout << endl << "Length List 1: " << list.length() << endl;

  return 0;
}
