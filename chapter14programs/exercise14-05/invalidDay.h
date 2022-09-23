#ifndef invalidDay_H
#define invalidDay_H

#include <string>
using namespace std;

class invalidDay {
    private:
        string message = "The number of days is invalid. Reenter it: ";
    public:
        string what() { return message; }
};

#endif
