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
  vector<Node>::iterator getAdjacent( int aNode );
  Edge& getEdge( Node aNode, Node anotherNode );
  int nodeCount;

  //void getEdgesFromNode(Node node, vector<Edge*> *output);
  //void getAdjacentNodes(Node node, vector<Node> *output);
private:
  //vector<Edge *> edges;
  vector< vector< Node > > adjacencyList;
  vector< vector< Edge* > > incidencyMatrix;
};