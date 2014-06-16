#pragma once

#include <vector>
#include "ProblemInstance.h"

class Parser
{
public:
	Parser();
	~Parser();
	vector<ProblemInstance*> problemInstances;	
	void parseInput();	
};
