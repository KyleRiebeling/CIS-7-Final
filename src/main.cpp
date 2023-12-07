#include <cstdlib>
#include <iostream>

#include "BiMatrixGraph.h"

using namespace std;

int main() {
  //Initialize graph with 4 nodes
  const int NUM_VERTS = 4;
  BiMatrixGraph graph = BiMatrixGraph(NUM_VERTS);

  //initialize key so we don't have to remember indexes
  string key[] = {"Riverside", "Moreno Valley", "Perris", "Hemet"};
  string* keyPtr = key;

  //Set the key for the graph
  graph.setKey(keyPtr);

  //Set all edges with weights
  graph.addWeight("Riverside", "Perris", 24);
  graph.addWeight("Riverside", "Moreno Valley", 16);
  graph.addWeight("Riverside", "Hemet", 33);

  graph.addWeight("Perris", "Moreno Valley", 18);
  graph.addWeight("Perris", "Hemet", 30);

  graph.addWeight("Moreno Valley", "Hemet", 26);

  //Print the created graph that matches the assignment
  cout << "\t\t\tFull Adjacency list" << endl;
  cout << "---------------------------------------------------------------------";
  graph.print();

  //Use depth first search to find quickest connection without back tracking
  cout << "Shortest path between all cities" << endl;
  for (int i = 0; i < NUM_VERTS; i++){
    graph.DFS(i);
  }
  
  cout << endl;

  //Using the prim minimum spanning tree algorithim to find 
  //quickest connection when back tracking is allowed
  graph.primMST();

  return 0;
}
