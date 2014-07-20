#include "BacktrackingHeuristic.h"

void BacktrackingHeuristic::parseInput(int N) {
    this->N = N;
    cin >> this->M >> this->U >> this->V >> this->K;
    this->G = new Graph(N);
    this->visited = vector<bool>(N, false);
    int v1, v2;
    double w1, w2;
    for(int i = 0; i < M; i++) {
        cin >> v1 >> v2 >> w1 >> w2;
        this->G->addEdge(v1, v2, w1, w2);
    }
}

void BacktrackingHeuristic::initialize() {
    this->currentBranch.path.push_back(this->U);
    this->bestSolutionFound.totalOmega2 = INFINITE;
    
    DijkstraSolution byOmega1(N, V);
    DijkstraSolution byOmega2(N, V);
    Dijkstra<ObjectiveFunctionA> dijsktra1; 
    Dijkstra<ObjectiveFunctionB> dijsktra2; 
    dijsktra1.findPath(this->G, &byOmega1);
    dijsktra2.findPath(this->G, &byOmega2);
    this->distancesOmega1 = byOmega1.distances;
    this->distancesOmega2 = byOmega2.distances;
}

void BacktrackingHeuristic::backtrack(Edge *e) {
    Node toNode = e->toNode;
    this->currentBranch.path.push_back(toNode);
    this->currentBranch.totalOmega1 += e->omega1;
    this->currentBranch.totalOmega2 += e->omega2;
    this->visited[toNode] = true;
    
    bool podar = ((this->currentBranch.totalOmega1 + this->distancesOmega1[toNode]) > this->K) ||
        ((this->currentBranch.totalOmega2 + this->distancesOmega2[toNode]) >= this->bestSolutionFound.totalOmega2);

    if (!podar) {
        if (toNode == this->V) {
            this->bestSolutionFound = currentBranch;
        } else {
            vector<Node> adjacent = G->getAdjacent(toNode); // se devuelve por referencia
            for (int i = 0; i < adjacent.size(); i++) {
                Node n = adjacent[i];
                if (!visited[n]) {
                    Edge *f = this->G->getEdge(toNode, n);
                    backtrack(f);
                }
            }
        }
    }

    this->currentBranch.path.pop_back();
    this->currentBranch.totalOmega1 -= e->omega1;
    this->currentBranch.totalOmega2 -= e->omega2;
    this->visited[toNode] = false;
}

void BacktrackingHeuristic::printSolution() {
    Solution *s = &(this->bestSolutionFound);
    if (s->totalOmega2 == INFINITE) {
        cout << "no" << endl;
        return;
    }

    cout << s->totalOmega1 << " " << s->totalOmega2 << " " << (s->path.size()+1);
    for (int i = 0; i < s->path.size(); i++)
        cout << " " << s->path[i];
    cout << endl;
    return;
}
