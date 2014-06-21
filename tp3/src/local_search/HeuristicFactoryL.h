#pragma once

#include "../common/HeuristicFactory.h"
#include "InitialSolutionL_A.h"
#include "InitialSolutionL_B.h"
#include "InitialSolutionL_C.h"

class HeuristicFactoryL : public HeuristicFactory
{
public:
  InitialSolution* createInitialSolution( int );  
};
