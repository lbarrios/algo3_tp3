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
    //cout << "Initial solution: ";
    //solution->print();    
    // si solution no es valida entonces, entonces es NULL
    if(solution != NULL) {
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
    if(solution) {
      solution->print();
      delete solution;
    }    
    //solution->printTP();
    
    // save all obtained times to output
    timer.saveAllTimes();
  }
  return 0;
}
