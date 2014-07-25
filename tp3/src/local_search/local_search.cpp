#include "../common/Graph.h"
#include "../common/Parser.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"
#include "../common/GreedyHeuristic.h"
#include "../common/Solution.h"
#include "../common/Parser.h"
#include "../common/Timer.h"
#include "NeighbourhoodSelectorA.h"
#include "InitialSolution.h"

Parser parser;
Timer timer( cerr );


int main( int argc, char const* argv[] )
{
  /*****************
    Initialization
  ******************/
  // instantiate the initial solution using the initial solution parameter
  InitialSolution* initialSolution = new InitialSolution();
  // instantiate the neighborhood selector using the neighborhood selector parameter
  NeighbourhoodSelector* selector = new NeighbourhoodSelectorA();
  // parse the input
  parser.parseInput();  

  /*************************
    Iterate over instances
  *******************'*******/
  for(auto instance:parser.problemInstances)
  {
    /*************
      Resolution
    **************/           
    selector->initialize(instance);        
    
    // obtain the initial time
    timer.setInitialTime( "todo_el_codigo" );
    // obtain the initial solution
    
    int initialSolutionOmega2;

    Solution* solution = initialSolution->getInitialSolution( instance );    
    //cout << "Initial solution: ";

    unsigned int iteraciones = 0;

    // El dijkstra de omega1 debe cumplir con el K, sino no tiene sentido correr la heuristica    
    // si solution no es valida entonces, entonces es NULL
    if(solution != NULL) {
      initialSolutionOmega2 = solution->totalOmega2;

      // run the heuristic
      Solution* newSolution = NULL;    
      bool huboMejora = false;
      do
      {
        newSolution = selector->getBestNeighbour( solution );
        // Si no logro mejorar la solucion, termino      
        if(newSolution != NULL) {
          //cout << "Mejore omega2!" << endl;
          //cout << "new solution: ";
          //newSolution->print();
          delete solution;
          solution = newSolution;          
          huboMejora = true;  
          iteraciones++;
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
    //cout << "Final solution: ";
    cout << iteraciones << " ";
    if(solution) {
      if(iteraciones) cout << (initialSolutionOmega2 - solution->totalOmega2) / iteraciones << endl;
      else cout << 0 << endl;
      //solution->print();
      delete solution;
    }
    else
    {
      cout << 0 << endl;
    }
    //solution->printTP();
    
    // save all obtained times to output
    timer.saveAllTimes();
  }
  return 0;
}
