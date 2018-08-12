/**
 * Problema 0307: Arboles libres
 * David Mallasén Quintana
 */

#include <cstdio>
#include <vector>
#include <queue>

#define gc getchar_unlocked

inline int readInt();

struct Grafo {
    int nVertices;
    std::vector<std::vector<int>> ady;

    Grafo(int nVertices) : nVertices{nVertices}, ady(nVertices) {}
};

void recorridoProfundidad(const Grafo &grafo, int nodo, std::vector<bool>
&marcas, std::vector<int> &ultimoNodo, bool &hayCiclo) {
    marcas[nodo] = true;
    if (!hayCiclo) {
        for (int nodoSig : grafo.ady[nodo]) {
            if (!marcas[nodoSig]) {
                ultimoNodo[nodoSig] = nodo;
                recorridoProfundidad(grafo, nodoSig, marcas, ultimoNodo,
                                     hayCiclo);
            } else if (marcas[nodoSig] && ultimoNodo[nodo] != nodoSig) {
                hayCiclo = true;
            }
        }
    }
}

bool esArbolLibre(const Grafo &grafo) {
    std::vector<bool> marcas(grafo.nVertices, false);
    std::vector<int> ultimoNodo(grafo.nVertices);
    int nodoIni = 0;
    bool hayCiclo = false;

    recorridoProfundidad(grafo, nodoIni, marcas, ultimoNodo, hayCiclo);

    if (hayCiclo) {
        return false;
    } else {
        for (bool conectado : marcas) {
            if (!conectado) {
                return false;
            }
        }
        return true;
    }
}

bool resuelveCaso() {
    int nVertices, nAristas;

    scanf("%d", &nVertices);
    if (feof(stdin)) return false;

    nAristas = readInt();

    Grafo grafo(nVertices);
    int v1, v2;
    for (int i = 0; i < nAristas; ++i) {
        v1 = readInt();
        v2 = readInt();
        grafo.ady[v1].push_back(v2);
        grafo.ady[v2].push_back(v1);
    }

    if (esArbolLibre(grafo))
        printf("SI\n");
    else
        printf("NO\n");

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}

int readInt() {
    char ch = gc();
    int num = 0;

    while (ch < '0') ch = gc();

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}