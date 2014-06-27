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

template<class ObjectiveFunction>
class GreedyHeuristic
{
private: 
  int _take_time;
  int _iters;
  string _save2file;
  Solution* solution;
  Timer* timer;

public:
  GreedyHeuristic();
  GreedyHeuristic(Timer*);
  void resolveInstance( ProblemInstance* );
  void run();
};


template<class ObjectiveFunction>
GreedyHeuristic<ObjectiveFunction>::GreedyHeuristic()
{
  solution = new Solution();
}

template<class ObjectiveFunction>
GreedyHeuristic<ObjectiveFunction>::GreedyHeuristic(Timer* t)
{
  solution = new Solution();
  timer = t;
}

template<class ObjectiveFunction>
void GreedyHeuristic<ObjectiveFunction>::resolveInstance( ProblemInstance* instance ){
  // creo el dijkstra
  Dijkstra<ObjectiveFunction> dijsktra;
  // creo la solucion
  DijkstraSolution sol( instance->graph->nodeCount, instance->u );
  // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
  dijsktra.findPath( instance->graph, &sol );
  // obtengo el path que me interesa
  sol.getPath( instance->v, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2 );
}

template<class ObjectiveFunction>
void GreedyHeuristic<ObjectiveFunction>::run()
{
  Parser parser;
  parser.parseInput();

  for ( int i = 0; i < parser.problemInstances.size(); i++ )
  {
    ProblemInstance* instance = parser.problemInstances[0];
    
    timer->setInitialTime("todo_el_codigo");
    resolveInstance( instance );       
    timer->setFinalTime("todo_el_codigo");
    timer->saveAllTimes();
    
    solution->print();
  }
}
