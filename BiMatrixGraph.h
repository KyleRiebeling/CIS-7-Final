/*
 * File:   BiMatrixGraph.h
 * Author: Kyle
 *
 * Created on June 2, 2023, 10:48 AM
 */

#ifndef BIMATRIXGRAPH_H
#define BIMATRIXGRAPH_H

#include <iomanip>
#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

class BiMatrixGraph {
private:
  int **graph;
  int numVerts;
  string *key;
  bool usingKey = false;

  void printMST(int parent[]) {
    int total = 0;
    if (!usingKey) {
      cout << "     MSP     \n-------------\n";
      cout << "Edge \tWeight" << endl;
      for (int i = 1; i < numVerts; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]];
      }
    } else {
      cout << "\tMSP\n-----------------------\n";
      cout << "Edge \t\tWeight" << endl;
      for (int i = 1; i < numVerts; i++) {
        cout << key[parent[i]] << " - " << key[i] << " \t"
             << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]];
      }
    }

    cout << "Total weight: " << total << endl << endl;
  }

  int minKey(int distance[], bool visited[]) {

    int min = INT_MAX, min_index;

    for (int i = 0; i < numVerts; i++) {
      if (visited[i] == false && distance[i] <= min) {
        min = distance[i], min_index = i;
      }
    }

    return min_index;
  }

