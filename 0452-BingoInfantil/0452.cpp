/**
 * Problema 0452: Bingo infantil
 *
 * Fase local Ada Byron 2018. Equipo MineFinder:
 * David Mallasen Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define gc getchar_unlocked

inline int readInt();

bool resuelveCaso() {
    int num, numResultados;
    num = readInt();
    if (num == 0) return false;

    std::vector<bool> aparecidos(2001, false);
    std::vector<int> numeros(num);
    std::vector<int> resultados;
    for (int i = 0; i < num; ++i) {
        numeros[i] = readInt();
    }
    numResultados = 0;
    for (int i = 0; i < num - 1; ++i) {
        for (int j = i + 1; j < num; ++j) {
            int dif = std::max(numeros[i], numeros[j]) - std::min(numeros[i], numeros[j]);
            if (!aparecidos[dif]) {
                aparecidos[dif] = true;
                resultados.push_back(dif);
                numResultados++;
            }
        }
    }
    std::sort(resultados.begin(), resultados.end());
    printf("%i", resultados[0]);
    for (int i = 1; i < numResultados; ++i) {
        printf(" %i", resultados[i]);
    }
    printf("\n");

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