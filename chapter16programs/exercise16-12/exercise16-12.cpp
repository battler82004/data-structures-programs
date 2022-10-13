/*
  Title: Exercise 16-12 (Doubly Linked List Test)
  Description: This program takes in a list of integers (ended by -999)
    and outputs various aspects of the list partially based on user
    input in order to test the 'doublyLinkedList' class.
  Author: James Taddei
  Date: 10/13/21
*/

// Test data: 83, 121, 98, 23, 57, 33, -999

#include <iostream>
#include "doublyLinkedList.h"
using namespace std;

int main() {
  // Variable declaration
  int num = 0;
  doublyLinkedList<int> list, temp;

  // User input
  cout << "Enter a list of positive integers ending with -999: "
    << endl;
  cin >> num;

  // Keep inputting until -999
  do {
    list.insert(num);
    cin >> num;
  } while (num != -999);

  // Goal 1: output in ascending
  cout << endl << "List in ascending order: ";
  list.print();

  // Goal 2: output in descending
  cout << endl << "List in descending order: ";
  list.reversePrint();

  // Goal 3: delete item
  cout << "\n\nEnter item to be deleted: ";
  cin >> num;
  list.deleteNode(num);
  cout << "List after deleting " << num << " : ";
  list.print();

  // Goal 4: search for item
  cout << "\n\nEnter item to be searched: ";
  cin >> num;
  if (list.search(num)) // Found
    cout << num << " found in the list." << endl;
  else // Not found
    cout << num << " is not in the list." << endl;

  // Goal 5: copy constructor
  cout << endl << "********Testing copy constructor***********" << endl;
  doublyLinkedList<int> intList(list);
  cout << "intList: ";
  intList.print();

  // Goal 6: assignment operator
  cout << endl << "********Testing assignment operator***********"
    << endl;
  temp = list;
  cout << "temp: ";
  temp.print();
  cout << endl;

  return 0;
}
