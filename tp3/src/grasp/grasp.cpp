#include "../common/Graph.h"
#include "../common/Parser.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"
#include "../common/DijkstraRandomized.h"
#include "../common/GreedyHeuristic.h"
#include "../common/Solution.h"
#include "../common/Parser.h"
#include "../common/Timer.h"
#include "NeighbourhoodSelectorA.h"
#include "InitialSolution.h"
#include <math.h>

Parser parser;
Timer timer( cerr );


int main( int argc, char const* argv[] ) 
{
    /* Semilla random */
    srand (time(NULL));

    /*****************
      Initialization
    ******************/
        
    
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
        NeighbourhoodSelector* selector = new NeighbourhoodSelectorA();
        selector->initialize(instance);                        

        // valores arbitrarios basados en n para criterio de terminaciones
        int n = instance->graph->nodeCount;
        int iteracionesSinMejorarCount = 0;
        int iteracionesSinMejorarMax = n;
        int iteracionesMax = n * log(n);
        int iteracionesSinInitialPathCount = 0;
        int iteracionesSinInitialPathMax = n;
        
        Solution* bestSolution = NULL;            

        for(int i = 0; i<iteracionesMax; i++) {  
            //cout <<  iteracionesSinMejorarCount << "/" << iteracionesSinMejorarMax << ", " <<
            //    i << "/" << iteracionesMax << ", " << 
            //    iteracionesSinInitialPathCount << "/" << iteracionesSinInitialPathMax << endl;
            // instantiate the initial solution using the initial solution parameter
            InitialSolution* initialSolution = new InitialSolution();        
            //cout << "aca3" << endl;    
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
            //cout << "Initial solution: ";
            //solution->print();

            // El dijkstra de omega1 debe cumplir con el K, sino no tiene sentido correr la heuristica
            if(solution->totalOmega1 <= instance->K) {                
                // run the heuristic
                Solution* newSolution = NULL;    
                bool huboMejora = false;
                do
                {                    
                    //cout << "aca" << endl;
                    newSolution = selector->getBestNeighbour( solution );                    
                    //cout << "aca2" << endl;
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

                if(bestSolution == NULL) {
                    bestSolution = solution;
                } else if(solution->totalOmega2 < bestSolution->totalOmega2) {
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
            //cout << "Final solution: ";
            bestSolution->print();
            delete bestSolution;
        } else {
            cout << "No" << endl;
        }    
        
        // save all obtained times to output
        timer.saveAllTimes();

        //delete selector;
    }    
    
    return 0;
}
