#include "Graph.h"
#include <iostream>

using namespace std;
Graph::Graph( int n )
  : nodeCount( n )
{
    edgeCount = 0;
    this->adjacencyList = vector<vector<int> >(n);
    for (int i = 0; i < n; i++) {
        this->incidencyMatrix.push_back(vector<Edge*>(n, NULL));
    }
}
Graph::~Graph()
{
}
void Graph::addEdge( Node fromNode, Node toNode, double omega1, double omega2 )
{
  this->edgeCount++;
  this->adjacencyList[fromNode-1].push_back( toNode );
  this->incidencyMatrix[fromNode-1][toNode-1] = new Edge( fromNode, toNode, omega1, omega2 );
  this->adjacencyList[toNode-1].push_back( fromNode );
  this->incidencyMatrix[toNode-1][fromNode-1] = new Edge( toNode, fromNode, omega1, omega2 );
}

vector<Node>& Graph::getAdjacent( Node n ) {
    return this->adjacencyList[n-1];
}

Edge* Graph::getEdge( Node aNode, Node anotherNode )
{
  return this->incidencyMatrix[aNode-1][anotherNode-1];
}

int Graph::countNodes(){
  return nodeCount;
}

int Graph::countEdges(){
  return edgeCount;
}