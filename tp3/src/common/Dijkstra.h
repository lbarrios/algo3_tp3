#pragma once

#include <vector>
#include <queue>
#include <iostream>
#include <limits> //< numeric_limits
#include "Graph.h"
#include "DijkstraSolution.h"
#include "defines.h"
#include "UnvisitedNode.h"

using namespace std;

template<class ObjectiveFunction>
class Dijkstra
{
	priority_queue<UnvisitedNode* ,std::vector<UnvisitedNode*>, ObjectiveFunction> unvisited;
public:
    Dijkstra();
    
    void findPath(Graph* graph, DijkstraSolution* solution);
    
};

template<class ObjectiveFunction>
Dijkstra<ObjectiveFunction>::Dijkstra() {
}

template<class ObjectiveFunction>
void Dijkstra<ObjectiveFunction>::findPath(Graph* graph, DijkstraSolution* solution) {
    int* prevNodes = solution->prevNodes;    
    double* dist = solution->distances;
    for (int i=0; i<graph->nodeCount; i++) {
        dist[i] = INF;
        prevNodes[i] = -1;
    }
    dist[solution->fromNode-1] = 0;

    ObjectiveFunction objFunc;

    unvisited.push(new UnvisitedNode(solution->fromNode, 0, 0));
    
    while (unvisited.size() > 0) {
        UnvisitedNode* currNode = unvisited.top();
        unvisited.pop();         
                
        vector<Node> adjNodes = graph->getAdjacent(currNode->node);        
        for (int i=0; i<adjNodes.size(); i++) {            
            Node toNode = adjNodes[i];
            Edge* edge = graph->getEdge(currNode->node, adjNodes[i]);
            double weight = objFunc.weight(edge->omega1, edge->omega2);
            if(dist[currNode->node-1] + weight < dist[toNode-1]) {
                prevNodes[toNode-1] = currNode->node;
                dist[toNode-1] = dist[currNode->node-1] + weight;                
                unvisited.push(new UnvisitedNode(toNode, edge->omega1, edge->omega2));
            }
        }
    }    
}
