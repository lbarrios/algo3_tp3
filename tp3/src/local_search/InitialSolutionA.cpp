#include "InitialSolutionA.h"
#include "../common/Dijkstra.h"
#include "../common/DijkstraSolution.h"

class ObjectiveFunctionOmega1
{
public:
    bool operator() (const UnvisitedNode* node1, const UnvisitedNode* node2) const
    {
      // define que operador de comparacion se usa para ordenar la lista de nodos en Dijkstra
        return weight(node1->omega1, node1->omega2) > weight(node2->omega1, node2->omega2);
    }

    double weight(double omega1, double omega2) const
    {
      // define la funcion de peso para los ejes en Dijkstra
        return omega1;
    } 
};

Solution* InitialSolutionA::getInitialSolution(ProblemInstance* instance)
{
	// creo el dijkstra
    Dijkstra<ObjectiveFunctionOmega1> dijsktra;
    // creo la solucion
    DijkstraSolution sol( instance->graph->nodeCount, instance->u);
    // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
    dijsktra.findPath( instance->graph, &sol );
    // obtengo el path que me interesa
    Solution* solution = new Solution();    
    sol.getPath( instance->v, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2 );
    return solution;
}