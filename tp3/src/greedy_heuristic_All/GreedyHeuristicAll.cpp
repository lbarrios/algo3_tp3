#include "GreedyHeuristicAll.h"

GreedyHeuristicAll::GreedyHeuristic()
{
  solution = new Solution();
}

GreedyHeuristic::GreedyHeuristic(Timer* t)
{
  solution = new Solution();
  timer = t;
}

void GreedyHeuristic::resolveInstance( ProblemInstance* instance ){
  // creo el dijkstra
  Dijkstra<ObjectiveFunction> dijsktra;
  // creo la solucion
  DijkstraSolution sol( instance->graph->nodeCount, instance->u );
  // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
  dijsktra.findPath( instance->graph, &sol );
  // obtengo el path que me interesa
  sol.getPath( instance->v, instance->graph, solution->path, solution->totalOmega1, solution->totalOmega2 );
}

void GreedyHeuristic::run()
{
  Parser parser;
  parser.parseInput();

  for ( int i = 0; i < parser.problemInstances.size(); i++ )
  {
    ProblemInstance* instance = parser.problemInstances[i];
    
    timer->setInitialTime("todo_el_codigo");
    resolveInstance( instance );       
    timer->setFinalTime("todo_el_codigo");
    timer->saveAllTimes();
    
    solution->print();
  }
}
