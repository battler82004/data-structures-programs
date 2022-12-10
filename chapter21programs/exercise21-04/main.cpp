/*
  Title: Exercise 20-4 (Updated Video Rentals)
  Description: This program works as the customer and Video rental
    system for a rentals shop.
  Author: James Taddei
  Date: 12/10/22
*/

#include <iostream>
#include <fstream>
#include <string>
#include "customer.h"
#include "customerListType.h"
#include "videoLinkedListType.h"
#include "videoType.h"
using namespace std;

// Function prototypes
void createVideoList(ifstream& inFile, 
  videoListType& videos);
void displayMenu();

int main() {
  // Variable declaration
  customerListType customers;
  videoListType videos;
  ifstream custFile, inFile;
  int pos, choice, accountNo;
  string title, line, toMakeCust[3];
  customerType cust;
  char discard;

  // Input of customer data from file
  custFile.open("custDat.txt");
  while (getline(custFile, line)) { // for each line
    // Reset for next customer
    pos = 0;
    toMakeCust[0] = "";
    toMakeCust[1] = "";
    toMakeCust[2] = "";
    // Split line at spaces
    for (unsigned int i = 0; i < line.length(); i++) {
      if (line[i] != ' ')
        toMakeCust[pos] += line[i];
      else
        pos++;
    }
    // Create and insert cust
    cust.setCustInfo(toMakeCust[0], toMakeCust[1], stoi(toMakeCust[2]));
    customers.insert(cust);
  }
  custFile.close();

  // Input Video data from file
  inFile.open("videoDat.txt");
  if (!inFile) {
    cout << "The input file does not exist. " <<
      "Program terminates!!" << endl;
    return 1;
  }
  createVideoList(inFile, videos);
  inFile.close();

  // User input
  displayMenu(); //show the menu
  cout << "Enter your choice: ";
  cin >> choice; //get the request
  cin.get(discard); //ignore the remaining characters in the line
  cout << endl;
  while (choice != 9) {
    switch (choice) {
      case 1: 
        cout << "Enter the title: ";
        getline(cin, title);
        cout << endl;
        if (videos.videoSearch(title))
          cout << "The store carries " << title << endl;
        else
          cout << "The store does not carry " << title << endl;
        break; 
      case 2: 
        cout << "Enter the title: ";
        getline(cin, title);
        cout << endl;
        if (videos.videoSearch(title)) {
          if (videos.isVideoAvailable(title)) {
            cout << "Enter customer id: ";
            cin >> accountNo;

            customers.custRentVideo(accountNo, title);
            videos.videoCheckOut(title);
            cout << "Enjoy your movie: " << title << endl;
          }
          else
            cout << "Currently " << title << " is out of stock."
              << endl;
        }
        else
          cout << "The store does not carry " << title << endl;
        break;
      case 3: 
        cout << "Enter the title: ";
        getline(cin, title);
        cout << endl;
        if (videos.videoSearch(title)) {
          cout << "Enter customer id: ";
          cin >> accountNo;
          customers.custReturnVideo(accountNo, title);

          videos.videoCheckIn(title);
          cout << "Thanks for returning " << title << endl;
        }
        else
          cout << "The store does not carry " << title << endl;
        break;
      case 4: 
        cout << "Enter the title: ";
        getline(cin, title);
        cout << endl;
        if (videos.videoSearch(title)) {
          if (videos.isVideoAvailable(title))
            cout << title<<" is currently in " << "stock." << endl;
          else
            cout << title<<" is currently out " << "of stock." << endl;
        }
        else
          cout << "The store does not carry " << title << endl;
        break;
      case 5:
        videos.videoPrintTitle();
        break;
      case 6:
        videos.print();
        break;
      case 7:
        customers.print();
        break;
		  case 8:
        customers.rentedVideosInfo();
        break;
      default: cout << "Invalid selection." << endl;
    } //end switch
    displayMenu(); //display the menu
    cout << "Enter your choice: ";
    cin >> choice; //get the next request
    cin.ignore(100, '\n'); //ignore the remaining characters in the line
    cout << endl;
  } // end while
  // Look at 19-12

  return 0;
}

void createVideoList(ifstream& inFile, 
  videoListType& videos) {
  
  string title, star1, star2, producer, director, productionCo;
  int inStock;
  videoType newVid;

  getline(inFile, title);
  while (inFile) {
    getline(inFile, star1);
    getline(inFile, star2);
    getline(inFile, producer);
    getline(inFile, director);
    getline(inFile, productionCo);
    inFile >> inStock;
    inFile.ignore(100, '\n');
    newVid.setVideoInfo(title, star1, star2, producer,
      director, productionCo, inStock);
    videos.insert(newVid);
    getline(inFile, title);
  } //end while
} //end createVideoList

void displayMenu() {
  cout << "Select one of the following:" << endl;
  cout << "1: To check whether the store carries a "
    << "particular Video." << endl;
  cout << "2: To check out a Video." << endl;
  cout << "3: To check in a Video." << endl;
  cout << "4: To check whether a particular Video is " << "in stock."
    << endl;
  cout << "5: To print only the titles of all the Videos." << endl;
  cout << "6: To print a list of all the Videos." << endl;
  cout << "7: Print a list of customers." << endl;
  cout << "8: Print a list of Videos rented by a customer." << endl;
  cout << "9: To exit" << endl;
}
