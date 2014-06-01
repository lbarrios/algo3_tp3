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
    int totalK;
    
    DijkstraSolution(int n);
    
    void getPath(int toNode, Graph* graph, list<Edge*> &path, double &totalK);
};