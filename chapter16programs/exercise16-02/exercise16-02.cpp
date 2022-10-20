/*
  Title: Exercise 16-2 (deleteSmallest and removeAll Linked List)
  Description: This program adds and tests the functions deleteSmallest
    and removeAll to the 'unorderedLinkedList' class.
  Author: James Taddei
  Date: 10/6/22
*/

#include <iostream>
#include "linkedList.h"
#include "unorderedLinkedList.h"
using namespace std;

int main() {
  unorderedLinkedList<int> testList;
  testList.insertLast(13);
  testList.insertLast(14);
  testList.insertLast(17);
  testList.insertLast(14);
  testList.insertLast(33);

  testList.print();
  testList.deleteSmallest();
  testList.print();
  testList.removeAll(14);
  testList.print();

  cout << "Test" << endl;

  return 0;
}
