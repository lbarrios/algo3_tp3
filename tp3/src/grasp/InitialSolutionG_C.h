#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionG_C : public InitialSolution
{
public:	
	InitialSolutionG_C(int type);
	Solution* getInitialSolution(ProblemInstance* instance);
};