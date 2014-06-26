#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionL_A : public InitialSolution
{
public:
	InitialSolutionL_A(int type);
	Solution* getInitialSolution(ProblemInstance* instance);
};