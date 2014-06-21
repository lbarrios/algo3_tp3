#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionL_A : public InitialSolution
{
public:
	Solution* getInitialSolution(ProblemInstance* instance);
};