#pragma once

#include "Node.h"

class Edge
{
public:
    Edge(int fromNode, int toNode, double omega1, double omega2);
    int fromNode;
    int toNode;
    double omega1;
    double omega2; 
};
