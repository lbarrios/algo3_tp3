#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionL_B : public InitialSolution
{
public:	
	InitialSolutionL_B(int type);
	Solution* getInitialSolution(ProblemInstance* instance);	
};