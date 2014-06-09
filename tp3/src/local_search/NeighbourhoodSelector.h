#pragma once

#include "../common/ProblemInstance.h"
#include "Solution.h"

class NeighbourhoodSelector
{	
protected:
	int nodeCount;
	Solution* pathMatrix; // Matriz de paths. Cada elemento es un path entre dos nodos. 
						  // Son de tipo Solution pero no significa que sean soluciones. 
						  // Los unicos elementos de la matriz que son soluciones, son los 2 caminos entre u y v.
public:
  NeighbourhoodSelector();
  virtual ~NeighbourhoodSelector() = default;

  virtual Solution* getBestNeighbour(Solution* solution) = 0;

  void initialize(ProblemInstance* instance);
};