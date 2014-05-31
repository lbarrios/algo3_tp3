#include "Graph.h"
#include <iostream>

using namespace std;
Graph::Graph( int n )
  : nodeCount( n )
{
}
Graph::~Graph()
{
}
void Graph::addEdge( Node fromNode, Node toNode, double omega1, double omega2 )
{
  this->adjacencyList[fromNode].push_back( toNode );
  this->incidencyMatrix[fromNode][toNode] = new Edge( fromNode, toNode, omega1, omega2 );
}
Edge& Graph::getEdge( Node aNode, Node anotherNode )
{
  return *( this->incidencyMatrix[aNode][anotherNode] );
}
