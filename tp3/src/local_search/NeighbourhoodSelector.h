#pragma once

#include "../common/ProblemInstance.h"
#include "Solution.h"

class NeighbourhoodSelector
{	
	void deleteMatrix();
protected:
	int nodeCount;
	Solution** pathMatrix; // Matriz de paths. Cada elemento es un path entre dos nodos. 
						  // Son de tipo Solution pero no significa que sean soluciones. 
						  // Los unicos elementos de la matriz que son soluciones, son los 2 caminos entre u y v.
	int K;
public:
  NeighbourhoodSelector();
  virtual ~NeighbourhoodSelector();

  virtual Solution* getBestNeighbour(const Solution* solution) = 0;
  Solution* getSolvedPathBetween(int node1, int node2);

  void initialize(ProblemInstance* instance);  
};