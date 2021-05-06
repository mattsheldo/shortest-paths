#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

typedef vector<vector<int> > Matrix;

class Graph{

  Matrix graph;

public:
  Graph(int nNodes, int nEdges){
    // This function will generate a random weighted graph given the
    // desired parameters (number of nodes and number of edges)
    srand (time(NULL));

    graph = Matrix(nNodes, vector<int>(nNodes,0));

    for(int i=0; i<nEdges; i++){
      //random weight
      int weight = 0;
      while(weight == 0) weight = rand()%(101);
      int node1, node2;

      do{
        node1 = rand()%(nNodes);
        node2 = rand()%(nNodes);
      }while(node1 == node2 && !connected(node1,node2));

      graph[node1][node2] = graph[node2][node1] = weight;
    }

  }

  int size(){
    // Returns the number of nodes in the graph
    return graph.size();
  }

  list<int> getConnectedNodes(int n){
    // Return a list with the nodes connected to input node
    list<int> conNode;

    for(int i = 0; i < graph[n].size(); i++) {
      if(graph[n][i] != 0) {
        conNode.push_back(i);
      }
    }
    return conNode;
  }

  int getEdgeWeight(int n, int n2){
    // Return the weight assigned to a edge
    return graph[n][n2];
  }

  bool connected(int n, int n2){
    // Return true if the two nodes are connected
    if(graph[n][n2] == 0) {
      return false;
    }
    else{
      return true;
    }
  }

  void print(){
    // I used this for debugging purposes
    for(int i = 0; i < graph.size(); i++) {
      for(int j = 0; j < graph.size(); j++) {
        cout << graph[i][j] << ",\t";
      }
      cout << endl;
    }
    cout << endl;
  }

};
