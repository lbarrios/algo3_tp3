#pragma once

#include <cstddef> // NULL
#include "Graph.h"

class ProblemInstance
{
public:
	Graph* graph;
	int u;
	int v;
	int K;

	ProblemInstance();
	/**
	 * A constructor
	 * @param graph original graph
	 * @param u initial node of the path
	 * @param v final node of the path
	 * @param K sum of omega1 must be lower than K
	 */
	ProblemInstance(Graph* graph, int u, int v, int K);
	~ProblemInstance();
};
