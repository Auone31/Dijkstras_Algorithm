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
*
* IMPORTANT:
*	1) Currently, algorithm only calculates the least costs from source to 
*	every destination.
*	2) Functionality to add to routing table remains to be added 
****************************************************************************/
void Dijkstra::Dijkstra_algorithm(void)
{
	// ------------------------!$!$!$!$!$!$!$!$!$!$!$!$!$------------------------
	//
	// The code within these markers is for adding the routing table. For now the
	// only part being used from this section of the code is the "distances" array
	// which is used later within this fuction.  
	routing_table = new Doubly_LinkedList [size_graph];
	distances = new float [size_graph];
	for (int i = 0; i < size_graph; ++i)
	{
		node * current_node = new node;
		current_node -> number = i;
		if (i == source_node)
		{
			current_node -> cost = 0;
		}
		else
		{
			current_node -> cost = 100000000;
		}
		routing_table[i].push_back(current_node);
		distances[i] = sqrt(pow((vertex_x[i] - vertex_x[source_node]),2) + pow((vertex_y[i] - vertex_y[source_node]),2));
	}
	//
	// ------------------------!$!$!$!$!$!$!$!$!$!$!$!$!$------------------------


	/*****************************************************************************
  	* Sort all the vertices based on their distances from the source vertex.
  	* Calculate and store the cost of each vertex from the source vertex.
  	* IMPORTANT:
  	*	If distance between source u and vertex v is less than 50:
  	*					 cost[u,v] = (dist[u,v])^2
  	*
  	*	If distance between source u and vertex v is greater than 50:           
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
				//cost to that neighbor can be found "costs" vector at the same location. 
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
* Functionality remains to be added, function will plot the shortest path
* from the source_vertex to vertex specified by dest_number. 
*
****************************************************************************/
void Dijkstra::get_shortest_path(int dest_number)
{
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