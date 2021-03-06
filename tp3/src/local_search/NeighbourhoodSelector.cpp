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

NeighbourhoodSelector::~NeighbourhoodSelector() {
  deleteMatrix();  
}

void NeighbourhoodSelector::deleteMatrix() {
  if(pathMatrix) {    
    delete pathMatrix;
    pathMatrix = NULL;
  }   
}

void NeighbourhoodSelector::initialize(ProblemInstance* instance)
{	
	deleteMatrix();
	nodeCount = instance->graph->nodeCount;
	pathMatrix = new Solution*[nodeCount*nodeCount];     
  K = instance->K;   

  // Como los paths entre j y k son iguales a los paths entre k y j, pero al reves
  // primero encuentro los paths entre j y k y luego los doy vuelta
	for(int j=1; j<=nodeCount; j++) {
  	Dijkstra<ObjectiveFunctionOmega2> dijsktra;          
    DijkstraSolution dijkstraSolution( instance->graph->nodeCount, j );                
    dijsktra.findPath( instance->graph, &dijkstraSolution );                      
    for(int k=1; k<=nodeCount; k++) {                    
      if(j==k) continue;
    	  Solution* solution = new Solution();        
    	  dijkstraSolution.getPath(k, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2);          
        // si no hay ninun path entre los nodos j y k entonces, cargo NULL en la matrix             
        pathMatrix[j-1 + (k-1) * nodeCount] = solution->path.size() > 0 ? solution : NULL;                                  
    }
	}
}

Solution* NeighbourhoodSelector::getSolvedPathBetween(int node1, int node2) {  
  return pathMatrix[node1-1 + (node2-1) * nodeCount];
}
