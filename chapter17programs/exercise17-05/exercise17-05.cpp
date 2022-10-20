/*
  Title: Exercise 17-5 (Matching Grouping Symbols)
  Description: This program takes in an arithmetic expression ended by
    a semicolon. It then checks if the expression has matching grouping
    symbols (parentheses and curly braces).
  Author: James Taddei
  Date: 10/20/22
*/

/*
Ex Inputs:
Valid: {25 + (3 - 6) * 8}
Valid: 7 + 8 * 2
Invalid: 5 + {(13 + 7) / 8 - 2 * 9
*/

#include <iostream>
#include <string>
#include "myStack.h"
using namespace std;

int main() {
  // Variable declaration
  string expr;
  bool isValid = true;
  stackType<char> stack;

  // User input
  cout << "Enter an arithmetic expression follow by a semicolon: ";
  getline(cin, expr, ';');

  // Goes through each char and checks for grouping symbols
  for (unsigned int i = 0; i < expr.length(); i++) {
    if (expr[i] == '{')
      stack.push('{');
    else if (expr[i] == '}') {
      // Checks that the } closes an earlier {
      if (!stack.isEmptyStack() && stack.top() == '{')
        stack.pop();
      // Don't need to check before last becaue need to close (
      // before closing {
      else { // Not closing a {, thus invalid
        isValid = false;
        break;
      }
    }

    else if (expr[i] == '(')
      stack.push('(');
    else if (expr[i] == ')') {
      // Checks that the ) closes an earlier (
      if (!stack.isEmptyStack() && stack.top() == '(')
        stack.pop();
      // Don't need to check for earlier ( because () should be
      // surrounded by {}
      else { // Not closing a (, thus invalid
        isValid = false;
        break;
      }
    }
  }

  if (isValid && stack.isEmptyStack())
    cout << "Expression has matching grouping symbol"  << endl;
  else {
    cout << "Expression does not have matching grouping symbols."
      << endl;
  }

  return 0;
}
