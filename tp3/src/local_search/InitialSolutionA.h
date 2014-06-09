#pragma once

#include "InitialSolution.h"

class InitialSolutionA : public InitialSolution
{
public:
	InitialSolutionA() = default;
	virtual ~InitialSolutionA() = default;
	
	Solution* getInitialSolution(ProblemInstance* instance);
};