#pragma once

#include "../common/Solution.h"
#include "../common/ProblemInstance.h"

class InitialSolution
{
public:
	InitialSolution();
	Solution* getInitialSolution(ProblemInstance* instance);
};