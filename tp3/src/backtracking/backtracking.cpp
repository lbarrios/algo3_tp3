#include <iostream>
#include <vector>
#include "../common/Graph.h"
#include "../common/Timer.h"
#include "../common/Dijkstra.h"
#include "../common/DijkstraSolution.h"
using namespace std;

#define INF 1<<30

Timer timer( cerr );

class Solution {
public:
    vector<Node> path;
    int totalOmega1;
    int totalOmega2;
};

ostream& operator<<(ostream& os, const Solucion &s) {
    if (s.sumaOmega2 == INF) {
        os << "no" << endl;
        return os;
    }

    os << s.sumaOmega1 << " " << s.sumaOmega2 << " " << s.cantAristas;
    for (int i = 0; i < s.camino.size(); i++)
        os << " " << s.camino[i];
    os << endl;
    return os;
}

class Backtracking_Heuristic {
public: // no te olvides el constructor
    int N, M, U, V, K;
    Graph G;
    double *distancesOmega1;
    double *distancesOmega2;
    vector<bool> visited;
    Solution bestSolutionFound;
    Solution currentBranch;

    void backtrack(Edge*); // que arranque ya con el nodo U en el camino
};

void Backtracking_Heuristic::backtrack(Edge *e) {
    Node fromNode = e->fromNode;
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
            vector<Node> adjacent = G->getAdjacent(toNode); // se pasa por referencia
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

void parseInput(Backtracking_Heuristic*);

int main() {
    while (cin >> N && N) {
        Backtracking_Heuristic *b;
        parseInput(b);
        timer.setInitialTime( "todo_el_codigo" );



        backtrack(U, U);
        timer.setFinalTime( "todo_el_codigo" );
        timer.saveAllTimes();
        cout << mejorSolucion;
    }
    return 0;
}


void parseInput(Backtracking_Heuristic *b) {
    cin >> M >> U >> V >> K;
    b->G = Graph(N);
    b->visited = vector<bool>(N+1, false);
    int v1, v2;
    double w1, w2;
    for(int i = 0; i < M; i++) {
        cin >> v1 >> v2 >> w1 >> w2;
        b->G->addEdge(v1, v2, w1, w2);
    }
    b->mejorSolucion.sumaOmega2 = INF;
    ramaActual.sumaOmega1 = 0;
    ramaActual.sumaOmega2 = 0;
    ramaActual.cantAristas = 0;
}
