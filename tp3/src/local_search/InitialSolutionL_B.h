#pragma once

#include "../common/InitialSolution.h"

class InitialSolutionL_B : public InitialSolution
{
public:	
	Solution* getInitialSolution(ProblemInstance* instance);	
};