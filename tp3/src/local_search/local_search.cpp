#include "local_search.h"

HeuristicFactory heuristicFactory;
Parser parser;
Timer timer( cerr );
void printSolution ( const Solution* );

int main( int argc, char const* argv[] )
{
  /*****************
    Initialization
  ******************/
  // get console parameters
  const char* initialSolutionParameter = ( argc >= 2 ? argv[1] : 0 );
  const char* neighborhoodSelectorParameter = ( argc >= 3 ? argv[2] : 0 );
  // instantiate the initial solution using the initial solution parameter
  InitialSolution* initialSolution =  heuristicFactory.createInitialSolution( initialSolutionParameter );
  // instantiate the neighborhood selector using the neighborhood selector parameter
  NeighbourhoodSelector* selector = heuristicFactory.createNeighborhoodSelector( neighborhoodSelectorParameter );
  // parse the input
  parser.parseInput();

  /*************************
    Iterate over instances
  **************************/
  for(auto instance:parser.problemInstances)
  {
    /*************
      Resolution
    **************/
    timer.setInitialTime( "todo_el_codigo" ); // obtain the initial time
    selector->initialize( instance ); // initialize the neighbourhood selector for this instance
    Solution* solution = initialSolution->getInitialSolution( instance ); // obtain the initial solution
    Solution* newSolution = NULL;
    do // run the heuristic
    {
      newSolution = selector->getBestNeighbour( solution );
    } while( newSolution && newSolution < solution );    
    timer.setFinalTime( "todo_el_codigo" ); // obtain the final time

    /***************
      Output Print
    ****************/
    // print the solution
    printSolution ( solution );
    // save all obtained times to output
    timer.saveAllTimes();
  }
  return 0;
}

void printSolution ( const Solution* solution )
{  
  cout << "Omega1: " << solution->totalOmega1 << ", Omega2: " << solution->totalOmega2 << endl;
  cout << "Path: ";
  for ( auto it = begin( solution->path ); it != end( solution->path ); ++it )
  {
    cout << ( *it )->fromNode << " -> " << ( *it )->toNode << ", ";
  }
  cout << endl << endl;
}