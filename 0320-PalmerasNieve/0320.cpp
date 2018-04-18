/**
 * Problema 0320: Palmeras en la nieve
 *
 * Ada Byron 2016. Equipo Compiler Error:
 * David Mallasén Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>
#include <queue>

#define gc getchar_unlocked

inline int readInt();

int v[100010];

int main() {
    int casos = readInt();
    for (int c = 0; c < casos; c++) {
        int pCaido, nPalm;
        std::priority_queue<int, std::vector<int>, std::greater<int>> ultimos;

        pCaido = readInt();
        nPalm = readInt();

        for (int j = 0; j < nPalm; ++j)
            v[j] = readInt();

        int longitud = 0, longMax = 0;

        for (int j = 0; j < nPalm; ++j) {
            longitud++;
            if (v[j] - pCaido >= 0) {
                ultimos.push(j);
            }
            if (ultimos.size() > 5) {
                longitud = j - ultimos.top();
                ultimos.pop();
            } else if (longitud > longMax) {
                longMax = longitud;
            }
        }
        printf("%i\n", longMax);
    }

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