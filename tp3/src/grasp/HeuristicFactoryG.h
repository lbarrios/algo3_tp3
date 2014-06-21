#pragma once

#include "../common/HeuristicFactory.h"
#include "InitialSolutionG_A.h"
#include "InitialSolutionG_B.h"
#include "InitialSolutionG_C.h"

class HeuristicFactoryG : public HeuristicFactory
{
public:
	InitialSolution* createInitialSolution( int );
};
