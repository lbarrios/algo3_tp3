#pragma once

#include <iostream>
#include "Graph.h"
#include "Edge.h"
#include <list>

class DijkstraSolution
{
public:
    int fromNode;
    int* prevNodes;
    double* dist;
    
    DijkstraSolution(int n);
    
    void getPath(int toNode, list<Edge*> *path);
};