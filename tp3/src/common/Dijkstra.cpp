#include "Dijkstra.h"

#define INF std::numeric_limits<double>::max()

Dijkstra::Dijkstra() {
}

void Dijkstra::findPath(Graph* graph, int fromNode, DijkstraSolution* solution) {
    int* prevNodes = solution->prevNodes;
    double* dist = solution->dist;
    for (int i=0; i<graph->n; i++) {
        dist[i] = INF;
        prevNodes[i] = -1;
    }
    dist[fromNode] = 0;
    
    UnvisitedPQ unvisited;
    unvisited.push(fromNode);
    
    while (unvisited.size() > 0) {
        int fromNode = unvisited.top();
        unvisited.pop(); // O(log(n^2)) = O(log(n))
        
        vector<int> adjNodes;
        graph->getAdjacentNodes(fromNode, &adjNodes);
        for (int i=0; i<adjNodes.size(); i++) {
            int toNode = adjNodes[i];
            if(dist[fromNode] + 1 < dist[toNode]) {
                prevNodes[toNode] = fromNode;
                dist[toNode] = dist[fromNode] + 1;
                unvisited.push(toNode);
            }
        }
    }
}