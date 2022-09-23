#ifndef invalidMin_H
#define invalidMin_H

#include <string>
using namespace std;

class invalidMin {
    private:
        string message = "The number of minutes is invalid.";
    public:
        string what() { return message; }
};

#endif
