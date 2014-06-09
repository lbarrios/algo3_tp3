#pragma once

#include "InitialSolution.h"

class InitialSolutionC : public InitialSolution
{
public:
	InitialSolutionC() = default;
	virtual ~InitialSolutionC() = default;
	
	Solution* getInitialSolution(ProblemInstance* instance);
};