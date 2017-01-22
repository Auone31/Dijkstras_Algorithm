# Dijkstras_Algorithm
C++ Implementation of Dijkstra's Algorithm

#UPDATE: 
1) The program now calculates the shortest_path costs to all vertices within the Graph, prints out the cost to each vertex and also prints out the least cost route to the destination specified by the user. 

2) The program now plots the shortest paths to specified destination vertex.

# Dependencies
Graph.h requires the following:

1 - Python 2.7 (Python.h)

2 - matplotlib

# Description
The code performs the following:

1) Generates and plots a network of uniformly distributed nodes

2) The network moves left to right, with the left most vertex in the graph selected as the source node.
  
3) Cost between two vertices u and v is selected as (dist[u, v])^2, i.e., square of the distance between the two vertices. The cost formula can be changed in Dijkstra.cpp.

4) The code prints out the cost from source vertex to each of the remaining vertices as calculated before and after running Dijkstra's algorithm.

5) The code also prints out the least cost path to the user-specified vertex. Users will be prompted to specify their desired destination vertex by typing the vertex number in the CLI. Users can select one of the vertices shown in the plot generated (See item 1 above in Description).

6) Finally, the code also plots the shortest path to the destination specified by the user (Screenshot.png as an example.).

Any feedback would be highly appreciated!!!

Enjoy!!!
