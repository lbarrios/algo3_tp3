#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionL_C : public InitialSolution
{
public:
	Solution* getInitialSolution(ProblemInstance* instance);
};