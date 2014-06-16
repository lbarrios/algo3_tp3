#include "../common/Graph.h"
#include "../common/Parser.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"
#include "../common/GreedyHeuristic.h"
#include "Solution.h"
#include "../common/Parser.h"
#include "../common/Timer.h"
#include "HeuristicFactory.h"

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
    cout << "Initial solution: ";
    solution->print();

    if(solution->totalOmega1 < instance->K) {
      // run the heuristic
      Solution* newSolution = NULL;    
      bool huboMejora = false;
      do
      {
        newSolution = selector->getBestNeighbour( solution );
        // Si no logro mejorar la solucion, termino      
        if(newSolution != NULL) {
          cout << "Mejore omega2!" << endl;
          cout << "new solution: ";
          newSolution->print();
          delete solution;
          solution = newSolution;          
          huboMejora = true;  
        } else {                      
          huboMejora = false;
        }      
      } while(huboMejora);
    } else {
      // El dijkstra de omega1 no cumple con el K, asi que no tiene correr la heuristica
    }
    
    
    // obtain the final time
    timer.setFinalTime( "todo_el_codigo" );

    /***************
      Output Print
    ****************/
    // print the solution
    cout << "Final solution: ";
    solution->print();

    delete solution;
    
    // save all obtained times to output
    timer.saveAllTimes();
  }
  return 0;
}