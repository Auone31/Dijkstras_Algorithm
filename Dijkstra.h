//
//  Dijkstra.h
//
//  Created by Auon Muhammad Akhtar on 2017-01-01.
//  Copyright © 2017 Auon Muhammad Akhtar. All rights reserved.
//
#ifndef Dijkstra_h
#define Dijkstra_h
#include "Graph.h"
#include "Doubly_LinkedList.h"


class Dijkstra : public Graph
{
	

	Doubly_LinkedList * routing_table;//Will store the routing table
	std::vector<int> visited;//Vector contains the list of visited vertices
	std::vector<int> sorted_vertices;// Vector contains list of vertices sorted by their distance from the source vertex
	std::vector<float> costs;//Vector stores costs of all vertices from the source vertex in ascending order
	float * distances;//Points to an array of floats representing the distances between the source vertex and all other vertices
	int next_nearest_node;//Temporary variable used to store the location of next nearest vertex when preparing sorted_vertices
	bool visited_vertex;//Used in Dijkstra's algorithm to check whether a certain node is a visited node
	float cost;//Used in Dijkstra's algorithm for calculating the costs between two vertices
	int current_vertex;//Used in Dijsktra's algorithm to store the vertex currently being used to calculate costs to other neighbors
	int neighbor_location;//Used in Dijsktra's algorithm to obtain the location of given vertex within sorted_vertices


public:


	/*****************************************************************************
 	* Overloading Constructor
	*****************************************************************************/
	Dijkstra();


	/*****************************************************************************
 	* Constructor
	*****************************************************************************/
	Dijkstra(int, float);


	/*****************************************************************************
 	* Destructor
	*****************************************************************************/
	~Dijkstra();


	/*****************************************************************************
 	* Finds the shortest cost path from source vertex to every destination vertex
	*****************************************************************************/
	void Dijkstra_algorithm(void);


	/*****************************************************************************
 	* Plot the shortest path from the source_vertex to vertex specified by 
 	* dest_number. 
	*****************************************************************************/
	void get_shortest_path(int dest_number);
};


#endif