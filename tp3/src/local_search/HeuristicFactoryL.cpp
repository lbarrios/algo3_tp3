#include "HeuristicFactoryL.h"

InitialSolution* HeuristicFactoryL::createInitialSolution( int initial_solution_param )
{    
  if(this->initial_solution) {
    delete this->initial_solution;
    this->initial_solution = NULL;
  }
  // los posibles valores de initial_solution_param estan en defines.h
  switch ( initial_solution_param )
  {
  case INITIAL_SOLUTION_A:
    this->initial_solution = new InitialSolutionL_A(initial_solution_param);
    break;

  case INITIAL_SOLUTION_B:
    this->initial_solution = new InitialSolutionL_B(initial_solution_param);
    break;

  case INITIAL_SOLUTION_C:
    this->initial_solution = new InitialSolutionL_C(initial_solution_param);
    break;

  default:
    this->initial_solution = new InitialSolutionL_A(initial_solution_param);
    break;
  }

  return this->initial_solution;
}
