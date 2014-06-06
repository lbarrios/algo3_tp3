#include "HeuristicFactory.h"
std::unique_ptr<InitialSolution> HeuristicFactory::createInitialSolution( const char* initial_solution_param )
{
  // initial_solution_param debe ser un int, ver initial_solution_enum en HeuristicFactory.h
  switch ( initial_solution_param != NULL ? atoi( initial_solution_param ) : 0 )
  {
  case INITIAL_SOLUTION_A:
    break;

  case INITIAL_SOLUTION_B:
    break;

  case INITIAL_SOLUTION_C:
    break;

  default:
    break;
  }

  return std::move( this->initial_solution );
}

std::unique_ptr<NeighborhoodSelector> HeuristicFactory::createNeighborhoodSelector( const char* neighborhood_selector_param )
{
  // neighborhood_selector_param debe ser un int, ver neighborhood_selector_enum en HeuristicFactory.h
  switch ( neighborhood_selector_param != NULL ? atoi( neighborhood_selector_param ) : 0 )
  {
  case NEIGHBORHOOD_SELECTOR_A:
    break;

  case NEIGHBORHOOD_SELECTOR_B:
    break;

  case NEIGHBORHOOD_SELECTOR_C:
    break;

  default:
    break;
  }

  return std::move( this->selector );
}

std::unique_ptr<LocalHeuristic> HeuristicFactory::createHeuristic(
  std::unique_ptr<InitialSolution> initialSolution, std::unique_ptr<NeighborhoodSelector> neighborhoodSelector )
{
  this->heuristic.reset( new LocalHeuristic( std::move( initialSolution ), std::move( neighborhoodSelector ) ) );
  /*

  */
  return std::move( this->heuristic );
}
