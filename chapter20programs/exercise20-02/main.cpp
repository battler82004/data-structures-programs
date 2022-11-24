/*
  Title: Exercise 20-2 (Creating Graphs + Adjcaent Vertices)
  Description: This program creates a graph based on the inputted data
    file. It then outputs this graph depth first. The program also adds
    the 'getAdjacentVertices' method. 
  Author: James Taddei
  Date: 11/17/22
*/

#include <iostream>
#include <string>
#include "graphType.h"
using namespace std;

// To test, enter either "Ch20_Ex2Data.txt" or "Ch20_Ex14Data.txt"

int main() {
  // Variable declaration
  graphType test(100);

  // Creating and outputting graph
  test.createGraph();
  test.breadthFirstTraversal();
  
  return 0;
}
