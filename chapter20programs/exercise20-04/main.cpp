/*
  Title: Exercise 20-4 (Minimal Spanning Tree)
  Description: This program takes in the name of files which it reads
    the graph data from before turning it into and outputting the
    minimal spanning tree.
  Author: James Taddei
  Date: 11/24/22
*/

#include <iostream>
#include "minimalSpanTreeType.h"
using namespace std;

// To test, enter either "Ch20_Ex21Data.txt" or "Ch20_Ex4Data.txt"

int main() {
  msTreeType treeGraph(10); // Variable declaration

  // Create, manipulate, and output graph
  treeGraph.createSpanningGraph();
  treeGraph.minimalSpanning(0);
  treeGraph.printTreeAndWeight();

  return 0;
}
