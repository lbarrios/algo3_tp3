#include "DijkstraSolution.h"

DijkstraSolution::DijkstraSolution(int n) {
    prevNodes = new int[n];   
}

void DijkstraSolution::getPath(int toNode, Graph* graph, list<Edge*> &path, double &totalK) {	
    int fromNode = prevNodes[toNode-1];
    totalK = 0;
    while (fromNode != -1) {
    	Edge* edge = graph->getEdge(fromNode, toNode);
        path.push_front(new Edge(fromNode, toNode, edge->omega1, edge->omega2));
        totalK += edge->omega1;
        toNode = fromNode;
        fromNode = prevNodes[fromNode-1];
    }    
}