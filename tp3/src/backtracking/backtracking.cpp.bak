#include <iostream>
#include <vector>
#include "../common/Graph.h"
using namespace std;

#define INF 1<<30;

struct Solucion {
    vector<int> camino;
    int sumaOmega1;
    int sumaOmega2;
    int cantAristas;
};

int N, M, U, V, K;
Graph *G;
vector<bool> visitados;
Solucion mejorSolucion;
Solucion ramaActual;

void backtrack(Edge *e);
void tomarParametros();


int main() {
    tomarParametros();
    backtrack(NULL);
    cout << mejorSolucion.sumaOmega2 << endl; // definir el cout
    delete G;
    return 0;
}


void tomarParametros() {
    cin >> N >> M >> U >> V >> K;
    G = new Graph(N);
    for(int i = 0; i < N; i++)
        visitados[i] = false;
    int v1, v2;
    double w1, w2;
    for(int i = 0; i < M; i++) {
        cin >> v1 >> v2 >> w1 >> w2;
        G->connect(v1, v2, w1, w2);
    }
    mejorSolucion.sumaOmega2 = INF;
    ramaActual.sumaOmega1 = 0;
    ramaActual.sumaOmega2 = 0;
    ramaActual.cantAristas = 0;
}


void backtrack(Edge *e) {
    int nodo;
    if (e = NULL)
        nodo = U;
    else
        nodo = e->toNode;
    // primero agrego el nodo
    ramaActual.camino.push_back(nodo);
    if (e != NULL) {  // me cubro del nodo inicial
        ramaActual.sumaOmega1 += e->omega1;
        ramaActual.sumaOmega2 += e->omega2;
    }
    ramaActual.cantAristas++;
    visitados[nodo] = true;
    
    if (ramaActual.sumaOmega1 > K) {
        // no haces nada
    } else if (nodo == V) { 
        if (ramaActual.sumaOmega2 < mejorSolucion.sumaOmega2)
            mejorSolucion = ramaActual;
    } else { // llamas a la recursion
        vector<Edge*> *ejesSalida;
        G->getEdgesFromNode(nodo, ejesSalida);
        for (vector<Edge*>::iterator it = ejesSalida->begin(); it != ejesSalida->end(); it++) {
            int nodoDeLlegada = (*it)->toNode;
            if (! visitados[nodoDeLlegada]) {
                backtrack(*it);
            }
        }
    }
    // dejas todo como estaba, antes de retornar
    ramaActual.camino.pop_back();
    if (e != NULL) {
        ramaActual.sumaOmega1 -= e->omega1;
        ramaActual.sumaOmega2 -= e->omega2;
    }
    ramaActual.cantAristas--;
    visitados[nodo] = false;
}
