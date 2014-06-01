#include "Graph.h"
#include <iostream>

using namespace std;
Graph::Graph( int n )
  : nodeCount( n )
{
    this->adjacencyList = vector<vector<int> >(n+1);
    for (int i = 0; i < n+1; i++) {
        this->incidencyMatrix.push_back(vector<Edge*>(n+1, NULL));
    }
}
Graph::~Graph()
{
}
void Graph::addEdge( Node fromNode, Node toNode, double omega1, double omega2 )
{
  this->adjacencyList[fromNode].push_back( toNode );
  this->incidencyMatrix[fromNode][toNode] = new Edge( fromNode, toNode, omega1, omega2 );
}

vector<Node>& Graph::getAdjacent( Node n ) {
    return this->adjacencyList[n];
}

Edge* Graph::getEdge( Node aNode, Node anotherNode )
{
  return this->incidencyMatrix[aNode][anotherNode];
}
