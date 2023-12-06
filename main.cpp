#include <cstdlib>
#include <iostream>

#include "BiMatrixGraph.h"

using namespace std;

int main() {
  BiMatrixGraph graph = BiMatrixGraph(4);
  string key[] = {"Riverside", "Moreno Valley", "Perris", "Hemet"};
  string* keyPtr = key;

  graph.setKey(keyPtr);

  graph.addWeight("Riverside", "Perris", 24);
  graph.addWeight("Riverside", "Moreno Valley", 16);
  graph.addWeight("Riverside", "Hemet", 33);

  graph.addWeight("Perris", "Moreno Valley", 18);
  graph.addWeight("Perris", "Hemet", 30);

  graph.addWeight("Moreno Valley", "Hemet", 26);

  graph.print();
  
  graph.primMST(); //NEED TO FIX

  graph.minDistDijk("Hemet");

  return 0;
}
