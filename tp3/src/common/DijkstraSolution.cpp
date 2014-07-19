#include "DijkstraSolution.h"
#include <limits> //< numeric_limits
#include <list>

#define INF (std::numeric_limits<double>::max())

DijkstraSolution::DijkstraSolution(int n, int fromNode) {    
    prevNodes = new int[n];   
    distances = new double[n];
    this->fromNode = fromNode;    
}

void DijkstraSolution::getPath(int toNode, Graph* graph, vector<Edge*> &path, double &totalOmega1, double &totalOmega2) {	
    int prevNode = prevNodes[toNode-1];
    totalOmega1 = 0;
    totalOmega2 = 0;        
    list<Edge*> pathList;
    while (prevNode != -1) {
    	Edge* edge = graph->getEdge(prevNode, toNode);
        pathList.push_front(new Edge(prevNode, toNode, edge->omega1, edge->omega2));
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
        // el path que se devuelve en la solucion queda vacio
    } else {
        // solo devuelvo un camino si existe un camino posible entre fromNode y toNode
        path.resize(pathList.size());
        int index = 0;
        for(list<Edge*>::iterator it = pathList.begin(); it != pathList.end(); it++) {
            path[index] = *it;
            index++;
        }
    }
}
