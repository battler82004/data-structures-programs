/*
  Title: Exercise 20-3 (Shortest Dist to Nodes)
  Description: This program takes in a weight digraph from the inputted
    file and outputs the shortest distance from the source to the
    various nodes.
  Author: James Taddei
  Date: 11/18/22
*/

#include <iostream>
#include "weightedGraph.h"
using namespace std;

// To test, enter either "Ch20_Ex3Data.txt" or "dataSet2.txt"

int main() {
  // Variable declaration
  int src = 0;
  weightedGraphType test(50);

  test.createWeightedGraph();

  // Determine and output shortest distances
  test.shortestPath(src);
  test.printShortestDistance(src);

  return 0;
}

// Working, comments
