/*
  Title: Exercise 19-12 (DVD Rentals)
  Description: This program works as the customer and DVD system for
    a DVD rentals shop. Most of the program was pre-written, but
    several aspects (including customer management) were added.
  Author: James Taddei
  Date: 11/10/22
*/

//*************************************************************
// Author: D.S. Malik
//
// This program uses the classes dvdType and dvdBinaryTree
// to create a list of DVDs for a DVD store. It performs
// basic operations such as check in and check out DVDs.
//*************************************************************
 
#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
#include "dvdType.h"
#include "dvdBinaryTree.h"
#include "customerBinaryTree.h"
using namespace std;

// Function prototpyes
void createDVDList(ifstream& infile, 
                   dvdBinaryTree& dvdList);
void displayMenu();

int main()
{
    // Variable declaration
    dvdBinaryTree dvdList;
    int choice, pos, accountNo;
    char discard;
    string title, line, toMakeCust[3];
    ifstream infile, custFile;
    customerType cust;
    customerBTreeType custTree;

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
      cust.setCustInfo(toMakeCust[0], toMakeCust[1],
        stoi(toMakeCust[2]));
      custTree.insert(cust);
    }

    // Input DVD data from file
    infile.open("dvdDat.txt");
    if (!infile)
    {
         cout << "The input file does not exist. " 
              << "Program terminates!!" << endl;
         return 1;
    }
    createDVDList(infile, dvdList);
    infile.close();

    // User input
    displayMenu(); //show the menu
    cout << "Enter your choice: ";
    cin >> choice; //get the request
    cin.get(discard); //ignore the remaining characters in the line
    cout << endl;
    while (choice != 9)
    {
         switch (choice)
         {
         case 1: 
             cout << "Enter the title: ";
             getline(cin, title);
             cout << endl;
             if (dvdList.dvdSearch(title))
                 cout << "The store carries " << title << endl;
             else
                 cout << "The store does not carry " << title
                      << endl;
             break; 
         case 2: 
             cout << "Enter the title: ";
             getline(cin, title);
             cout << endl;
             if (dvdList.dvdSearch(title))
             {
                 if (dvdList.isDVDAvailable(title))
                 {
                     cout << "Enter customer id: ";
                     cin >> accountNo;

                     custTree.custRentDVD(accountNo, title);
                     dvdList.dvdCheckOut(title);
                     cout << "Enjoy your movie: " << title
                          << endl;
                 }
                 else
                     cout << "Currently " << title
                          << " is out of stock." << endl;
             }
             else
                  cout << "The store does not carry " << title
                       << endl;
             break;
         case 3: 
             cout << "Enter the title: ";
             getline(cin, title);
             cout << endl;
             if (dvdList.dvdSearch(title))
             {
                 cout << "Enter customer id: ";
                 cin >> accountNo;
                 custTree.custReturnDVD(accountNo, title);

                 dvdList.dvdCheckIn(title);
                 cout << "Thanks for returning " << title
                      << endl;
             }
             else
                 cout << "The store does not carry " << title
                      << endl;
             break;
         case 4: 
             cout << "Enter the title: ";
             getline(cin, title);
             cout << endl;
             if (dvdList.dvdSearch(title))
             {
                 if (dvdList.isDVDAvailable(title))
                     cout << title<<" is currently in "
                          << "stock." << endl;
                 else
                     cout << title<<" is currently out "
                          << "of stock." << endl;
             }
             else
                 cout << "The store does not carry " << title
                      << endl;
             break;
         case 5:
             dvdList.dvdPrintTitle();
             break;
         case 6:
             dvdList.inorderTraversal();
             break;
         case 7:
            custTree.inorderTraversal();
            break;
		     case 8:
            custTree.rentedDVDsInfo();
            break;
         default: cout << "Invalid selection." << endl;
         } //end switch
         displayMenu();          //display the menu
         cout << "Enter your choice: ";
         cin >> choice;          //get the next request
         cin.ignore(100, '\n');  //ignore the remaining
                                 //characters in the line
         cout << endl;
    } //end while
    return 0;
}

void createDVDList(ifstream& infile, 
                   dvdBinaryTree& dvdList)
{
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    int inStock;
 
    dvdType newDVD;
    getline(infile, title);
    while (infile)
    {
         getline(infile, star1);
         getline(infile, star2);
         getline(infile, producer);
         getline(infile, director);
         getline(infile, productionCo);
         infile >> inStock;
         infile.ignore(100, '\n');
         newDVD.setDVDInfo(title, star1, star2, producer,
                           director, productionCo, inStock);
         dvdList.insert(newDVD);
         getline(infile, title);
    } //end while
} //end createDVDList

void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: To check whether the store carries a "
         << "particular DVD." << endl;
    cout << "2: To check out a DVD." << endl;
    cout << "3: To check in a DVD." << endl;
    cout << "4: To check whether a particular DVD is " 
         << "in stock." << endl;
    cout << "5: To print only the titles of all the DVDs."
         << endl;
    cout << "6: To print a list of all the DVDs." << endl;
    cout << "7: Print a list of customers." << endl;
    cout << "8: Print a list of DVDs rented by a customer." << endl;
    cout << "9: To exit" << endl;
}
