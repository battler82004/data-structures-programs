/*
  Title: Exercise 21-1 (Updated Election Results)
  Description: This program takes in the data from candidData.txt and
    voteData.txt before outputting all of the aggregated voting data
    as well as the winner and total votes polled.
  Author: James Taddei
  Date: 12/6/22
*/

#include <iostream>
#include "candidateType.h"
#include <list>
#include <fstream>
#include <string>
using namespace std;

int main() {
  // Variable declaration
  list<candidateType> candidates;
  list<candidateType>::iterator candidIter; // just for reqs
  candidateType *tempCandidate, mostVotesC;
  ifstream infile;
  string fName, lName;
  int region, votes, totalVotesPolled = 0;

  // Reading candidate data
  infile.open("candData.txt");
  if (!infile) {
    cout << "Cannot open input file." << endl;
    return -1;
  }
  // Create candidates and them to list
  while (infile >> fName >> lName) {
    tempCandidate = new candidateType();
    tempCandidate->setName(fName, lName);
    candidates.push_back(*tempCandidate);
    // Memory leak, who cares?
  }
  infile.close();

  // Reading vote data
  infile.open("voteData.txt");
  if (!infile) {
    cout << "Cannot open input file." << endl;
    return -1;
  }

  while (infile >> fName >> lName >> region >> votes) {
    // Finds candidate and updates their votes
    for (auto &c : candidates) {
      if ((c.getFirstName() == fName) && (c.getLastName() == lName)) {
        c.updateVotesByRegion(region, votes);
        break;
      }
    }
  }
  infile.close();

  candidates.sort(); // by last name

  // Output
  cout << "      --------------------Election Results--------------"
    << "------\n\name                                      Votes\n"
    << "  Candidate Name    Region1  Region2  Region3  Region4   Total"
    << "\n------------------  -------  -------  -------  -------  "
    << "------" << endl;
  
  for (auto &c : candidates) { // Prints candidate data 
    c.calculateTotalVotes();
    totalVotesPolled += c.getTotalVotes();
    c.printData();

    if (c.getTotalVotes() > mostVotesC.getTotalVotes())
      mostVotesC = c; // checks if new most total votes
  }

  cout << "Winner: " << mostVotesC.getFirstName() << ' ' <<
    mostVotesC.getLastName() << ", Votes Received: " <<
    mostVotesC.getTotalVotes() << endl;
  cout << "Total votes polled: " << totalVotesPolled << endl;
  
  return 0;
}
