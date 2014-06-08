#include "DijkstraSolution.h"
#include <limits> //< numeric_limits

#define INF (std::numeric_limits<double>::max())

DijkstraSolution::DijkstraSolution(int n, int fromNode) {    
    prevNodes = new int[n];   
    this->fromNode = fromNode;
}

void DijkstraSolution::getPath(int toNode, Graph* graph, list<Edge*> &path, double &totalOmega1, double &totalOmega2) {	
    int prevNode = prevNodes[toNode-1];
    totalOmega1 = 0;
    totalOmega2 = 0;        
    while (prevNode != -1) {
    	Edge* edge = graph->getEdge(prevNode, toNode);
        path.push_front(new Edge(prevNode, toNode, edge->omega1, edge->omega2));
        totalOmega1 += edge->omega1;
        totalOmega2 += edge->omega2;
        toNode = prevNode;
        prevNode = prevNodes[prevNode-1];
    }    

    // toNode va cambiando dentro del while
    // si llegado a este punto, toNode != fromNode, significa que no hay camino entre toNode y fromNode    
    if(toNode != fromNode) {
        totalOmega1 = INF;
        totalOmega2 = INF;
    }
}