#include "InitialSolutionC.h"

Solution* InitialSolutionC::getInitialSolution(ProblemInstance* instance)
{
	// creo el dijkstra
    Dijkstra<InitialSolution::ObjectiveFunctionOmega1> dijsktra;
    // creo la solucion
    DijkstraSolution sol( instance->graph->nodeCount, instance->u);
    // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
    dijsktra.findPath( instance->graph, &sol );
    // obtengo el path que me interesa
    Solution* solution = new Solution();    
    sol.getPath( instance->v, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2 );
    return solution;
}
