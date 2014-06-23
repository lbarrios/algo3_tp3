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

public:
  GreedyHeuristic();
  GreedyHeuristic(int take_time, int iters, string save2file);
  void resolveInstance( ProblemInstance* );
  void run();
};


template<class ObjectiveFunction>
GreedyHeuristic<ObjectiveFunction>::GreedyHeuristic()
{
  solution = new Solution();
}

template<class ObjectiveFunction>
GreedyHeuristic<ObjectiveFunction>::GreedyHeuristic(int take_time, int iters, string save2file)
{
  solution = new Solution();
  _take_time = take_time;
  _iters = iters;
  _save2file = save2file;
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

    if( _take_time ){
      ofstream fs;
      fs.open( _save2file, std::ofstream::app ); // apend
      Timer timer(cerr);
      
      timer.setInitialTime("resolver");
      for( int i = 0; i < _iters; i++ ){
        resolveInstance( instance ); 
      }
      timer.setFinalTime("resolver");

      fs << instance->countNodes() << "\t" 
         << instance->countEdges() << "\t"
         << instance->K << "\t"
         << timer.getTime("resolver") / _iters << endl;

    }
    resolveInstance( instance ); 

    solution->print();
  }
}
