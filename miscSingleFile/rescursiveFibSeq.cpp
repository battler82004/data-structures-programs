// Recursive Fibbonacci Sequence
// James Taddei
// 9/29/22

#include <iostream>
using namespace std;

// Function prototypes
void fibSeq(int, int = 0, int = 1);
    // This function outputs the first n nums in the fibbonacci sequnce

int main() {
    int n;
    
    // User input
    cout << "N = ";
    cin >> n;
    
    // Output
    cout << "Fibbonacci Sequence to " << n << " numbers: " << endl;
    fibSeq(n);

    return 0;
}

// This function outputs the first n nums in the fibbonacci sequnce
void fibSeq(int n, int a, int b) {
    if (a == 0) { // First run
        cout << 0 << endl << 1 << endl;
        n -= 2; // already have 0 and 1
    }
    
    int c = a+b;
    cout << c << endl;
    
    if (n != 1) // Base case
        fibSeq(n-1,b,c);
}
