#pragma once

#include "NeighbourhoodSelector.h"
#include "InitialSolution.h"
#include "LocalHeuristic.h"
#include <cstdlib> // atoi
#include <memory> // unique_ptr
#include "NeighbourhoodSelectorA.h"
#include "NeighbourhoodSelectorB.h"
#include "NeighbourhoodSelectorC.h"
#include "InitialSolutionA.h"
#include "InitialSolutionB.h"
#include "InitialSolutionC.h"

class HeuristicFactory
{
public:
  HeuristicFactory();
  ~HeuristicFactory();
  InitialSolution* createInitialSolution( int );
  NeighbourhoodSelector* createNeighborhoodSelector( int );
  LocalHeuristic* createHeuristic( InitialSolution*, NeighbourhoodSelector* );
private:  
  InitialSolution* initial_solution;
  NeighbourhoodSelector* selector;
  LocalHeuristic* heuristic;
};
