/*
  Title: Exercise 15-13 (Ackermann's Function)
  Description: This program implements a recursive Ackermann's Function
    and outputs 4 different values created by different calls.
  Author: James Taddei
  Date: 9/29/22
*/

#include <iostream>
using namespace std;

// Function prototypes
int Ackermann(int, int);
  // This function implements Ackermann's function

int main() {
  cout << "Ackermann(0,0): " << Ackermann(0,0) << endl;
  cout << "Ackermann(0,1): " << Ackermann(0,1) << endl;
  cout << "Ackermann(1,1): " << Ackermann(1,1) << endl;
  cout << "Ackermann(3,2): " << Ackermann(3,2) << endl;

  return 0;
}

// This function implements Ackermann's function
int Ackermann(int m, int n) {
  if (m == 0) // base case
    return n+1;
  else if (n == 0)
    return Ackermann(m-1,1);
  else
    return Ackermann(m-1, Ackermann(m,n-1));
}

/*
A(m,n) = {
  if m = 0: n+1
  else if n = 0: A(m-1,1)
  else: A(m-1, A(m,n-1))
}
*/
