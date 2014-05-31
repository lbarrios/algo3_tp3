#include <iostream>
#include <vector>
#include "../common/Graph.h"
using namespace std;

int main()
{
  Graph g( 10 ); // creo un grafo de 10 nodos, prueba
  std::cout << g.nodeCount << std::endl;
  return 0;
}
