#pragma once

#include "Solution.h"
#include "../common/ProblemInstance.h"
#include "../common/Dijkstra.h"
#include "../common/DijkstraSolution.h"

class InitialSolution
{
public:
  InitialSolution();
  virtual ~InitialSolution() = default;
  virtual Solution* getInitialSolution(ProblemInstance* instance) = 0;
  class ObjectiveFunctionOmega1
  {
  public:
      /**
       * define que operador de comparacion se usa para ordenar la lista de nodos en Dijkstra
       */
      bool operator() (const UnvisitedNode* node1, const UnvisitedNode* node2) const
      {
          return weight(node1->omega1, node1->omega2) > weight(node2->omega1, node2->omega2);
      }
      /**
       * define la funcion de peso para los ejes en Dijkstra
       */
      double weight(double omega1, double omega2) const
      {
          return omega1;
      } 
  };
};