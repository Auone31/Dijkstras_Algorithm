//
//  Dijkstra.cpp
//
//  Created by Auon Muhammad Akhtar on 2017-01-01.
//  Copyright © 2017 Auon Muhammad Akhtar. All rights reserved.
//
#include "Dijkstra.h"


/****************************************************************************
* Overloading Constructor()
*****************************************************************************
*
*  
*
****************************************************************************/
Dijkstra::Dijkstra()
{
}


/****************************************************************************
* Constructor()
*****************************************************************************
*
*  
*
****************************************************************************/
Dijkstra::Dijkstra(int sg, float md) : Graph(sg, md)
{
}


/****************************************************************************
* Function: Dijkstra_algorithm(void)
*****************************************************************************
*
* Finds the shortest cost path from source vertex to every destination vertex
* Prints out the cost to each vertex and saves the least cost path to each 
* destination
****************************************************************************/
void Dijkstra::Dijkstra_algorithm(void)
{
	// Initializaing the routing table. and saving distances between the source
	// vertex and each of the destination vertices in an array  
	routing_table = new Doubly_LinkedList [size_graph];
	distances = new float [size_graph];
	for (int i = 0; i < size_graph; ++i)
	{
		node * current_node = new node;
		current_node -> number = i;
		routing_table[i].push_back(current_node);
		distances[i] = sqrt(pow((vertex_x[i] - vertex_x[source_node]),2) + pow((vertex_y[i] - vertex_y[source_node]),2));
	}



	/*****************************************************************************
  	* Sort all the vertices based on their distances from the source vertex.
  	* Calculate and store the cost of each vertex from the source vertex.
  	* IMPORTANT:
  	*	If distance between source u and vertex v is less than "max_distance":
  	*					 cost[u,v] = (dist[u,v])^2
  	*
  	*	If distance between source u and vertex v is greater than "max_distance":           
  	*                    cost[u,v] = Infinity (1000000)
  	*****************************************************************************/	
	for (int i = 0; i < size_graph; ++i)
	{
		next_nearest_node = 0;
		for (int j = 1; j < size_graph; ++j)
		{
			if (distances[j] < distances[next_nearest_node])
			{
				next_nearest_node = j;
			}
		}
		sorted_vertices.push_back(next_nearest_node);
		if (distances[next_nearest_node] <= max_distance)
		{
			costs.push_back(pow(distances[next_nearest_node], 2));
		}
		else
		{
			costs.push_back(1000000);
		}
		distances[next_nearest_node] = 1000000;
	}


	/*****************************************************************************
  	* Print out the vertex numbers and their costs from the source vertex (Before)
  	* running Dijkstra's
  	*****************************************************************************/
	std::cout << "Vertex number and cost from the source BEFORE Dijkstra's Algorithm" << std::endl;
	std::cout << "Cost" << "-->" << "Vertex" << std::endl;
	for (int i = 0; i < size_graph; ++i)
	{
		std::cout << costs[i] << " --> " << sorted_vertices[i] << std::endl;
	}


	/*****************************************************************************
  	* Dijkstra's Algorithm starts here
  	*****************************************************************************/
	current_vertex = source_node;
	visited.push_back(source_node);
	while(visited.size() < size_graph)
	{
		current_vertex = sorted_vertices[visited.size()];

		for(unsigned int i = 0; i < neighbor_table[current_vertex].size(); ++i)
		{
			visited_vertex = false;
			for (unsigned int j = 0; j < visited.size(); ++j)
			{
				// If current neighbor is already a visited neighbor
				if (visited[j] == neighbor_table[current_vertex][i])
				{
					visited_vertex = true;
				}
			}
			if (!visited_vertex)
			{
				cost = sqrt(pow((vertex_x[current_vertex] - vertex_x[neighbor_table[current_vertex][i]]),2) + 
					pow((vertex_y[current_vertex] - vertex_y[neighbor_table[current_vertex][i]]),2));
				cost = pow(cost, 2);


				//Find the location of the current neighbor within "sorted_vertices". The current 
				//cost to that neighbor can be found in the "costs" vector at the same location. 
				for (int k = 0; k < size_graph; ++k)
				{
					if (sorted_vertices[k] == neighbor_table[current_vertex][i])
					{
						neighbor_location = k;
						break;
					}
				}
				if (costs[neighbor_location] > costs[visited.size()] + cost)
				{
					costs[neighbor_location] = costs[visited.size()] + cost;

					//Remove the previous best path to the current neighbor. The "if" condition checks if
					//there are nodes already added to the routing table for the current neighbor
					if (routing_table[neighbor_table[current_vertex][i]].get_length() > 1)
					{
						int table_length = routing_table[neighbor_table[current_vertex][i]].get_length();
						for (int l = 1; l < table_length; ++l)
						{
							routing_table[neighbor_table[current_vertex][i]].remove(1);
						}
					}

					// Add the new best path to the routing table
					for (int m = 1; m <= routing_table[current_vertex].get_length(); ++m)
					{
						int vertex_number;
						routing_table[current_vertex].get_node(m, vertex_number);
						node * vertex = new node;
						vertex -> number = vertex_number;
						routing_table[neighbor_table[current_vertex][i]].insert_node(vertex, m);
					} 
				}
			}
		}
		visited.push_back(current_vertex);
	}


	/*****************************************************************************
  	* Print out the vertex numbers and their costs from the source vertex (After)
  	* running Dijkstra's
  	*****************************************************************************/
	std::cout << "Vertex number and cost from the source AFTER Dijkstra's Algorithm" << std::endl;
	std::cout << "Cost" << "-->" << "Vertex" << std::endl;
	for (int i = 0; i < size_graph; ++i)
	{
		std::cout << costs[i] << " --> " << sorted_vertices[i] << std::endl;
	}
}


/****************************************************************************
* Function: get_shortest_path(int dest_number)
*****************************************************************************
*
* Prints out the shortest path from source to destination "dest_number"
*
* ADDITIONAL FEATURES THAT WILL BE ADDED:
* Function will eventually plot the shortest path from the source_vertex to 
* the vertex specified by dest_number. 
*
****************************************************************************/
void Dijkstra::get_shortest_path(int dest_number)
{
	std::cout << source_node;
	routing_table[dest_number].printout();
}


/****************************************************************************
* Destructor()
*****************************************************************************
*
*  
*
****************************************************************************/
Dijkstra::~Dijkstra()
{
	delete distances;
}