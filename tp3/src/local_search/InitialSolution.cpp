#include "InitialSolution.h"
#include "../common/ObjectiveFunctions.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"

InitialSolution::InitialSolution() {}

Solution* createSolutionA(ProblemInstance* instance) 
{    
    // creo el dijkstra
    Dijkstra<ObjectiveFunctionA> dijsktra;
    // creo la solucion
    DijkstraSolution dijkstraSolution( instance->graph->nodeCount, instance->u);
    // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
    dijsktra.findPath( instance->graph, &dijkstraSolution );
    // obtengo el path que me interesa
    Solution* solution = new Solution();    
    dijkstraSolution.getPath( instance->v, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2 );
    return solution;
}

Solution* createSolutionB(ProblemInstance* instance) 
{
    // creo el dijkstra    
    Dijkstra<ObjectiveFunctionB> dijsktra;
    // creo la solucion
    DijkstraSolution dijkstraSolution( instance->graph->nodeCount, instance->u);
    // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
    dijsktra.findPath( instance->graph, &dijkstraSolution );
    // obtengo el path que me interesa
    Solution* solution = new Solution();    
    dijkstraSolution.getPath( instance->v, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2 );
    return solution;
}

Solution* createSolutionC(ProblemInstance* instance) 
{
    // creo el dijkstra    
    Dijkstra<ObjectiveFunctionC> dijsktra;
    // creo la solucion
    DijkstraSolution dijkstraSolution( instance->graph->nodeCount, instance->u);
    // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
    dijsktra.findPath( instance->graph, &dijkstraSolution );
    // obtengo el path que me interesa
    Solution* solution = new Solution();    
    dijkstraSolution.getPath( instance->v, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2 );
    return solution;
}

Solution* InitialSolution::getInitialSolution(ProblemInstance* instance)
{   
    Solution* solutionB = createSolutionB(instance);    
    if(solutionB->totalOmega1 <= instance->K) {
        return solutionB;
    }
    // si la solucion no es factible probamos con otras funciones objetivo    
    Solution* solutionA = createSolutionA(instance);
    Solution* solutionC = createSolutionC(instance);
    if(solutionC->totalOmega1 <= instance->K) {
        if(solutionA->totalOmega2 < solutionC->totalOmega2) {
            return solutionA;
        } 
        return solutionC;
    }
    if(solutionA->totalOmega2 <= instance->K) {
        return solutionA;
    }
    return NULL;    
}