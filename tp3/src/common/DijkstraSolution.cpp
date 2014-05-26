#include "DijkstraSolution.h"

DijkstraSolution::DijkstraSolution(int n) {
    prevNodes = new int[n];
    dist = new double[n];
}

void DijkstraSolution::getPath(int toNode, list<Edge*> *path) {
    int fromNode = prevNodes[toNode];
    while (fromNode != -1) {
        path->push_front(new Edge(fromNode, toNode, dist[toNode]));
        toNode = fromNode;
        fromNode = prevNodes[fromNode];
    }
}