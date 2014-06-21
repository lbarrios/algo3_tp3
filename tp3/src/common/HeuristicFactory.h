#pragma once

#include "../local_search/NeighbourhoodSelector.h"
#include "InitialSolution.h"
#include "../local_search/LocalHeuristic.h"
#include <cstdlib> // atoi
#include <memory> // unique_ptr
#include "../local_search/NeighbourhoodSelectorA.h"
#include "../local_search/NeighbourhoodSelectorB.h"
#include "../local_search/NeighbourhoodSelectorC.h"

class HeuristicFactory
{
public:
  HeuristicFactory();
  virtual ~HeuristicFactory();
  InitialSolution* createInitialSolution( int );
  NeighbourhoodSelector* createNeighborhoodSelector( int );
  LocalHeuristic* createHeuristic( InitialSolution*, NeighbourhoodSelector* );
protected:  
  InitialSolution* initial_solution;
  NeighbourhoodSelector* selector;
  LocalHeuristic* heuristic;
};
