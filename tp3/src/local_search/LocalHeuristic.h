#pragma once

#include "InitialSolution.h"
#include "NeighborhoodSelector.h"
#include <memory> // unique_ptr

class LocalHeuristic
{
public:
  LocalHeuristic() = default;
  LocalHeuristic( std::unique_ptr<InitialSolution>, std::unique_ptr<NeighborhoodSelector> );
  ~LocalHeuristic() = default;
  ProblemInstance& run( ProblemInstance );
private:
  std::unique_ptr<InitialSolution> initial_solution;
  std::unique_ptr<NeighborhoodSelector> neighborhood_selector;
};
