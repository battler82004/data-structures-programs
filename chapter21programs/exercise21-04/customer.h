#ifndef H_customerType 
#define H_customerType
 
#include <iostream> 
#include <list>
#include "personType.h"
#include <string>

using namespace std;

class customerType: public personType 
{
   friend ostream& operator<<(ostream& os, customerType& cust);
	  // overload stream insertion operator
public:
	void print();
	  //Output account number, first name, last name, and 
	  //number of rentals, in the form:
	  //acctNo firstName lastName noOfRentals
	void setCustInfo(string first, string last, int acctNo);
	  //Set firstName, lastName, and account number according 
      //to the parameters
	  //firstName = first; lastName = last; 
	void rentVideo(string);
	  //This function rents a video to the customer
	void returnVideo(string);
	  //This function renturns a video to the customer
	int getNoOfRentals();
	  //This function returns the number of
	  //videos rented by the customer.
	int getAcctNo();
	  //This function returns the account number of
	  //the customer.
	void printRentedVideo();
      // Prints the list of rented videos
	customerType(string first, string last, int acctNo);
	  //constructor with parameters
	  //set firstName and lastName according to the parameters
	  //firstName = first; lastName = last;
  	customerType(); 
  	  //Default constructor;
  	  //intialize firstName and lastName, and custAcctNo 
  	  //Postcondition: firstName = ""; lastName = "";
	  //		          custAcctNo = 0;
	bool operator==(customerType);
      // Overloaded equality operator
	bool operator!=(customerType);
      // Overloaded inequality operator
	bool operator==(int);
      // Overloaded equality operator (for account number)
	void insert(const string title);
      // Adds a video to the rented video list. (IDK if the method
      // is supposed to do this)

private:
	int custAcctNo; //store account number
	list<string> rentedVideoList;
};

#endif 
