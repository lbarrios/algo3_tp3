#include "InitialSolutionG_C.h"
#include "../common/ObjectiveFunctions.h"
#include "../common/DijkstraRandomized.h"

InitialSolutionG_C::InitialSolutionG_C(int type) : InitialSolution(type) {}

Solution* InitialSolutionG_C::getInitialSolution(ProblemInstance* instance)
{
	// creo el dijkstra
    DijkstraRandomized<ObjectiveFunctionC> dijsktraRandom;
    // creo la solucion
    DijkstraSolution dijkstraSolution( instance->graph->nodeCount, instance->u);
    // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
    dijsktraRandom.findPath( instance->graph, &dijkstraSolution );
    // obtengo el path que me interesa
    Solution* solution = new Solution();    
    dijkstraSolution.getPath( instance->v, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2 );
    return solution;
}
