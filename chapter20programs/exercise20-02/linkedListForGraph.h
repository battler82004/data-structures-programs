#ifndef H_LinkedListForGraph
#define H_LinkedListForGraph

#include <iostream>
#include "linkedList.h"

using namespace std; 

template<class vType>
class linkedListGraph: public linkedListType<vType>
{ 
public:
    void getAdjacentVertices(vType adjacencyList[], 
     				         int& length);
	//Function to retrieve the vertices adjacent to a
	//given vertex. 
	//Postcondition: The vertices adjacent to a given vertex
	//               from the linked list are retrieved in the
	//               array adjacencyList. The parameter length 
	//               specifies the number of vertices adjacent 
	//               to given vertex.
};

// Function to retrieve the vertices adjacent to a given vertex. 
// Untested.
template <class vType>
void linkedListGraph<vType>::getAdjacentVertices(vType adjacencyList[], 
    int& length) {

    // Create iterator to go through each not in adjacent linked list
    linkedListIterator<vType> vLinked(linkedListIterator<vType>::first);
    int pos = 0;

    while (vLinked != nullptr) {
        adjacencyList[pos] = *vLinked; // add vertex to return list
        vLinked++;
        pos++;
    }
    length = pos;
}

#endif
