#include <list>
#include "customerListType.h"
using namespace std;

// Determines if a customer exists with account number 'id'
bool customerListType::custSearchId(int id) {
  bool found;
  list<customerType>::iterator location;

  location = custList.begin();
  searchCust(id, found, location);

	return found;
}

// Returns the customer with acount 'id''s copy of the video
void customerListType::custReturnVideo(int id, string title) {
  bool found;
  list<customerType>::iterator location;

  // Find customer in the list
  location = custList.begin();
  searchCust(id, found, location);

  location->returnVideo(title);
}

// Rents a copy of the movie for user 'id'
void customerListType::custRentVideo(int id, string title) {
  bool found;
  list<customerType>::iterator location;

  // Find customer in the list
  location = custList.begin();
  searchCust(id, found, location);

  location->rentVideo(title);
}

// Returns the number of a rentals customer has
int customerListType::custGetNoOfRentals(int id) {
  bool found;
  list<customerType>::iterator location;

  // Find customer in the list
  location = custList.begin();
  searchCust(id, found, location);

  return location->getNoOfRentals();
}

// Prints every cutomer's ID and their rented videos
void customerListType::rentedVideosInfo() {
  cout << "######## Rented Video Info ########" << endl;
  for (auto cust : custList) {
    if (cust.getNoOfRentals() > 0) {
      cout << "Customer ID: " << cust.getAcctNo() << endl
        << "Number of Rentals: " << cust.getNoOfRentals() << endl
        << "Videos Rented: ";
      cust.printRentedVideo();
      cout << "*****************" << endl << endl;
    }
  }
}

// Apends a new customer to the list
void customerListType::insert(const customerType& cust) {
  custList.push_back(cust);
}

// Prints out each customer and their data
void customerListType::print() {
  for (auto cust : custList) {
    cust.print();
  }
}

// If a user with the inputed id is in the list, found is set to true
// and 'location' holds the object holding the user. Otherwise, found
// is set to false
void customerListType::searchCust(int id, bool& found,
  list<customerType>::iterator &location) {

  found = false;
  // Uses the iterator 'location' to go throuhg each customer and see
  // if their account number matches the inputted id. If it does, the
  // function stops with location still set to that element.
  for (; location != custList.end(); location++) {
    if (location->getAcctNo() == id) {
      found = true;
      return;
    }
  }
}
