#pragma once

#include "Node.h"

class Edge
{
public:
    int fromNode;
    int toNode;
    int weight;
    
    Edge(int fromNode, int toNode, double weight);
};
