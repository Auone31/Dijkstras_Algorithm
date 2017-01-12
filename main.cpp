//
//  main.cpp
//
//  Created by Auon Muhammad Akhtar on 2017-01-01.
//  Copyright © 2017 Auon Muhammad Akhtar. All rights reserved.
//

#include "Python.h"
#include <iostream>
#include "Dijkstra.h"

int main(int argc, const char * argv[])
{
    //Dijkstra myGR(int sg, float md), where sg = size_graph, md = maximum_distance 
    Dijkstra myGR; // <--------- Overloading constructor being used currently
    myGR.draw_graph();
    myGR.Dijkstra_algorithm();
    int dest_vertex;
    while(true)
    {
    	std::cout << "Please enter vertex number to print shortest path or 100 to exit: ";
    	std::cin >> dest_vertex;
    	if (dest_vertex == 100)
    	{
    		break;
    	}
    	else
    	{
    		myGR.get_shortest_path(dest_vertex);
    	}
    }
	return 0;
}
