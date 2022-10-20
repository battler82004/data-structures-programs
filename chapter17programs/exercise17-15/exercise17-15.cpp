/*
  Title: Exercise 17-15 (Palindrome Checker)
  Description: This program takes in a line of text from the user and
    outputs whether or not it is a palindrome which is determined via
    a stack and queue.
  Author: James Taddei
  Date: 10/20/22
*/

#include <iostream>
#include <string>
#include "myStack.h"
#include "queueAsArray.h"
using namespace std;

int main() {
  // Variable declaration
  string line;
  char curr;
  bool isPalindrome = true;
  stackType<char> stack;
  queueType<char> queue;

  // User input
  cout << "Enter the line of text: ";
  getline(cin, line);

  // Adds of the (now lowercase) chars to the stack and queue
  for (unsigned int i = 0; i < line.length(); i++) {
    curr = tolower(line[i]);
    stack.push(curr);
    queue.addQueue(curr);
  }

  // Check that the last in stack equals the first in queue throughout
  for (unsigned int i = 0; i < line.length(); i++) {
    if (stack.top() != queue.front()) {
      isPalindrome = false;
      break;
    }
    // Remove prev chars
    stack.pop();
    queue.deleteQueue();
  }

  // Final output
  if (isPalindrome)
    cout << "The line of text you entered is a palindrome." << endl;
  else
    cout << "The line of text you entered is not a palindrome." << endl;

  return 0;
}
