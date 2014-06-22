#include "HeuristicFactoryG.h"

InitialSolution* HeuristicFactoryG::createInitialSolution( int initial_solution_param )
{
  if(this->initial_solution) {
    delete this->initial_solution;
    this->initial_solution = NULL;
  }
  // los posibles valores de initial_solution_param estan en defines.h
  switch ( initial_solution_param )
  {
  case INITIAL_SOLUTION_A:
    this->initial_solution = new InitialSolutionG_A();
    break;

  case INITIAL_SOLUTION_B:
    this->initial_solution = new InitialSolutionG_B();
    break;

  case INITIAL_SOLUTION_C:
    this->initial_solution = new InitialSolutionG_C();
    break;

  default:
    this->initial_solution = new InitialSolutionG_A();
    break;
  }

  return this->initial_solution;
}