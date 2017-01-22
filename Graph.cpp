//
//  Graph.cpp
//
//  Created by Auon Muhammad Akhtar on 2017-01-01.
//  Copyright © 2017 Auon Muhammad Akhtar. All rights reserved.
//
#include "Graph.h"


/****************************************************************************
* Overloading Constructor
*****************************************************************************
*
* Sets a network with 20 nodes which are uniformly distributed
*
****************************************************************************/
Graph::Graph()
{
    size_graph = 20;
    max_distance = 50;
}


/****************************************************************************
* Constructor
*****************************************************************************
*
* Sets a network with user specified number of nodes which are uniformly 
* distributed 
*
****************************************************************************/
Graph::Graph(int sg, float md)
{
    size_graph = sg;
    max_distance = md;
}


/****************************************************************************
* Function: draw_graph()
*****************************************************************************
*
* Generates and draws the graph showing all vertices and edges. Invokes Python 
* and utilizes matplotlib.pyplot for plotting the graph. 
*
* IMPORTANT: 
*
* 1) An edge exists between two vertices if the Euclidean distance
* between them is no larger than max_distance.
*
* 2) The vertex selected as the source node is the one with the lowest value 
* of the x-component
****************************************************************************/
void Graph::draw_graph()
{
    neighbor_table = new std::vector<int> [size_graph];
    for (int i = 0; i < size_graph; ++i)
    {
        std::uniform_int_distribution<int> distribution(1,100);
        vertex_x.push_back(distribution(generator));
        vertex_y.push_back(distribution(generator));
    }
    Py_Initialize();   
    PyRun_SimpleString("import matplotlib.pyplot as plt");
    std::string command;
    source_node = 0;
    for (int i = 1; i < size_graph; ++i)
    {
        if (vertex_x[i] < vertex_x[source_node])
        {
            source_node = i;
        }
    }


/*****************************************************************************
* Add vertices to the graph. Source node will be shown in red 
*****************************************************************************/
    for (int i = 0; i < size_graph; ++i)
    {
        std::cout << "(" << vertex_x[i] << ", " << vertex_y[i] << ")" << std::endl;
        command.append("plt.scatter(");
        command.append(std::to_string(vertex_x[i]));
        command.append(", ");
        command.append(std::to_string(vertex_y[i]));
        command.append(", s = 100");
        if (i == source_node)
        {
            command.append(", facecolor = \"red\", edgecolor = \"red\"");
        }
        command.append(")");
        PyRun_SimpleString(command.c_str());
        command = {};
        command.append("plt.annotate(");
        command.append(std::to_string(i));
        command.append(", (");
        command.append(std::to_string(vertex_x[i]));
        command.append(", ");
        command.append(std::to_string(vertex_y[i]));
        command.append("))");
        PyRun_SimpleString(command.c_str());
        command = {};
    }


/*****************************************************************************
* Add edges to the graph
*****************************************************************************/
    for (int j = 0; j < size_graph; ++j)
    {
        for (int i = j; i < size_graph; ++i)
        {
            distance = sqrt(pow((vertex_x[j] - vertex_x[i]),2) + pow((vertex_y[j] - vertex_y[i]),2));
            if ((i != j) && distance <= max_distance)
            {
                command.append("plt.plot([");
                command.append(std::to_string(vertex_x[j]));
                command.append(", ");
                command.append(std::to_string(vertex_x[i]));
                command.append("], [");
                command.append(std::to_string(vertex_y[j]));
                command.append(", ");
                command.append(std::to_string(vertex_y[i]));
                command.append("], color = \"grey\")");
                PyRun_SimpleString(command.c_str());
                command = {};
                neighbor_table[j].push_back(i);//Add vertex to the neighbor table of vertex j 
                neighbor_table[i].push_back(j);//Add vertex to the neighbor table of vertex i
            }
        }
    }
    PyRun_SimpleString("plt.show(block = False)");
}


/****************************************************************************
* Destructor
*****************************************************************************
*
* 
*
****************************************************************************/
Graph::~Graph()
{
    Py_Exit(0);
}