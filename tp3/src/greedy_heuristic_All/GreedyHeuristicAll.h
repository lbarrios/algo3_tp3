#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
#include "../common/Graph.h"
#include "../common/Parser.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"
#include "../common/Solution.h"
#include "../common/Timer.h"

using namespace std;

class GreedyHeuristicAll
{
private: 
  int _take_time;
  int _iters;
  string _save2file;
  Solution* solution;
  Timer* timer;

public:
  GreedyHeuristicAll();
  GreedyHeuristicAll(Timer*);
  void resolveInstance( ProblemInstance* );
  void run();
};


