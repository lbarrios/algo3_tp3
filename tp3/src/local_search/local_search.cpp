#include "local_search.h"
#include "../common/Graph.h"
#include "../common/Parser.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"
#include "../common/GreedyHeuristic.h"
#include "Solution.h"

HeuristicFactory heuristicFactory;
Parser parser;
Timer timer( cerr );


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


int main( int argc, char const* argv[] )
{
  /*****************
    Initialization
  ******************/
  // get console parameters
  const char* initialSolutionParameter = ( argc >= 2 ? argv[1] : NULL );
  const char* neighborhoodSelectorParameter = ( argc >= 3 ? argv[2] : NULL );
  // instantiate the initial solution using the initial solution parameter
  InitialSolution* initialSolution =  heuristicFactory.createInitialSolution( initialSolutionParameter );
  // instantiate the neighborhood selector using the neighborhood selector parameter
  NeighbourhoodSelector* selector = heuristicFactory.createNeighborhoodSelector( neighborhoodSelectorParameter );
  // instantiate the heuristic using the initial solution and the neighborhood selector
  //std::unique_ptr<LocalHeuristic> heuristic = heuristicFactory.createHeuristic( std::move( solution ), std::move( selector ) );
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
    selector->initialize(instance);        

    // obtain the initial time
    timer.setInitialTime( "todo_el_codigo" );
    // obtain the initial solution
    Solution* solution = initialSolution->getInitialSolution( instance );

    // run the heuristic
    Solution* newSolution = NULL;    
    do
    {
      newSolution = selector->getBestNeighbour( solution );
    } while( newSolution && newSolution < solution );    

    
    // obtain the final time
    timer.setFinalTime( "todo_el_codigo" );
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