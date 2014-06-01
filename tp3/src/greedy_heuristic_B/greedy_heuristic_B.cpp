#include <iostream>
#include "../common/GreedyHeuristic.h"
#include "../common/Dijkstra.h"

using namespace std;

class ObjectiveFunction
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

int main()
{
	GreedyHeuristic<ObjectiveFunction> greedy;
	greedy.run();	
    
    return 0;
}
