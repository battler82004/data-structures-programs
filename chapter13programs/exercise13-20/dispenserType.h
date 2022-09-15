#ifndef dispenserType_H
#define dispenserType_H

#include <iostream>
using namespace std;
  
class dispenserType
{
    friend ostream& operator<<(ostream&, const dispenserType&);
public:
    int getNoOfItems() const; 

    int getCost() const; 

    void makeSale();  

    dispenserType operator++();
    dispenserType operator++(int);
    dispenserType operator--();
    dispenserType operator--(int);

    dispenserType(int setNoOfItems = 50, int setCost = 50); 

private:
    int numberOfItems;     //variable to store the number of 
                           //items in the dispenser
    int cost;  //variable to store the cost of an item
};

#endif
