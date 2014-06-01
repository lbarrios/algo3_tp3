#pragma once

#include "Graph.h"
#include <vector>
#include <queue>
#include <iostream>
#include "DijkstraSolution.h"
#include "limits.h"

using namespace std;

#define INF (std::numeric_limits<double>::max())

class UnvisitedNode
{
public:
	Node node;
	double omega1;
	double omega2;

	UnvisitedNode(Node n, double o1, double o2) : node(n), omega1(o1), omega2(o2) {} 
};

template<class ObjectiveFunction>
class Dijkstra
{
	priority_queue<UnvisitedNode* ,std::vector<UnvisitedNode*>, ObjectiveFunction> unvisited;
public:
    Dijkstra();
    
    void findPath(Graph* graph, int fromNode, DijkstraSolution* solution);
    
};

template<class ObjectiveFunction>
Dijkstra<ObjectiveFunction>::Dijkstra() {
}

template<class ObjectiveFunction>
void Dijkstra<ObjectiveFunction>::findPath(Graph* graph, int fromNode, DijkstraSolution* solution) {
    int* prevNodes = solution->prevNodes;
    double* dist = new double[graph->nodeCount];
    for (int i=0; i<graph->nodeCount; i++) {
        dist[i] = INF;
        prevNodes[i] = -1;
    }
    dist[fromNode-1] = 0;

    ObjectiveFunction objFunc;

    unvisited.push(new UnvisitedNode(fromNode, 0, 0));
    
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