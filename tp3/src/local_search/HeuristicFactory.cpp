#include "HeuristicFactory.h"

HeuristicFactory::HeuristicFactory()
: initial_solution(NULL), selector(NULL), heuristic(NULL)
{
}

HeuristicFactory::~HeuristicFactory()
{
  if(this->initial_solution) {
    delete this->initial_solution;
  }
  if(this->selector) {
    delete this->selector;
  }
  if(this->heuristic) {
    delete this->heuristic;
  }
}

InitialSolution* HeuristicFactory::createInitialSolution( const char* initial_solution_param )
{
  if(this->initial_solution) {
    delete this->initial_solution;
    this->initial_solution = NULL;
  }
  // initial_solution_param debe ser un int, ver initial_solution_enum en HeuristicFactory.h
  switch ( initial_solution_param != NULL ? atoi( initial_solution_param ) : 0 )
  {
  case INITIAL_SOLUTION_A:
    this->initial_solution = new InitialSolutionA();
    break;

  case INITIAL_SOLUTION_B:
    this->initial_solution = new InitialSolutionB();
    break;

  case INITIAL_SOLUTION_C:
    this->initial_solution = new InitialSolutionC();
    break;

  default:
    this->initial_solution = new InitialSolutionA();
    break;
  }

  return this->initial_solution;
}

NeighbourhoodSelector* HeuristicFactory::createNeighborhoodSelector( const char* neighbourhood_selector_param )
{
  if(this->selector) {
    delete this->selector;
    this->selector = NULL;
  }
  // neighborhood_selector_param debe ser un int, ver neighborhood_selector_enum en HeuristicFactory.h
  switch ( neighbourhood_selector_param != NULL ? atoi( neighbourhood_selector_param ) : 0 )
  {
  case NEIGHBORHOOD_SELECTOR_A:
    this->selector = new NeighbourhoodSelectorA();
    break;

  case NEIGHBORHOOD_SELECTOR_B:
    this->selector = new NeighbourhoodSelectorB();
    break;

  case NEIGHBORHOOD_SELECTOR_C:
    this->selector = new NeighbourhoodSelectorC();
    break;

  default:
    this->selector = new NeighbourhoodSelectorA();
    break;
  }

  return this->selector;
}

LocalHeuristic* HeuristicFactory::createHeuristic( InitialSolution* initialSolution, NeighbourhoodSelector* neighbourhoodSelector )
{
  if(this->heuristic) {
    delete this->heuristic;
    this->heuristic = NULL;
  }
  this->heuristic = new LocalHeuristic( initialSolution, neighbourhoodSelector );
  return this->heuristic;
}
