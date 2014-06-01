#include <iostream>
#include <vector>
#include <queue>
#include "../common/Graph.h"
#include "../common/Parser.h"
#include "../common/DijkstraSolution.h"
#include "../common/Dijkstra.h"

using namespace std;

template<class ObjectiveFunction>
class GreedyHeuristic
{
public:
	GreedyHeuristic();
	void run();
};


template<class ObjectiveFunction>
GreedyHeuristic<ObjectiveFunction>::GreedyHeuristic() 
{
	
}

template<class ObjectiveFunction>
void GreedyHeuristic<ObjectiveFunction>::run()
{
	Parser parser;
	parser.parseInput();	
	for(int i=0; i<parser.problemInstances.size(); i++) {
		ProblemInstance* instance = parser.problemInstances[0];
		// creo el dijkstra
		Dijkstra<ObjectiveFunction> dijsktra;
		// creo la solucion
	    DijkstraSolution sol(instance->graph->nodeCount);    
	    // cargo en la solucion, todos los paths del dijkstra desde el nodo inicial
	    dijsktra.findPath(instance->graph, instance->u, &sol);
	    // obtengo el path que me interesa    
	    list<Edge*> path;
	    double totalK;
	    sol.getPath(instance->v, instance->graph, path, totalK);    
	    // imprimo el path
	    if(path.size() == 0) {
	    	cout << "No se encontro el path." << endl;
	    } else if(totalK > instance->K) {
	    	cout << "Se supero el K " << totalK << "/" << instance->K << "!"<< endl;
	    	for (auto it = begin(path); it != end(path); ++it) {
		        cout << (*it)->fromNode << " -> " << (*it)->toNode << endl;
		    }
	    } else {
	    	cout << "Encontré el path:" << endl;
		    for (auto it = begin(path); it != end(path); ++it) {
		        cout << (*it)->fromNode << " -> " << (*it)->toNode << endl;
		    }
		}
	}	
}
