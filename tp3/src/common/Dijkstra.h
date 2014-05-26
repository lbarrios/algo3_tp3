#pragma once

#include "Graph.h"
#include "UnvisitedNode.h"
#include <vector>
#include <queue>
#include <iostream>
#include "PreviousNode.h"
#include "DijkstraSolution.h"

using namespace std;

class UnvisitedComparison
{
public:
    bool operator() (const int& lhs, const int&rhs) const
    {
        return lhs > rhs;
    }
};
typedef priority_queue<int,std::vector<int>, UnvisitedComparison> UnvisitedPQ;


class Dijkstra
{
public:
    Dijkstra();
    
    void findPath(Graph* graph, int fromNode, DijkstraSolution* solution);
    
};
