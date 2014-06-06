#pragma once

#include "NeighborhoodSelector.h"
#include "InitialSolution.h"
#include "LocalHeuristic.h"
#include <cstdlib> // atoi
#include <memory> // unique_ptr

class HeuristicFactory
{
public:
  HeuristicFactory() = default;
  ~HeuristicFactory() = default;
  std::unique_ptr<InitialSolution> createInitialSolution( const char* );
  std::unique_ptr<NeighborhoodSelector> createNeighborhoodSelector( const char* );
  std::unique_ptr<LocalHeuristic> createHeuristic( std::unique_ptr<InitialSolution>, std::unique_ptr<NeighborhoodSelector> );
private:
  enum initial_solution_enum {INITIAL_SOLUTION_A = 1, INITIAL_SOLUTION_B, INITIAL_SOLUTION_C};
  enum neighborhood_selector_enum {NEIGHBORHOOD_SELECTOR_A = 1, NEIGHBORHOOD_SELECTOR_B, NEIGHBORHOOD_SELECTOR_C};
  std::unique_ptr<InitialSolution> initial_solution;
  std::unique_ptr<NeighborhoodSelector> selector;
  std::unique_ptr<LocalHeuristic> heuristic;
};
