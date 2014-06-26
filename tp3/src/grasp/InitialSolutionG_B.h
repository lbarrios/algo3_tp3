#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionG_B : public InitialSolution
{
public:
	InitialSolutionG_B(int type);
	Solution* getInitialSolution(ProblemInstance* instance);	
};