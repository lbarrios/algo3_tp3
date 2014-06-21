#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionG_C : public InitialSolution
{
public:	
	Solution* getInitialSolution(ProblemInstance* instance);
};