#pragma once

#include <vector>
#include <queue>
#include <list>
#include <iostream>
#include <limits> //< numeric_limits
#include "Graph.h"
#include "DijkstraSolution.h"
#include <iostream>

using namespace std;

#define INF (std::numeric_limits<double>::max())
#define RCL_SIZE 10

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
    
    void findPath(Graph* graph, DijkstraSolution* solution);
    
};

template<class ObjectiveFunction>
Dijkstra<ObjectiveFunction>::Dijkstra() {
}

template<class ObjectiveFunction>
void Dijkstra<ObjectiveFunction>::findPath(Graph* graph, DijkstraSolution* solution) {
    int* prevNodes = solution->prevNodes;
    double* dist = new double[graph->nodeCount];
    for (int i=0; i<graph->nodeCount; i++) {
        dist[i] = INF;
        prevNodes[i] = -1;
    }
    dist[solution->fromNode-1] = 0;

    ObjectiveFunction objFunc;

    unvisited.push(new UnvisitedNode(solution->fromNode, 0, 0));
    
    while (unvisited.size() > 0) {
        int rcl_size = min(RCL_SIZE, int(unvisited.size()));
        int chosen = rand()%rcl_size + 1; // genera un int entre 1 y rcl_size 
        list<UnvisitedNode*> stack;
        for (int i = 0; i < chosen; i++) {
            stack.push_front(unvisited.top());
            unvisited.pop();
        }
        UnvisitedNode* currNode = stack.front();
        stack.pop_front();
        for (list<UnvisitedNode*>::iterator it = stack.begin(); it != stack.end(); it++)
            unvisited.push(*it);
                
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
