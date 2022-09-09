#ifndef unorderedArrayListType_H
#define unorderedArrayListType_H

#include "arrayListType.h"
using namespace std;

class unorderedArrayListType: public arrayListType {
    public:
        bool isInList(int num);
        // Returns the bool for if num is in the array
        void removeAll(int num);
        // Removes all instances of num from the array
        unorderedArrayListType(int nums[8], int len);
        // Constructor
};

#endif
