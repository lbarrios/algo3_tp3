#include "../common/Graph.h"
#include "../common/Parser.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"
#include "../common/GreedyHeuristic.h"
#include "../common/Solution.h"
#include "../common/Parser.h"
#include "../common/Timer.h"
#include "HeuristicFactoryL.h"

HeuristicFactoryL heuristicFactory;
Parser parser;
Timer timer( cerr );


int main( int argc, char const* argv[] )
{
  /*****************
    Initialization
  ******************/
  // get console parameters
  int initialSolutionParameter = ( argc >= 2 ? atoi(argv[1]) : 0 );
  int neighborhoodSelectorParameter = ( argc >= 3 ? atoi(argv[2]) : 0 );
  // instantiate the initial solution using the initial solution parameter
  InitialSolution* initialSolution =  heuristicFactory.createInitialSolution( initialSolutionParameter );
  InitialSolution* initialSolutionBestOmega1 =  heuristicFactory.createInitialSolution( INITIAL_SOLUTION_A );
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
    // si no encuentro el path que cumpla con K, pruebo usando dijkstra con omega1.
    // Tambien puede pasar que no encuentre ningun path, por lo que totalOmega1 = INF, y en ese 
    // caso tambien pruebo buscar otro path
    if(initialSolution->type != initialSolutionBestOmega1->type && solution->totalOmega1 > instance->K) {
      delete solution;
      solution = initialSolutionBestOmega1->getInitialSolution(instance);
    }

    cout << "Initial solution: ";
    solution->print();

    // El dijkstra de omega1 debe cumplir con el K, sino no tiene sentido correr la heuristica
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