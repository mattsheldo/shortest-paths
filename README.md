# Shortest Paths Algorithms

I completed this code for my algorithms class. The code compares two different algorithms for calculating the shortest path between any and every node of a graph. The first algorithm is Dijkstra's algorithm and the second algorithm is a dynamic programming approach. The main purpose of this code is compare the run time of the two algorithm's with different sizes of graphs.

## Encoding the Graph Data

For both of the algorithms in this repo I used matrices (2D arrays) to store the graph information. For the matrices the indexes represent the nodes so for example index 0 of the matrix represents the first node and index 1 represents the second node and so on. The edges are the values stored in the matrix and they can be accessed by using two indices. So if you want to find the value of the edge between Node A and Node B you would inspect the value at Matrix[0][1]. The final bit of data encoding in the matrix is how to indicate if there is no edge between two nodes. For the Matrices used in the Dijkstra's algorithm no edge is indicated by a value of 0 in the matrix so if Matrix[0][1] is 0 then that means that Node A and Node B has no edge. For the Dynamic Programming Approach it is the same idea but instead of 0 I used infinity (just a really big number).

## Dijkstra's Algorithm

Dijkstra's algorithm is one of the most famous path finding algorithms but I am still going to give a brief summary of how it works. Dijkstra's works by starting a given source node on the graph then following the edges with the lowest costs to find the fastest route to every other node. For this algorithm I do this process using every node as the source node and replacing any previous paths with new paths if a better (lower cost) path is found.

## Dynamic Programming Approach

Dynamic programming in general is all about breaking down a problem into subproblems where the answers to the subproblems can be used to solve the bigger problem. More specifically we store the subproblem solutions so that we never have to calculate them again if we need them later on. So for calculating shortests paths I use dynamic programming by storing the fastest routes between two specific nodes. The stored shortests paths will help find paths between a different pair of nodes until the entire graph is connected. So for clarification If I find the path from A -> C whenever I look for the shortest path from A -> D I don't have to calculate A -> C again because it is already sotred in the matrix which saves time as more pairs are solved.

## Try it Yourself!

Use Git to clone the repository and run the program. On your machine navigate to your desired folder and run the following command.

```bash
git clone https://github.com/mattsheldo/shortest-paths.git
```

Once you have the repository cloned on your machine you can run the following commands to compile and run the code.

To Compile:
```bash
g++ main.cpp Timer.cpp
```
To Run:
```bash
./a.out
```
