//**********************************************************
// Author: D.S. Malik
//
// Implementation file dispenserType.cpp 
// This file contains the definitions of the functions to 
// implement the operations of the class dispenserType.
//**********************************************************
 
#include <iostream> 
#include "dispenserType.h"

using namespace std;

int dispenserType::getNoOfItems() const
{
    return numberOfItems;
}

int dispenserType::getCost() const
{
    return cost;
}

dispenserType dispenserType::operator++() {
  numberOfItems++;

  return *this;
}

dispenserType dispenserType::operator++(int u) {
  dispenserType temp = *this;

  numberOfItems++;

  return temp;
}

dispenserType dispenserType::operator--() {
  numberOfItems--;

  return *this;
}

dispenserType dispenserType::operator--(int u) {
  dispenserType temp = *this;

  numberOfItems--;

  return temp;
}

dispenserType::dispenserType(int setNoOfItems, int setCost)
{
    if (setNoOfItems >= 0)
         numberOfItems = setNoOfItems;
    else    
        numberOfItems = 50;

    if (setCost >= 0)
        cost = setCost;
    else
        cost = 50;
}


ostream& operator<<(ostream& os, const dispenserType& disp)
{
    os << "Cost: " << disp.cost << ", quantity " << disp.numberOfItems;

    return os;
}
