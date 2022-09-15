#ifndef cashRegister_H
#define cashRegister_H

#include <iostream>
using namespace std; 
 
class cashRegister
{
    friend ostream& operator<<(ostream&, const cashRegister&);
public:
    int getCurrentBalance() const;
    cashRegister operator+(const cashRegister& cashR);
    cashRegister operator-(const cashRegister& cashR);
    bool operator==(const cashRegister& cashR) const; 
    bool operator!=(const cashRegister& cashR) const; 
    bool operator<=(const cashRegister& cashR) const;
    bool operator<(const cashRegister& cashR) const;
    bool operator>=(const cashRegister& cashR) const;
    bool operator>(const cashRegister& cashR) const;

    cashRegister(int cashIn = 500); 

private:
     int cashOnHand;     //variable to store the cash 
                         //in the register
};

#endif
