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

InitialSolution* HeuristicFactory::createInitialSolution( int initial_solution_param )
{
  if(this->initial_solution) {
    delete this->initial_solution;
    this->initial_solution = NULL;
  }
  // los posibles valores de initial_solution_param estan en defines.h
  switch ( initial_solution_param )
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

NeighbourhoodSelector* HeuristicFactory::createNeighborhoodSelector( int neighbourhood_selector_param )
{
  if(this->selector) {
    delete this->selector;
    this->selector = NULL;
  }
  // los posibles valores de neighbourhood_selector_param estan en defines.h
  switch ( neighbourhood_selector_param )
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
