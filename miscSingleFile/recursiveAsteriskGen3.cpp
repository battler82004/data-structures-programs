/*
  Title: Exercise 15-(1.3) (Recursive Asterisk Generator)
  Description: This program takes a number and outputs double that many
    lines of asterisks through the use of a recursive function.
  Author: James Taddei
  Date: 9/29/21
*/

#include <iostream>
using namespace std;

// Function prototype
void asteriskGenerator(int);
    // This function takes in the total number of asterisks in the first
    // line and then calls itself to output the correct num of asterisks

int main() {
    // Variable declaration
    int numOfLines;

    // User input
    cout << "Enter the number of lines: ";
    cin >> numOfLines;

    asteriskGenerator(numOfLines); // Output

    return 0;
}

// This function takes in the total number of asterisks in the first
// line and then calls itself to output the correct num of asterisks
void asteriskGenerator(int numOfAsterisks) {
    // Top stars (output this num while decreasing)
    for (int i = 0; i < numOfAsterisks; i++)
        cout << '*';
    cout << endl;
    
    // All stars in between
    if (numOfAsterisks != 1)
        asteriskGenerator(numOfAsterisks-1);
    
    // Bottom stars (output this num while increasing)
    for (int i = 0; i < numOfAsterisks; i++)
        cout << '*';
    cout << endl;
}
/*
Each run of function will output the curr number of stars, call itself
to output the stars when num < curr but >=1, and then output the curr
number of stars again. This means that the specific number of stars is
only handled by one call.
*/
