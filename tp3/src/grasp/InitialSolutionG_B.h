#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionG_B : public InitialSolution
{
public:
	Solution* getInitialSolution(ProblemInstance* instance);	
};