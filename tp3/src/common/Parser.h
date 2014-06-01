#pragma once

#include "Graph.h"
#include <vector>
#include <iostream>
#include "ProblemInstance.h"

using namespace std;

class Parser
{
public:
	Parser();
	~Parser();
	vector<ProblemInstance*> problemInstances;	
	void parseInput();	
};