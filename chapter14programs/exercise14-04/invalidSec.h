#ifndef invalidSec_H
#define invalidSec_H

#include <string>
using namespace std;

class invalidSec {
    private:
        string message = "The number of seconds is invalid.";
    public:
        string what() { return message; }
};

#endif
