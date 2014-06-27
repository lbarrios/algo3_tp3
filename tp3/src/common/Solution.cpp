#include "Solution.h"

Solution* Solution::createSubSolutionBetween(int node1, int node2) const {
	Solution* res = new Solution();
	res->totalOmega1 = 0;
	res->totalOmega2 = 0;
	bool foundNode1 = false;
	bool foundNode2 = false;
	for(unsigned int i=0; i<path.size(); i++) {
		if(!foundNode1 && node1 == path[i]->fromNode) {
			foundNode1 = true;
		} else if(!foundNode2 && node2 == path[i]->fromNode) {
			foundNode2 = true;
		}
		if(foundNode1 && foundNode2) {
			break;
		}
		if(foundNode1 || foundNode2) {
			res->path.push_back(path[i]);
			res->totalOmega1 += path[i]->omega1;
			res->totalOmega2 += path[i]->omega2;
		}
	}
	// Falta chequear si el ultimo nodo del path es alguno de los dos nodos
	// En caso de que lo sea, marco que encontre el nodo. El ultimo eje que contiene
	// a ese nodo ya fue agregado en el loop si se habia encontrado al otro nodo.
	// Si no se habia encontrado al otro nodo, entonces el path estara vacio,
	// y se retornara NULL.
	if(!foundNode1) {
		if(node1 == path[path.size()-1]->toNode) {
			foundNode1 = true;
		}
	} else if(!foundNode2) {
		if(node2 == path[path.size()-1]->toNode) {
			foundNode2 = true;
		}
	}

	if(!foundNode1 || !foundNode2) {
		delete res;
		return NULL;
	}
	return res;
}

void Solution::print()
{
  cout << totalOmega1 << " " << totalOmega2 << " ";
  for ( auto it = begin( path ); it != end( path ); ++it )
    cout << ( *it )->fromNode << " ";
  cout << endl;
}