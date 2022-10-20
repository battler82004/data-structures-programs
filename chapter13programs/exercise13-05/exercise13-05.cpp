/*
  Title: Exercise 13-5 (Increment Overload)
  Description: This program overloads the increment (both pre and post)
    for the 'newClock' class.
  Author: James Taddei
  Date: 7/8/22
*/

#include <iostream> 
#include "newClock.h" 
using namespace std;

int main()
{
    // Given testing code
    clockType myClock(5, 6, 23);
    clockType yourClock;

    cout << "Line 3: myClock = " << myClock << endl;
    cout << "Line 4: yourClock = " << yourClock << endl;

    cout << "Line 5: Enter time in the form hrs:mins:secs ";
    cin >> myClock;
    cout << "Line 7: New value of myClock = " << myClock << endl;

    ++myClock;

    cout << "Line 9: After increment myClock is " << myClock << endl;

    yourClock.setTime(13, 35, 38);
    cout << "Line 11: Now yourClock = " << yourClock << endl;

    if (myClock == yourClock)
        cout << "Line 13: myClock and yourClock are equal" << endl;
    else
        cout << "Line 15: myClock and yourClock are not equal" << endl;

    if (myClock <= yourClock)
        cout << "Line 17: myClock is less than yourClock" << endl;
    else
        cout << "Line 19: myClock is not less than yourClock" << endl;

    cout << "Line 20: Testing post increment operator" << endl;

    yourClock = myClock++;

    cout << "Line 22: myClock = " << myClock << endl;
    cout << "Line 23: yourClock = " << yourClock << endl;

    return 0;
}
