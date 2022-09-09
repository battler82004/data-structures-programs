#ifndef arrayListType_H
#define arrayListType_H

using namespace std;

class arrayListType {
    private:
        int *list, length, maxSize = 100;
        // List is a ptr to the array of nums
    public:
        int* getList() const { return list; }
        // Returns the location list points to
        int getLength() const { return length; }
        // Returns the length of the array
        int getMaxSize() const { return maxSize; }
        // Returns the maximum size of the array
        void remove(int num);
        // Removes the first occurance of num
        void print() const;
        // Prints out the array separated by spaces
        virtual void removeAll(int num) = 0;
        // Removes all the occurances of num
        arrayListType(int nums[100], int len);
        // Constructor
};

#endif
