#include "Graph.h"
#include "Arrow.h"
#include <iostream>

using namespace std;
Graph::Graph(int n) {
    this->n = n;
}

void Graph::connect(int fromNode, int toNode, double weight) {
    if(fromNode < 0 || fromNode >= n || toNode < 0 || toNode >= n) {
        return;
    }
    edges.push_back(new Edge(fromNode, toNode, weight));
}

void Graph::getEdgesFromNode(int node, vector<Edge*> *output) {
    for (int i=0; i<edges.size(); i++) {
        if(edges[i]->fromNode == node || edges[i]->toNode == node) {
            output->push_back(edges[i]);
        }
    }
}


void Graph::getAdjacentNodes(int node, vector<int> *output) {
    for (int i=0; i<edges.size(); i++) {
        if(edges[i]->fromNode == node) {
            output->push_back(edges[i]->toNode);
        } else if(edges[i]->toNode == node) {
            output->push_back(edges[i]->fromNode);
        }
    }
}

Graph::~Graph() {

}
