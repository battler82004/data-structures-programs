#include <iostream>
#include <string>
#include "customer.h"
using namespace std;

// Overloaded stream insertion operator
ostream& operator<<(ostream& os, customerType& cust) {
  os << cust.custAcctNo << " " << cust.firstName << " "
    << cust.lastName << " " << cust.getNoOfRentals() << endl;

  return os;
}

// Output account number, first name, last name, and num of rentals
void customerType::print() {
  cout << custAcctNo << ' ' << firstName << ' ' << lastName << ' ' <<
    getNoOfRentals() << endl;
}

// Sets customrs first name, last name, and account num
void customerType::setCustInfo(string first, string last, int acctNo) {
  firstName = first;
  lastName = last;
  custAcctNo = acctNo;
}

// Rents a video to the customer
void customerType::rentVideo(string title) {
  this->rentedVideoList.push_back(title);
}

//This function returns a video to the customer
void customerType::returnVideo(string title) {
  rentedVideoList.remove(title);
}

// Returns the number of videos rented by the customer
int customerType::getNoOfRentals() {
  return rentedVideoList.size();
}

// Returns the account number of the customer
int customerType::getAcctNo() {
  return custAcctNo;
}

// Prints the list of rented videos
void customerType::printRentedVideo() {
  for (auto vid : rentedVideoList)
    cout << vid << endl;
}

// Constructor with first name, last name, and account number
customerType::customerType(string first, string last, int acctNo) {
  firstName = first;
  lastName = last;
  custAcctNo = acctNo;
}

// Default constructor
customerType::customerType() {
  firstName = "";
  lastName = "";
  custAcctNo = 0;
}

// Overloaded equality operator
bool customerType::operator==(customerType right) {
  return(custAcctNo == right.custAcctNo);
}

// Overloaded inequality operator
bool customerType::operator!=(customerType right) {
  return(custAcctNo != right.custAcctNo);
}

// Overloaded equality operator (for account number)
bool customerType::operator==(int acctNo) {
  return(custAcctNo == acctNo);
}

// Adds a video to the rented video list. (IDK if the method
// is supposed to do this)
void customerType::insert(const string title) {
  rentedVideoList.push_back(title);
}
