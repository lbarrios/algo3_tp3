#include "local_search.h"
#include "../common/Graph.h"
#include "../common/Parser.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"
#include "../common/GreedyHeuristic.h"

HeuristicFactory heuristicFactory;
Parser parser;
Timer timer( cerr );

struct ShortestPath
{
  double totalOmega1;
  double totalOmega2;
  list<Edge*> path;
};


class ObjectiveFunctionOmega1
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
        return omega1;
    } 
};


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

ShortestPath* createShortestPathMatrix(ProblemInstance* instance) {
  int n = instance->graph->nodeCount;
  ShortestPath* matrix = new ShortestPath[n*n];    
  for(int j=1; j<=n; j++) {
    Dijkstra<ObjectiveFunctionOmega2> dijsktra;    
    DijkstraSolution sol( instance->graph->nodeCount, j );    
    dijsktra.findPath( instance->graph, &sol );
    for(int k=1; k<=n; k++) {        
      ShortestPath* shortestPath = &matrix[j-1 + (k-1) * n];
      sol.getPath(k, instance->graph, shortestPath->path, shortestPath->totalOmega1, shortestPath->totalOmega2);
    }
  }
  return matrix;
}


int main( int argc, char const* argv[] )
{
  /*****************
    Initialization
  ******************/
  // get console parameters
  const char* initialSolutionParameter = ( argc >= 2 ? argv[1] : NULL );
  const char* neighborhoodSelectorParameter = ( argc >= 3 ? argv[2] : NULL );
  // instantiate the initial solution using the initial solution parameter
  std::unique_ptr<InitialSolution> solution =  heuristicFactory.createInitialSolution( initialSolutionParameter );
  // instantiate the neighborhood selector using the neighborhood selector parameter
  std::unique_ptr<NeighborhoodSelector> selector = heuristicFactory.createNeighborhoodSelector( neighborhoodSelectorParameter );
  // instantiate the heuristic using the initial solution and the neighborhood selector
  std::unique_ptr<LocalHeuristic> heuristic = heuristicFactory.createHeuristic( std::move( solution ), std::move( selector ) );
  // parse the input
  parser.parseInput();
  /*************************
    Iterate over instances
  **************************/
  for(auto instance:parser.problemInstances)
  {
    /*************
      Resolution
    **************/
    // obtain the initial time
    timer.setInitialTime( "todo_el_codigo" );
    // run the heuristic
    /*
    solution = heuristic.run( instance );
    */


    // creo el dijkstra
    Dijkstra<ObjectiveFunctionOmega1> dijsktra;
    // creo la solucion
    DijkstraSolution sol( instance->graph->nodeCount, instance->u);
    // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
    dijsktra.findPath( instance->graph, &sol );
    // obtengo el path que me interesa
    list<Edge*> path;
    double totalOmega1;
    double totalOmega2;
    sol.getPath( instance->v, instance->graph, path, totalOmega1, totalOmega2 );



    ShortestPath* matrix = createShortestPathMatrix(instance);

    int n = instance->graph->nodeCount;
    for(int j=1; j<=n; j++) {
      for(int k=1; k<=n; k++) {        
        ShortestPath sPath = matrix[(j-1)+ (k-1) * n];
        /*cout << j << " -> " << k << ": ";
        cout << "Omega1: " << sPath.totalOmega1 << ", Omega2: " << sPath.totalOmega2 << endl;
        cout << "Path: ";
        for ( auto it = begin( sPath.path ); it != end( sPath.path ); ++it )
        {
          cout << ( *it )->fromNode << " -> " << ( *it )->toNode << ", ";
        }
        cout << endl << endl;*/
      }
    }

    // obtain the final time
    timer.setFinalTime( "todo_el_codigo" );
    /***************
      Output Print
    ****************/
    /*
      code to print result
    */
    // save all obtained times to output
    timer.saveAllTimes();
  }
  return 0;
}
