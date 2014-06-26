#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionL_C : public InitialSolution
{
public:
	InitialSolutionL_C(int type);
	Solution* getInitialSolution(ProblemInstance* instance);
};