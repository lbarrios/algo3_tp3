#pragma once

#include "Graph.h"

class ProblemInstance
{
public:
	Graph* graph;
	int u;
	int v;
	int K;

	ProblemInstance();
	ProblemInstance(Graph* graph, int u, int v, int K);
	~ProblemInstance();
};