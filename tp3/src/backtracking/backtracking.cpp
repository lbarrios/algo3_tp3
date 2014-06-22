#include <iostream>
#include <vector>
#include "../common/Graph.h"
#include "../common/Timer.h"
using namespace std;

#define INF 1<<30

Timer timer( cout );

class Solucion {
public:
    vector<Node> camino;
    int sumaOmega1;
    int sumaOmega2;
    int cantAristas;
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

int N, M, U, V, K;
Graph *G;
vector<bool> visitados;
Solucion mejorSolucion;
Solucion ramaActual;

void backtrack(Node actual, Node padre);
void tomarParametros();


int main() {
    while (cin >> N && N) {
        tomarParametros();
        timer.setInitialTime( "todo_el_codigo" );
        backtrack(U, U);
        timer.setFinalTime( "todo_el_codigo" );
        timer.saveAllTimes();
        cout << mejorSolucion;
        delete G;
    }
    return 0;
}


void tomarParametros() {
    cin >> M >> U >> V >> K;
    G = new Graph(N);
    visitados = vector<bool>(N+1, false);
    int v1, v2;
    double w1, w2;
    for(int i = 0; i < M; i++) {
        cin >> v1 >> v2 >> w1 >> w2;
        G->addEdge(v1, v2, w1, w2);
    }
    mejorSolucion.sumaOmega2 = INF;
    ramaActual.sumaOmega1 = 0;
    ramaActual.sumaOmega2 = 0;
    ramaActual.cantAristas = 0;
}


void backtrack(Node actual, Node padre) {
    // primero agrego el nodo
    ramaActual.camino.push_back(actual);

    Edge *e = G->getEdge(padre, actual);

    if (actual != padre) {  // me cubro del nodo inicial
        ramaActual.sumaOmega1 += e->omega1;
        ramaActual.sumaOmega2 += e->omega2;
    }
    ramaActual.cantAristas++;
    visitados[actual] = true;
    
    if (ramaActual.sumaOmega1 > K) {
        // no haces nada
    } else if (actual == V) { 
        if (ramaActual.sumaOmega2 < mejorSolucion.sumaOmega2)
            mejorSolucion = ramaActual;
    } else { // llamas a la recursion
        vector<Node> vecinos = G->getAdjacent(actual);
        for (int i = 0; i < vecinos.size(); i++) {
            Node vecino = vecinos[i];
            if (! visitados[vecino]) {
                backtrack(vecino, actual);
            }
        }
    }
    // dejas todo como estaba, antes de retornar
    ramaActual.camino.pop_back();
    if (actual != padre) {
        ramaActual.sumaOmega1 -= e->omega1;
        ramaActual.sumaOmega2 -= e->omega2;
    }
    ramaActual.cantAristas--;
    visitados[actual] = false;
}
