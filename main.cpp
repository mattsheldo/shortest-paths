#include "Graph.h"
#include "Timer.h"
#include <queue>
#include <limits>

using namespace std;


int MAX = numeric_limits<int>::max();

vector<int> computeShortestPath(Graph g, int node){
  // Dijkstra’s Algorithm
  int v = g.size();
  vector<int> D;
  list<int> adjacent;

  // Initiallizing the results vector
  for(int i = 0; i < v; i++) {
    D.push_back(MAX);
  }
  // Creating the priority queue
  priority_queue<pair<int,int>, vector<pair<int,int> >,  greater<pair<int,int> >> Q;
  // Adding the source node which will always have a distance of 0 to itself
  Q.push(make_pair(0, node));
  D[node] = 0;
  // Keeps looking through the graph until there are no more options left to check
  while(!Q.empty()) {
    // Take the smallest costing edge off the top of the queue to be processed
    int u = Q.top().second;
    Q.pop();
    // Get a list of all adjacent nodes
    adjacent = g.getConnectedNodes(u);
    //Loop through every node in the list of adjacent nodes
    list<int>::iterator i;
    for(i = adjacent.begin(); i != adjacent.end(); i++) {
      int weight = g.getEdgeWeight(u,*i);
      /* If the path between the two nodes its is less weight using the edge that
      was popped of the queue replace the old path with the path that uses the new
      edge.*/
      if(D[*i] > D[u] + weight) {
        D[*i] = D[u] + weight;
        Q.push(make_pair(D[*i], *i));
      }
    }
  }
  return D;
};

vector<vector<int> > computeAllPairsShortestPath(Graph g){
  vector<vector<int> > matrix;
  vector<int> dijktsraResult;
  // Calling Dijkstra's Algorithm on each pair of nodes
  for(int i = 0; i < g.size(); i++) {
    dijktsraResult = computeShortestPath(g, i);
    matrix.push_back(dijktsraResult);
  }
  return matrix;
};

Matrix computeAllPairsShortestPathDynamicProgramming(Graph g){
  // Computing all possible shortest paths by implementing the dynamic programming approach
  vector<vector<int> > matrix(g.size(), vector<int>(g.size()));
  // Initiallizing the matrix based on graph g
  for(int i = 0; i < g.size(); i++) {
    for(int j = 0; j < g.size(); j++) {
      // The distance from a node to itself will always be 0
      if(i == j) {
        matrix[i][j] = 0;
      }
      // If a connection exists from the original graph copy that over to our new matrix
      else if(g.connected(i,j)) {
        matrix[i][j] = g.getEdgeWeight(i,j);
      }
      // If there is no connection add MAX (using MAX was causing me problems so I used 999 instead)
      else {
        matrix[i][j] = 999;
      }
    }
  }

  for(int k = 0; k < g.size(); k++) {
    for(int i = 0; i < g.size(); i++) {
      for(int j = 0; j < g.size(); j++) {
        //if the new path is less weight than the path currently in the matrix replace it
        if(matrix[i][j] > (matrix[i][k] + matrix[k][j])) {
          matrix[i][j] = matrix[i][k] + matrix[k][j];
        }
      }
    }
  }
  return matrix;
};

bool compareResults(Graph g, Matrix a, Matrix b){

  for(int i=0; i<g.size(); i++){
    for(int j=0; j<g.size(); j++){
      if(a[i][j] != b[i][j]){
        return false;
      }
    }
  }

  return true;
}


int main(){

  //create graph as a random matrix
  Graph g(1000,40000);
  cout << "Graph generated " << endl;

  //compute shortest path
  Timer time;
  time.start();
  Matrix a = computeAllPairsShortestPath(g);
  time.stop();
  cout << "Time with Dijkstra's algorithm " << time.getElapsedTimeInSec() << endl;

  //compute all possible shortest paths
  time.start();
  Matrix b = computeAllPairsShortestPathDynamicProgramming(g);
  time.stop();
  cout << "Time with Dynamic programming " << time.getElapsedTimeInSec() << endl;

  //compute by dynamic programming approach
  if(compareResults(g,a,b)){
    cout << "They are the same" << endl;
  }
  else{
    cout << "Different" << endl;
  }

};
