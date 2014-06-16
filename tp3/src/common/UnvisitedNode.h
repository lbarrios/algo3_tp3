#pragma once

#include "Node.h"

class UnvisitedNode
{
public:
	Node node;
	double omega1;
	double omega2;

	UnvisitedNode(Node n, double o1, double o2) : node(n), omega1(o1), omega2(o2) {} 
};