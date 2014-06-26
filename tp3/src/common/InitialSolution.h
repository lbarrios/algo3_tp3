#pragma once

#include "Solution.h"
#include "ProblemInstance.h"
#include "Dijkstra.h"
#include "DijkstraSolution.h"

class InitialSolution
{
public:
	int type;

  InitialSolution(int type);
  virtual ~InitialSolution() = default;
  virtual Solution* getInitialSolution(ProblemInstance* instance) = 0;

};