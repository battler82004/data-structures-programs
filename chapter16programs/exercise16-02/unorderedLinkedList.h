#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList  

#include "linkedList.h"
 
using namespace std; 

template <class Type> 
class unorderedLinkedList: public linkedListType<Type>
{
private:
    nodeType<Type> *first = nullptr; // pointer to first node
    nodeType<Type> *last; // pointer to last node
    int count = 0;
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the  
      //               list, and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the 
      //               list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.

    // Functions added by me
    void print() const;
        // This function outputs the linked list's info
    void deleteSmallest();
        // This function removes the first instance of the minimum
        // info value
    void removeAll(const Type& item);
};


template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = first; //set current to point to the first 
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found; 
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == nullptr)   //if the list was empty, newNode is also 
                        //the last node in the list
        last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->link = nullptr;     //set the link field of newNode
                              //to nullptr

    if (first == nullptr)  //if the list is empty, newNode is 
                        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual 
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == nullptr)    //Case 1; the list is empty. 
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2 
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)    //the list has only one node
                last = nullptr;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to 
                                   //the second node

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem) 
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted 
                                       //was the last node
                    last = trailCurrent; //update the value 
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

// This function removes the first instance of the minimum info value
template <class Type>
void unorderedLinkedList<Type>::deleteSmallest() {
    nodeType<Type> *current = first; //pointer to traverse the list
    nodeType<Type> *trailCurrent = first; //pointer just before current
    nodeType<Type> *currMin, *trailCurrMin;
    bool isNotFirstElement = false, changed = false;

    currMin = first;

    while (current != nullptr) {
        if (current->info < currMin->info) { // New min
            currMin = current;
            trailCurrMin = trailCurrent;
            if (isNotFirstElement) // Checks if first must be changed
                changed = true;
        }

        // "Counting"
        trailCurrent = current;
        current = current->link;
        isNotFirstElement = true;
    }

    if (changed) { // Element besides first is smallest
        trailCurrMin->link = currMin->link;
        delete currMin;
    }
    else { // First element is smallest
        first = first->link;
        delete currMin;
    }
    count--;
}

// This function removes all instances of the inputted item
template <class Type>
void unorderedLinkedList<Type>::removeAll(const Type& item) {
    nodeType<Type> *current = first; //pointer to traverse the list
    nodeType<Type> *trailCurrent = first; //pointer just before current
    bool isFirstElement = true;

    while (current != nullptr) {
        if (current->info == item) { // Remove element
            count--;

            if (isFirstElement) { // First element
                first = first->link;
                delete current;
                current = first;
            }
            else { // !1st element
                trailCurrent->link = current->link;

                if (last == current)
                    last = trailCurrent;

                delete current;

                // "Counting"
                current = trailCurrent->link;
                isFirstElement = false;
            }
        }
        else { // Will not be removed
            // "Counting"
            trailCurrent = current;
            current = current->link;
            isFirstElement = false;
        }
    }
}

// This function outputs the linked list's info
template <class Type>
void unorderedLinkedList<Type>::print() const {
    nodeType<Type> *current; //pointer to traverse the list

    current = first;    //set current so that it points to 
                        //the first node
    while (current != nullptr) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }

    cout << endl;
}//end print

#endif
