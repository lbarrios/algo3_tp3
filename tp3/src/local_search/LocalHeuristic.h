#pragma once

#include "InitialSolution.h"
#include "NeighbourhoodSelector.h"
#include <memory> // unique_ptr

class LocalHeuristic
{
public:
  LocalHeuristic() = default;
  LocalHeuristic( InitialSolution*, NeighbourhoodSelector* );
  ~LocalHeuristic() = default;
  ProblemInstance& run( ProblemInstance );
private:
  InitialSolution* initial_solution;
  NeighbourhoodSelector* neighbourhood_selector;
};
