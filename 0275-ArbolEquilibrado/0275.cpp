/**
 * Problema 0275: Esta el arbol equilibrado
 * David Mallasén Quintana
 */

#include <cstdio>
#include <algorithm>

#define gc getchar_unlocked

inline int readInt();

char arbol[5000];

bool estaEquilibrado(int &pos, int &altura) {
    if (arbol[pos] == '.') {
        altura = 0;
        return true;
    } else {
        int alturaIz, alturaDr;
        bool equilIz, equilDr;

        equilIz = estaEquilibrado(++pos, alturaIz);
        equilDr = estaEquilibrado(++pos, alturaDr);

        altura = std::max(alturaIz, alturaDr) + 1;

        return equilIz && equilDr && abs(alturaIz - alturaDr) <= 1;
    }
}

void resuelveCaso() {
    char c = gc();
    int n = 0;
    while (c != '\n') {
        arbol[n] = c;
        n++;
        c = gc();
    }

    int altura, pos = 0;
    if (estaEquilibrado(pos, altura))
        printf("SI\n");
    else
        printf("NO\n");
}

int main() {
    int numCasos = readInt();
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    return 0;
}


int readInt() {
    int num = 0;
    char ch = gc();

    while (ch < '0')
        ch = gc();

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}