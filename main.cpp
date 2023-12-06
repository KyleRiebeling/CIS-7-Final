/*
 * File:   main.cpp
 * Author: Kyle
 *
 * Created on June 2, 2023, 10:46 AM
 */

#include <cstdlib>
#include <iostream>

#include "BiMatrixGraph.h"

using namespace std;

int main() {
  srand(time(0));
  BiMatrixGraph graph = BiMatrixGraph(5);

  graph.print();

  for (int i = 0; i < 50; i++) {
    graph.addWeight(rand() % 5, rand() % 5, rand() % 5 + 1);
  }

  graph.print();

  graph.addVertex();

  graph.print();

  graph.addEdge(1, 5);

  graph.addWeight(5, 4, 2);

  graph.print();

  graph.delVertex(2);

  graph.print();

  string* key = new string[graph.getNumVerts()];
  key[0] = "First";
  key[1] = "Second";
  key[2] = "Third"; 
  key[3] = "Fourth";
  key[4] =  "Fifth";
  
  graph.setKey(key);

  graph.print();

  graph.primMST();

  graph.minDistDijk(3);

  return 0;
}
