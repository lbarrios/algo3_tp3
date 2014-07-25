#pragma once

#include "Node.h"
#include "Edge.h"
#include <vector>
using namespace std;

class Graph
{
public:
  Graph( int nodeCount );
  Graph( const Graph& g ) = default;
  ~Graph();

  void addEdge( Node fromNode, Node toNode, double omega1, double omega2 );
  vector<Node>& getAdjacent( Node n );
  Edge* getEdge( Node aNode, Node anotherNode );
  int nodeCount;
  int edgeCount;

  int countNodes();
  int countEdges();
  
private:
  vector< vector< Node > > adjacencyList;
  vector< vector< Edge* > > incidencyMatrix;
};
