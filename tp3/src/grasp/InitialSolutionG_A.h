#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionG_A : public InitialSolution
{
public:
	Solution* getInitialSolution(ProblemInstance* instance);
};