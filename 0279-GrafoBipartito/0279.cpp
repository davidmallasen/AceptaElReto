/**
 * Problema 0279: Grafo bipartito
 * David Mallasén Quintana
 */

#include <cstdio>
#include <vector>

#define gc getchar_unlocked

inline int readInt();

struct Grafo {
    int V;
    std::vector<std::vector<int>> ady;

    Grafo(int v) : V(v),  ady(v) {}

    void addArista(int u, int v) {
        ady[u].push_back(v);
        ady[v].push_back(u);
    }
};

//Colores: -1 si no se ha pintado, 0 o 1 si sí
//esBipartito inicialmente a true
//Inicializar previamente el color del nodo inicial (a 0 p.ej.)
void recorridoProfundidad(const Grafo &grafo, int nodo, std::vector<int> &colorNodo, bool &esBipartito) {
    if (esBipartito) {
        for (int nodoSig : grafo.ady[nodo]) {
            if (colorNodo[nodoSig] == -1) {
                colorNodo[nodoSig] = (colorNodo[nodo] + 1) % 2;
                recorridoProfundidad(grafo, nodoSig, colorNodo, esBipartito);
            } else if (colorNodo[nodo] == colorNodo[nodoSig]) {
                esBipartito = false;
            }
        }
    }
}

bool esGrafoBipartito(Grafo &grafo) {
    std::vector<int> colorNodo(grafo.V, -1);
    bool esBipartito = true;
    int nodoAct = 0;
    while (esBipartito && nodoAct < grafo.V) {
        if (colorNodo[nodoAct] == -1) {
            colorNodo[nodoAct] = 0;
            recorridoProfundidad(grafo, nodoAct, colorNodo, esBipartito);
        }
        nodoAct++;
    }
    return esBipartito;
}

bool resuelveCaso() {
    int nVertices, nAristas;
    scanf("%i", &nVertices);
    if (feof(stdin))
        return false;

    nAristas = readInt();
    Grafo grafo(nVertices);

    int v1, v2;
    for (int i = 0; i < nAristas; ++i) {
        v1 = readInt();
        v2 = readInt();
        grafo.addArista(v1, v2);
    }

    if (esGrafoBipartito(grafo)) printf("SI\n");
    else printf("NO\n");

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}

int readInt() {
    int num = 0;
    char ch = gc();

    while (ch < '0') ch = gc();
    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}