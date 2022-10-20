/*
  Title: Exercise 15-(1.2) (Recursive Asterisk Generator)
  Description: This program takes a number and outputs double that many
    lines of asterisks through the use of a recursive function.
  Author: James Taddei
  Date: 9/27/22
*/

#include <iostream>
using namespace std;

// Function prototype
void asteriskGenerator(int);
    // This function takes in the total number of asterisks in the first
    // line and then calls 2 recursive functions to ouput the correct num
    // of asterisks
void deAsterisks(int);
    // This funciton outputs the asterisks when the num is decreasing
void inAsterisks(int, int = 1);
    // This function outputs the asterisks when the num is increasing

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
// line and then calls 2 recursive functions to ouput the correct num
// of asterisks
void asteriskGenerator(int numOfAsterisks) {
    deAsterisks(numOfAsterisks);
    inAsterisks(numOfAsterisks);
}

// This funciton outputs the asterisks when the num is decreasing
void deAsterisks(int num) {
    for (int i = 0; i < num; i++) { // Outputs curr line
        cout << '*';
    }
    cout << endl;
    
    if (num != 1) // If general case
        deAsterisks(num-1);
}

// This funciton outputs the asterisks when the num is increasing
void inAsterisks(int max, int curr) {
    for (int i = 0; i < curr; i++) { // Outputs curr line
        cout << '*';
    }
    cout << endl;
    
    if (curr != max) // If general case
        inAsterisks(max, curr+1);
}
