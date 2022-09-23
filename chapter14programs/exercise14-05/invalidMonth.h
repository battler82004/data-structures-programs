#ifndef invalidMonth_H
#define invalidMonth_H

#include <string>
using namespace std;

class invalidMonth {
    private:
        string message ="The number of months is invalid. Reenter it: ";
    public:
        string what() { return message; }
};

#endif
