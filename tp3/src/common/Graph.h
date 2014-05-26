#pragma once

#include "Node.h"
#include "Edge.h"
#include <vector>

using namespace std;

class Graph
{
public:
    int n;
    vector<Edge*> edges;
    
    Graph(int n);
    ~Graph();
    void connect(int fromNode, int toNode, double weight);
    void getEdgesFromNode(int node, vector<Edge*> *output);
    void getAdjacentNodes(int node, vector<int> *output);
};