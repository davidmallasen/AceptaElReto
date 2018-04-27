/**
 * Problema 0446: Abuelas falsas
 *
 * Fase local Ada Byron 2018. Equipo MineFinder:
 * David Mallasen Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>
#include <string>

#define gc getchar_unlocked

using namespace std;

inline int readInt();

inline std::string readString();

void resuelveCaso() {
    string nieto, aux;
    nieto = readString();
    int num = readInt();

    bool esAbuela = true;
    if (num == 1) {
        aux = readString();
        esAbuela = false;
    } else {
        for (int i = 0; i < num - 1; ++i) {
            aux = readString();
            if (aux.compare(nieto) == 0) {
                esAbuela = false;
            }
        }

        if (esAbuela) {
            aux = readString();
            if (aux.compare(nieto) != 0) {
                esAbuela = false;
            }
        } else {
            aux = readString();
        }
    }
    if (esAbuela) {
        printf("VERDADERA\n");
    } else {
        printf("FALSA\n");
    }
}

int main() {
    int numCasos = readInt();
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
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

std::string readString() {
    std::string s;
    char ch = gc();
    while (ch == ' ') ch = gc();
    while (ch != ' ' && ch != '\n') {
        s.append(1, ch);
        ch = gc();
    }
    return s;
}