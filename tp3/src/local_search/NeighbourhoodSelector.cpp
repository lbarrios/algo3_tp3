#include "NeighbourhoodSelector.h"
#include "../common/Dijkstra.h"

class ObjectiveFunctionOmega2
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
        return omega2;
    } 
};


NeighbourhoodSelector::NeighbourhoodSelector() 
{
	pathMatrix = NULL;
}

void NeighbourhoodSelector::initialize(ProblemInstance* instance)
{	

	if(pathMatrix) {
		delete pathMatrix;
	}
  	nodeCount = instance->graph->nodeCount;
  	pathMatrix = new Solution[nodeCount*nodeCount];        

  	for(int j=1; j<=nodeCount; j++) {
    	Dijkstra<ObjectiveFunctionOmega2> dijsktra;          
	    DijkstraSolution sol( instance->graph->nodeCount, j );                
	    dijsktra.findPath( instance->graph, &sol );                  
	    for(int k=1; k<=nodeCount; k++) {        
	    	  Solution* solution = &pathMatrix[j-1 + (k-1) * nodeCount];                    
	    	  sol.getPath(k, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2);          
	    }

  	}
}