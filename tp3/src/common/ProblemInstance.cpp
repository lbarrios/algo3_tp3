#include "ProblemInstance.h"

ProblemInstance::ProblemInstance()
{
	graph = NULL;
	u = 0;
	v = 0;
	K = 0;
}

ProblemInstance::ProblemInstance(Graph* graph, int u, int v, int K) 
{
	this->graph = graph;
	this->u = u;
	this->v = v;
	this->K = K;
}

ProblemInstance::~ProblemInstance() 
{
	delete graph;
}