/**
 * Problema 0449: Trim
 *
 * Fase local Ada Byron 2018. Equipo MineFinder:
 * David Mallasen Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define gc getchar_unlocked

bool resuelveCaso() {
    char aux;
    vector<char> palabra;
    aux = gc();

    if (aux == EOF) return false;

    while (aux != '\n') {
        if (palabra.empty() || (!palabra.empty() && palabra.back() != aux)) {
            palabra.push_back(aux);
        }
        aux = gc();
    }

    int n = palabra.size();
    vector<vector<int>> m(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        m[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        m[i][i + 1] = (palabra[i] == palabra[i + 1]) ? 1 : 2;
    }

    for (int d = 2; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            int j = i + d;
            if (j - i >= 2 && palabra[i] == palabra[j]) {
                m[i][j] = 1 + m[i + 1][j - 1];
            } else {
                m[i][j] = 1 + min(m[i][j - 1], m[i + 1][j]);
            }
        }
    }

    printf("%i\n", m[0][n - 1]);

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}