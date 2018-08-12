/**
 * Problema 0126: Es un arbol AVL?
 * David Mallasén Quintana
 */

#include <cstdio>
#include <climits>
#include <algorithm>

#define gc getchar_unlocked

inline int readIntNeg();

bool esArbolAVL(int &altura, int &min, int &max) {
    int alturaIz, alturaDr, minIz, minDr, maxIz, maxDr;
    bool esAVLIz, esAVLDr, esBusqueda;

    int raiz = readIntNeg();

    if (raiz == -1) {
        altura = 0;
        min = INT_MAX;
        max = INT_MIN;
        return true;
    }

    esAVLIz = esArbolAVL(alturaIz, minIz, maxIz);
    esAVLDr = esArbolAVL(alturaDr, minDr, maxDr);
    altura = std::max(alturaDr, alturaIz) + 1;
    min = std::min(std::min(minDr, minIz), raiz);
    max = std::max(std::max(maxDr, maxIz), raiz);
    esBusqueda = maxIz < raiz && raiz < minDr;
    return esAVLDr && esAVLIz && esBusqueda && abs(alturaDr - alturaIz) <= 1;
}

void resuelveCaso() {
    int altura, min, max;
    if (esArbolAVL(altura, min, max))
        printf("SI\n");
    else
        printf("NO\n");
}


int main() {
    int numCasos = readIntNeg();
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    return 0;
}

int readIntNeg() {
    int num = 0;
    char ch = gc();

    while (ch < '0' && ch != '-') ch = gc();

    if (ch == '-') {
        ch = gc();
        num = -1;
    } else {
        while (ch >= '0') {
            num = 10 * num + ch - 48;
            ch = gc();
        }
    }

    return num;
}