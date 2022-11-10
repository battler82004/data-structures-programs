#ifndef H_customerListType
#define H_customerListType
 
#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include "customer.h"

using namespace std; 

class customerBTreeType:public bSearchTreeType<customerType>
{
public:
	bool custSearchId(int id);
	void custReturnDVD(int id, string title);
	void custRentDVD(int id, string title);
	int  custGetNoOfRentals(int id);

	void rentedDVDsInfo();

private:
	void searchCust(int id, bool& found,
					nodeType<customerType>* &current);

	void inorderRentedDVDInfo(nodeType<customerType>* p);
	// Function to do an inorder traversal and print
	// rented DVD information

};
 
#endif
