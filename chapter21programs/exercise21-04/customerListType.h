#ifndef H_customerListType
#define H_customerListType
 
#include <iostream> 
#include <string>
#include <list> 
#include "customer.h"

using namespace std;

class customerListType 
{
public:
	bool custSearchId(int id);
        // Determines if a customer exists with account number 'id'
	void custReturnVideo(int id, string title);
        // Returns the customer with acount 'id''s copy of the video
	void custRentVideo(int id, string title);
        // Rents a copy of the movie for user 'id'
	int  custGetNoOfRentals(int id);
        // Returns the number of a rentals customer has
	void rentedVideosInfo();
        // Prints every cutomer's ID and their rented videos
	void insert(const customerType&);
        // Apends a new customer to the list
	void print();
        // Prints out each customer and their data
private:
	void searchCust(int id, bool& found,
        list<customerType>::iterator &location);
        // If a user with the inputed id is in the list, found is set
        // to true and 'location' holds the object holding the user.
        // Otherwise, found is set to false.

	list<customerType> custList;
};

#endif
