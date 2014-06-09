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
  ~HeuristicFactory() = default;
  InitialSolution* createInitialSolution( const char* );
  NeighbourhoodSelector* createNeighborhoodSelector( const char* );
  LocalHeuristic* createHeuristic( InitialSolution*, NeighbourhoodSelector* );
private:
  enum initial_solution_enum {INITIAL_SOLUTION_A = 1, INITIAL_SOLUTION_B, INITIAL_SOLUTION_C};
  enum neighborhood_selector_enum {NEIGHBORHOOD_SELECTOR_A = 1, NEIGHBORHOOD_SELECTOR_B, NEIGHBORHOOD_SELECTOR_C};
  InitialSolution* initial_solution;
  NeighbourhoodSelector* selector;
  LocalHeuristic* heuristic;
};
