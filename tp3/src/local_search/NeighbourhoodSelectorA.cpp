#include "NeighbourhoodSelectorA.h"


Solution* createNewSolutionReplacingPath(const Solution* orig, const Solution* sub) {
  int node1 = sub->path[0]->fromNode;
  int node2 = sub->path[sub->path.size()-1]->toNode;
  Solution* res = new Solution();
  vector<Edge*> edgesToRemove;
  bool subPathStartsAtNode1 = false;
  int subPathStartsAtEdgeIndex = 0;
  // primero agrego todos los edges del path original hasta encontrar alguno de los nodos del subpath
  for(int i=0; i<orig->path.size(); i++) {
    Edge* edge = orig->path[i];
    if(edge->fromNode == node1 || edge->fromNode == node2) {
      subPathStartsAtNode1 = edge->fromNode == node1;
      subPathStartsAtEdgeIndex = i;
      break;
    } else {
      res->path.push_back(edge);
      res->totalOmega1 += edge->omega1;
      res->totalOmega2 += edge->omega2;
    }
  }

  // agrego todos los ejes del sub path
  for(int i=0; i<sub->path.size(); i++) {
    Edge* edge = sub->path[i];
    res->path.push_back(edge);
    res->totalOmega1 += edge->omega1;
    res->totalOmega2 += edge->omega2;
  }

  // busco el nodo desde donde continua el pedazo del path original
  // agrego todos los ejes del path original a partir de ahi
  int fromNode = subPathStartsAtNode1 ? node2 : node1;
  bool addEdges = false;
  for(int i=subPathStartsAtEdgeIndex+1; i<orig->path.size(); i++) {
    Edge* edge = orig->path[i];
    if(edge->fromNode == fromNode) {
      addEdges = true; // encontre el nodo, asi que comienzo a añadir los nodos desde aca
    }
    if(addEdges) {
      res->path.push_back(edge);
      res->totalOmega1 += edge->omega1;
      res->totalOmega2 += edge->omega2;
    }
  }

  return res;
}

Solution* NeighbourhoodSelectorA::getBestNeighbour(const Solution* origSolution)
{ 
  // Itero sobre la matriz de soluciones
  // Por cada par de nodos, tengo que buscar si existe un path en la matriz, 
  // tal que sustituyendolo pot path entre el par de nodos de la solucion original 
  // se obtenga una nueva solucion tal que se su totalOmega2 sea menor
  
  // Nota: Habiamos pensado en usar DeltaOmega2, pero si K es muy grande,
  // nos sobraria mucho K que podriamos haber usado para sustituir en cada paso
  // por un path con minimo omega2                
  
  // El path de una solution es un vector de ejes   
  // En cada iteracion que encuentro una solucion mejor, voy a cambiar algunos de los nodos, 
  // por lo que tengo que recalcular los nodos de la mejor solucion           
  int edgesCount = origSolution->path.size();
  int nodesCount = edgesCount+1;
  vector<int> nodes(nodesCount); 
  for(int i=0; i<edgesCount; i++) {
    Edge* edge = origSolution->path[i];
    nodes[i] = edge->fromNode;
  }
  nodes[nodesCount-1] = origSolution->path[edgesCount-1]->toNode; // ultimo nodo del path
  //cout << endl;
      
  Solution* bestSolution = NULL;
  for(int i=0; i<nodes.size() - 1; i++) {    
    for(int j=i+1; j<nodes.size(); j++) {           
      Solution* subSolution = origSolution->createSubSolutionBetween(nodes[i], nodes[j]); // solution con sub path entre los nodos
      if(subSolution == NULL) continue; // puede fallar o esto esta demas?      
      Solution* solution_ij = getSolvedPathBetween(nodes[i], nodes[j]); // dijkstra por omega2 entre los nodos
      if(solution_ij == NULL) {
        continue;
      }      
      /*cout << "Between (" << nodes[i] << ", " << nodes[j] << "):" << endl;
      cout << "subSolution: ";
      subSolution->print();
      cout << "solution_ij: ";
      solution_ij->print();*/
      
      // Si el path creado con dijkstra usando omega2, tiene menos omega2 total, que el path actual entre
      // los nodos i y j, entonces chequeo si al crear una nueva solucion tendra menos omega2 que la mejor solucion.
      // En ese caso me guardo esta nueva solucion como la mejor hasta ahora.
      // Ademas chequeo que se cumpla con el K requerido.                          
      double bestSolutionOmega2 = bestSolution == NULL ? origSolution->totalOmega2 : bestSolution->totalOmega2;
      double newSolutionOmega2 = origSolution->totalOmega2 - subSolution->totalOmega2 + solution_ij->totalOmega2;
      double newSolutionOmega1 = origSolution->totalOmega1 - subSolution->totalOmega1 + solution_ij->totalOmega1;      
      if(newSolutionOmega2 < bestSolutionOmega2 && newSolutionOmega1 <= K) {             
        if(bestSolution != NULL) {
          delete bestSolution;   
        }       
        // creo la nueva mejor solucion
        bestSolution = createNewSolutionReplacingPath(origSolution, solution_ij);            
        //cout << "hubo mejora!" << endl;
        //cout << "bestSolution: ";
        //bestSolution->print();
      }      
      delete subSolution;

      //cout << endl;      
    }
  }
    
  return bestSolution;  
}

