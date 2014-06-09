#pragma once

#include "InitialSolution.h"

class InitialSolutionB : public InitialSolution
{
public:
	InitialSolutionB() = default;
	virtual ~InitialSolutionB() = default;
	
	Solution* getInitialSolution(ProblemInstance* instance);	
};