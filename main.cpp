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
    Dijkstra myGR;
    myGR.draw_graph();
    myGR.Dijkstra_algorithm();
    int stop;
    std::cout << "Please enter any number to exit: ";
    std::cin >> stop;
    std::cout << stop*stop << std::endl;
    return 0;
}
