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
    
    DijkstraSolution(int n, int fromNode);
    
    void getPath(int toNode, Graph* graph, list<Edge*> &path, double &totalOmega1, double &totalOmega2);
};