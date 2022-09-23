#ifndef invalidHr_H
#define invalidHr_H

#include <string>
using namespace std;

class invalidHr {
    private:
        string message = "The number of hours is invalid.";
    public:
        string what() { return message; }
};

#endif
