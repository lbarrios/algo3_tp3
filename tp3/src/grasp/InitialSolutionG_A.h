#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionG_A : public InitialSolution
{
public:
	InitialSolutionG_A(int type);
	Solution* getInitialSolution(ProblemInstance* instance);
};