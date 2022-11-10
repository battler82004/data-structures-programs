#include <iostream>

#include "customerBinaryTree.h"

using namespace std;
 
bool customerBTreeType::custSearchId(int id)
{
	bool found;
	nodeType<customerType> *current;

	searchCust(id, found, current);

	return found; 
}    
 
void customerBTreeType::custReturnDVD(int id, string title)
{
	bool found;
	nodeType<customerType> *current;

	searchCust(id, found, current);
	current->info.returnDVD(title);
}

void customerBTreeType::custRentDVD(int id, string title)
{
	bool found;
	nodeType<customerType> *current;

	searchCust(id, found, current);
	current->info.rentDVD(title);
}

int customerBTreeType::custGetNoOfRentals(int id)
{
	bool found;
	nodeType<customerType> *current;

	searchCust(id, found, current);

	return current->info.getNoOfRentals();
}


void customerBTreeType::searchCust(int id, bool& found,
						           nodeType<customerType>* &current)
{
	found = false;   //set found to false
   
	current = nullptr;

   if (root == nullptr)  // list is empty
      cout<<"Cannot search an empty list. "<<endl;
   else
   {
		current = root;  // set current point to root node of the tree
		found = false;       // set found to false

		while (!found && current != nullptr) //search the tree
			if (current->info.getAcctNo() == id)   //item is found
       			found = true;
			else
				if (current->info.getAcctNo() > id)
					current = current->lLink;
				else
					current = current->rLink;
	} //end else
}

void customerBTreeType::rentedDVDsInfo()
{
	cout<<"         ######## Rented DVD Info ########" << endl << endl;
	
	inorderRentedDVDInfo(root);
}

void customerBTreeType::inorderRentedDVDInfo(nodeType<customerType>* p)
{
	if (p != nullptr)
	{
		inorderRentedDVDInfo(p->lLink);
		if (p->info.getNoOfRentals() > 0)
		{
			cout << "Customer ID: " << p->info.getAcctNo() << endl;
			cout << "DVDs Rented: ";
			p->info.printRentedDVD();
			cout << "*****************" << endl << endl;
		}
		inorderRentedDVDInfo(p->rLink);
	}
} 
