/**
 * Problema 0453: Eslabones perdidos
 *
 * Fase local Ada Byron 2018. Equipo MineFinder:
 * David Mallasen Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

inline void skipLine();

bool resuelveCaso() {
    int e, r;
    e = readInt();
    if (e == 0) return false;
    r = readInt();

    for (int i = 0; i < r; ++i)
        skipLine();

    if (r == e - 1) printf("TODAS\n");
    else printf("FALTA ALGUNA\n");

    return true;
}

int main() {
    while (resuelveCaso()) {}
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

void skipLine() {
    char ch = gc();
    while (ch != '\n') ch = gc();
}