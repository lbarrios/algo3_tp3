#include "local_search.h"
HeuristicFactory heuristicFactory;
Parser parser;
Timer timer( cerr );

int main( int argc, char const* argv[] )
{
  /*****************
    Initialization
  ******************/
  // get console parameters
  const char* initialSolutionParameter = ( argc >= 2 ? argv[1] : NULL );
  const char* neighborhoodSelectorParameter = ( argc >= 3 ? argv[2] : NULL );
  // instantiate the initial solution using the initial solution parameter
  std::unique_ptr<InitialSolution> solution =  heuristicFactory.createInitialSolution( initialSolutionParameter );
  // instantiate the neighborhood selector using the neighborhood selector parameter
  std::unique_ptr<NeighborhoodSelector> selector = heuristicFactory.createNeighborhoodSelector( neighborhoodSelectorParameter );
  // instantiate the heuristic using the initial solution and the neighborhood selector
  std::unique_ptr<LocalHeuristic> heuristic = heuristicFactory.createHeuristic( std::move( solution ), std::move( selector ) );
  // parse the input
  parser.parseInput();
  /*************
    Resolution
  **************/
  // obtain the initial time
  timer.setInitialTime( "todo_el_codigo" );
  /*
    code to resolve local heuristic
  */
  // obtain the final time
  timer.setFinalTime( "todo_el_codigo" );
  /***************
    Output Print
  ****************/
  /*
    code to print result
  */
  // save all obtained times to output
  timer.saveAllTimes();
  return 0;
}