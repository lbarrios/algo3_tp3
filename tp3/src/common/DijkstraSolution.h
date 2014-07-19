#pragma once

#include <iostream>
#include "Graph.h"
#include "Edge.h"
#include <vector>

class DijkstraSolution
{
public:
    int fromNode;
    int* prevNodes;       
    double *distances;

    DijkstraSolution(int n, int fromNode);
    
    void getPath(int toNode, Graph* graph, vector<Edge*> &path, double &totalOmega1, double &totalOmega2);
};
