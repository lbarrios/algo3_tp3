#include "LocalHeuristic.h"

LocalHeuristic::LocalHeuristic(
  std::unique_ptr<InitialSolution> i, std::unique_ptr<NeighborhoodSelector> n )
  : initial_solution( std::move( i ) ), neighborhood_selector( std::move( n ) )
{
}