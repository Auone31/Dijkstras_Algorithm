# Dijkstras_Algorithm
C++ Implementation of Dijkstra's Algorithm

IMPORTANT: Currently, the algorithm only calculates the shortest_path costs to all vertices within the Graph. The functionalities of routing table and plotting of shortest paths to specified nodes will be added soon.

# Dependencies
Graph.h requires the following:

1 - Python 2.7 (Python.h)

2 - matplotlib

# Description
The code performs the following:

1) Generates and plots a network of uniformly distributed nodes

2) The network moves left to right, with the left most vertex in the graph selected as the source node.
  
3) Cost between two vertices u and v is selected as (dist[u, v])^2, i.e., square of the distance between the two vertices. The cost formula can be changed in Dijkstra.cpp.

4) At the end of execution, the code prints out the cost from source vertex to each of the remaining vertices as calculated before and after running Dijkstra's algorithm.

Any feedback would be highly appreciated!!!

Enjoy!!!
