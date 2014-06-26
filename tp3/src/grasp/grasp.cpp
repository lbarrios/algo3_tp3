#include "../common/Graph.h"
#include "../common/Parser.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"
#include "../common/DijkstraRandomized.h"
#include "../common/GreedyHeuristic.h"
#include "../common/Solution.h"
#include "../common/Parser.h"
#include "../common/Timer.h"
#include "HeuristicFactoryG.h"
#include <math.h>

HeuristicFactoryG heuristicFactory;
Parser parser;
Timer timer( cerr );


int main( int argc, char const* argv[] ) 
{
    /* Semilla random */
    srand (time(NULL));

    /*****************
      Initialization
    ******************/
    // get console parameters
    int initialSolutionParameter = ( argc >= 2 ? atoi(argv[1]) : 0 );
    int neighborhoodSelectorParameter = ( argc >= 3 ? atoi(argv[2]) : 0 );  
    // instantiate the neighborhood selector using the neighborhood selector parameter
    NeighbourhoodSelector* selector = heuristicFactory.createNeighborhoodSelector( neighborhoodSelectorParameter );
    // instantiate the heuristic using the initial solution and the neighborhood selector
    //std::unique_ptr<LocalHeuristic> heuristic = heuristicFactory.createHeuristic( std::move( solution ), std::move( selector ) );
    // parse the input
    parser.parseInput();  

    // obtain the initial time
    timer.setInitialTime( "todo_el_codigo" );
    // obtain the initial solution

    /*************************
      Iterate over instances
    **************************/
    for(auto instance:parser.problemInstances)
    {
        /*************
         Resolution
        **************/           
        selector->initialize(instance);        

        // valores arbitrarios basados en n para criterio de terminaciones
        int n = instance->graph->nodeCount;
        int iteracionesSinMejorarCount = 0;
        int iteracionesSinMejorarMax = n;
        int iteracionesMax = n * log(n);
        int iteracionesSinInitialPathCount = 0;
        int iteracionesSinInitialPathMax = n;
        
        Solution* bestSolution = NULL; 
        // aca faltaria hacer un dijkstra por omega1, para ver que al menos existe una solucion factible

        for(int i = 0; i<iteracionesMax; i++) {    
            // instantiate the initial solution using the initial solution parameter
            InitialSolution* initialSolution =  heuristicFactory.createInitialSolution( initialSolutionParameter );        
            Solution* solution = initialSolution->getInitialSolution( instance );
            if(solution->path.size() == 0) {
                // no encontre un path entre u y v
                iteracionesSinInitialPathCount++;
                delete solution;            
                if(iteracionesSinInitialPathCount < iteracionesSinInitialPathMax) {
                    continue; // sigo intentando buscar soluciones
                } else {
                    break; // me rindo, dejo de buscar soluciones
                }            
            }

            cout << "Initial solution: ";
            solution->print();

            // El dijkstra de omega1 debe cumplir con el K, sino no tiene sentido correr la heuristica
            if(solution->totalOmega1 <= instance->K) {
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

                if(bestSolution == NULL) {
                    bestSolution = solution;
                } else if(solution->totalOmega2 > bestSolution->totalOmega2) {
                    delete bestSolution;
                    bestSolution = solution;
                } else {
                    delete solution;
                    iteracionesSinMejorarCount++;      
                }            
            }       

            if(iteracionesSinMejorarCount > iteracionesSinMejorarMax) {      
                break;
            }        
        }  

        // obtain the final time
        timer.setFinalTime( "todo_el_codigo" );

        /***************
          Output Print
        ****************/
        // print the solution
        if(bestSolution != NULL) {
            cout << "Final solution: ";
            bestSolution->print();
            delete bestSolution;
        } else {
            cout << "No se encontro ninguna solucion" << endl;
        }    
        
        // save all obtained times to output
        timer.saveAllTimes();
    }
    
    return 0;
}
