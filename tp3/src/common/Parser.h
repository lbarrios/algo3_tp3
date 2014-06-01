#pragma once

#include <vector>
#include <iostream>
#include <cstdlib> //< atoi

#include "Graph.h"
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