public:
  BiMatrixGraph(int verts) {
    numVerts = verts;
    graph = new int *[numVerts];
    for (int i = 0; i < numVerts; i++) {
      graph[i] = new int[numVerts];
      for (int j = 0; j < numVerts; j++) {
        graph[i][j] = 0;
      }
    }
  }

  int getNumVerts() { return numVerts; }

  void setKey(string s[]) {
    key = s;
    usingKey = true;
  }

  void addVertex() {
    graph[numVerts] = new int[numVerts];

    for (int i = 0; i < numVerts + 1; i++) {
      graph[numVerts][i] = 0;
      graph[i][numVerts] = 0;
    }

    numVerts++;
  }

  void delVertex(int v) {
    if (v > numVerts) {
      cout << "Invalid Vertex" << endl;
      return;
    }
    // Shift Up
    for (int i = 0; i < numVerts; i++) {
      for (int j = v; j < numVerts - 1; j++) {
        graph[i][j] = graph[i][j + 1];
      }
    }
    // Shift Left
    for (int i = v; i < numVerts - 1; i++) {
      graph[i] = graph[i + 1];
    }

    numVerts--;
  }

  void addEdge(int x, int y) {
    if (x >= numVerts || y >= numVerts) {
      cout << "Invalid Vertices" << endl;
      return;
    }
    graph[x][y] = 1;
    graph[y][x] = 1;
  }

  void addEdge(string x, string y) {
    int xIndx = 0, yIndx = 0;
    for (int i = 0; i < numVerts; i++) {
      if (key[i] == x)
        xIndx = i;
      if (key[i] == y)
        yIndx = i;
    }
    graph[xIndx][yIndx] = 1;
    graph[yIndx][xIndx] = 1;
  }

  void addWeight(int x, int y, int w) {
    if (x >= numVerts || y >= numVerts) {
      cout << "Invalid Vertices" << endl;
      return;
    }

    graph[x][y] += w;
    graph[y][x] += w;
  }

  void addWeight(string x, string y, int w) {
    int xIndx = 0, yIndx = 0;
    for (int i = 0; i < numVerts; i++) {
      if (key[i] == x)
        xIndx = i;
      if (key[i] == y)
        yIndx = i;
    }

    graph[xIndx][yIndx] += w;
    graph[yIndx][xIndx] += w;
  }

  void deleteEdge(int x, int y) {
    graph[x][y] = 0;
    graph[y][x] = 0;
  }

  void deleteEdge(string x, string y) {
    int xIndx = 0, yIndx = 0;
    for (int i = 0; i < numVerts; i++) {
      if (key[i] == x)
        xIndx = i;
      if (key[i] == y)
        yIndx = i;
    }
    graph[xIndx][yIndx] = 0;
    graph[yIndx][xIndx] = 0;
  }

  void primMST() {
    // Array to store constructed MST
    int *parent = new int[numVerts];

    // Key values used to pick minimum weight edge in cut
    int *distance = new int[numVerts];

    // To represent set of vertices included in MST
    bool *visited = new bool[numVerts];

    // Initialize all keys as INFINITE
    for (int i = 0; i < numVerts; i++) {
      distance[i] = INT_MAX, visited[i] = false;
    }

    // Distance to first vertex to itself is 0
    distance[0] = 0;

    // First node is always root of MST
    parent[0] = -1;

    for (int count = 0; count < numVerts - 1; count++) {

      // Pick the minimum weighted distance to the vertices not visited
      int u = minKey(distance, visited);

      // Add the picked vertex to the visited set
      visited[u] = true;

      for (int v = 0; v < numVerts; v++)

        if (graph[u][v] && visited[v] == false && graph[u][v] < distance[v]) {
          parent[v] = u, distance[v] = graph[u][v];
        }
    }

    // Print the constructed MST
    printMST(parent);
  }

  void minDistDijk(int main) {
    int *distance = new int[numVerts];
    bool *visited = new bool[numVerts];

    for (int i = 0; i < numVerts; i++) {
      distance[i] = INT_MAX;
      visited[i] = false;
    }

    distance[main] = 0; // Distance to itself is 0

    for (int i = 0; i < numVerts; i++) {
      // Find min distance
      int min = minKey(distance, visited);
      visited[min] = true;
      for (int j = 0; j < numVerts; j++) {
        // Update distances to neighboring nodes if needed
        if (!visited[j] && graph[min][j] && distance[min] != INT_MAX &&
            distance[min] + graph[min][j] < distance[j]) {
          distance[j] = distance[min] + graph[min][j];
        }
      }
    }

    cout << "Vertex\t\tDistance from selected vertex" << endl;
    for (int i = 0; i < numVerts; i++) {
      cout << i << "\t\t\t" << distance[i] << endl;
    }
  }

  void minDistDijk(string mainS, string secondK) {
    int *distance = new int[numVerts];
    bool *visited = new bool[numVerts];
    int main;

    for (int i = 0; i < numVerts; i++) {
      if (key[i] == mainS)
        main = i;
    }

    for (int i = 0; i < numVerts; i++) {
      distance[i] = INT_MAX;
      visited[i] = false;
    }

    distance[main] = 0; // Distance to itself is 0

    for (int i = 0; i < numVerts; i++) {
      // Find min distance
      int min = minKey(distance, visited);
      visited[min] = true;
      for (int j = 0; j < numVerts; j++) {
        // Update distances to neighboring nodes if needed
        if (!visited[j] && graph[min][j] && distance[min] != INT_MAX &&
            distance[min] + graph[min][j] < distance[j]) {
          distance[j] = distance[min] + graph[min][j];
        }
      }
    }

    for (int i = 0; i < numVerts; i++) {
      if (key[i] == secondK) {
        cout << key[i] << " is " << distance[i] << " away from " << key[main]
             << endl;
      }
    }
  }

  void print() {
    cout << endl;
    cout << "     ";
    if (!usingKey) {
      for (int i = 0; i < numVerts; i++) {
        cout << setw(4) << right << i << " ";
      }
      cout << endl;
      for (int i = 0; i < numVerts; i++) {
        cout << endl;
        cout << setw(4) << left << i << "    ";
        for (int j = 0; j < numVerts; j++) {
          cout << setw(4) << left << graph[j][i] << " ";
        }
      }
    } else {
      cout << "    ";
      for (int i = 0; i < numVerts; i++) {
        cout << setw(8) << left << key[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < numVerts; i++) {
        cout << endl;
        cout << setw(8) << left << key[i] << " ";
        for (int j = 0; j < numVerts; j++) {
          cout << setw(8) << left << graph[j][i] << " ";
        }
      }
    }
    cout << endl << endl;
  }
};

#endif /* BIMATRIXGRAPH_H */
