/*
  Title: Exercise 12-2 (Dynamic Test Grader)
  Description: This program takes in the file of data and takes the
    first line as the key. From there, it uses that key to grade
    more tests before outputting each students answers followed by
    their percentage and letter grade.
  Author: James Taddei
  Date: 7/7/22
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function prototypes
void splitStudentData(string, string*);
  // Finds the student's ID and answers and stores them
void gradeStudent(string, string*);
  // Finds the number of points the student earns and grades them with
  // a number and letter grade based on this
void printStudentData(string *currStudent);
  // Outputs the ID, answers, number grade, and letter grade for the
  // inputted student

// Named constants
const int NUM_OF_QUESTIONS = 20;

int main() {
  // Variable declaration
  string key, studentRaw, *currStudent;
  ifstream testData("Ch12_Ex2Data.txt"); // Creates the in file

  getline(testData, key);
  cout << "Key: " << key << endl;

  do { // Goes through each line in the file (each student) and
    // grades them

    // Creates a new array to hold the student's data
    currStudent = new string[4];

    getline(testData, studentRaw);
    splitStudentData(studentRaw, currStudent);
    gradeStudent(key, currStudent);

    if (!testData.eof()) { // Doesn't print if this is the last line
      printStudentData(currStudent);
    }

    delete[] currStudent; // Delete the currStudent array
  } while (!testData.eof());

  testData.close();

  return 0;
}

// Finds the student's ID and answers and stores them
void splitStudentData(string student, string *currStudent) {
  bool isOnSID = true;

  for (unsigned int i = 0; i < student.length(); i++) {
    if (isOnSID) { // Creates the student ID
      if (student[i] == ' ') { // Goes until the first space
        isOnSID = false;
        continue;
      }
      currStudent[0] += student[i];
    }
    else { // Adds to the student's answers
      currStudent[1] += student[i];
    }
  }

  for (int i = 0; i < NUM_OF_QUESTIONS; i++) { // Fill-in missing
  //ending spaces
    if (!currStudent[1][i]) {
      currStudent[1] += ' ';
    }
  }

  return;
}

// Finds the number of points the student earns and grades them with
// a number and letter grade based on this
void gradeStudent(string key, string *currStudent) {
  int grade = 0;

  for (int q = 0; q < NUM_OF_QUESTIONS; q++) {
    if (currStudent[1][q] == ' ') { // Space = 0 points
      continue;
    }
    if (key[q] == currStudent[1][q]) { // Correct answer = +2 points
      grade += 2; 
    }
    else {
      grade -= 1; // Wrong answer = -1 points
    }
  }

  currStudent[2] = to_string(grade); // Stores the number of points
  grade *= 2.5; // Multiplyer cause only 40 possible points

  if (grade >= 90) {
    currStudent[3] = 'A';
  }
  else if (grade >= 80) {
    currStudent[3] = 'B';
  }
  else if (grade >= 70) {
    currStudent[3] = 'C';
  }
  else if (grade >= 60) {
    currStudent[3] = 'D';
  }
  else {
    currStudent[3] = 'F';
  }

  return;
}

// Outputs the ID, answers, number grade, and letter grade for the
// inputted student
void printStudentData(string *currStudent) {
  cout << currStudent[0] + ' ' + currStudent[1] + " " + currStudent[2]
    << ' ' << currStudent[3] << endl;
  
  return;
}
