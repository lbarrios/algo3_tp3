#include <iostream>
#include <vector>
using namespace std;

struct Solucion {
    vector<int> camino;
    int sumaOmega1;
    int sumaOmega2;
    int cantAristas;
};

int u, v;
vector<bool> visitados;
Solucion mejorSolucion;
Solucion ramaActual;

void backtrack(int nodoActual, Solucion &s);

int main() {
    for (int i = 0; i < n; i++)
        visitados[i] = false;
    // tambien inicializa mejorSolucion, y ramaActual
    backtrack(u, 0);
    cout << mejorSolucion; // definir el cout
    return 0;
}

void backtrack(int nodoActual, int nodoPadre) {
    // primero agrego el nodoActual
    ramaActual.camino.push_back(nodoActual);
    ramaActual.sumaOmega1 += arista[nodoPadre][nodoActual].omega1; // definir bien para el padre de u
    ramaActual.sumaOmega2 += arista[nodoPadre][nodoActual].omega2; // definir bien para el padre de u
    ramaActual.cantAristas++;
    visitados[nodoActual] = true;
    
    if (ramaActual.sumaOmega1 > K) {
        // no haces nada
    } else if (nodoActual == v) { 
        if (ramaActual.sumaOmega2 < mejorSolucion.sumaOmega2)
            mejorSolucion = ramaActual;
    } else { // llamas a la recursion
        vector<int> adyacentes = adyacentes(nodoActual);
        for (vector<int>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++) {
            if (! visitados[*it]) {
                backtrack(*it, nodoActual);
            }
        }
    }
    // dejas todo como estaba, antes de retornar
    ramaActual.camino.pop_back();
    ramaActual.sumaOmega1 -= arista[nodoPadre][nodoActual].omega1; // definir bien para el padre de u
    ramaActual.sumaOmega2 -= arista[nodoPadre][nodoActual].omega2; // definir bien para el padre de u
    ramaActual.cantAristas--;
    visitados[nodoActual] = false;
}
