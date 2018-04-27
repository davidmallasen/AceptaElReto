/**
 * Problema 0448: El mejor de dos dados
 *
 * Fase local Ada Byron 2018. Equipo MineFinder:
 * David Mallasen Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>
#include <vector>
#include <algorithm>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int n, aux;

    n = readInt();
    while (n > 0) {
        std::vector<int> dado1, dado2;

        for (int i = 0; i < n; i++) {
            aux = readInt();
            dado1.push_back(aux);
        }

        for (int i = 0; i < n; i++) {
            aux = readInt();
            dado2.push_back(aux);
        }

        std::sort(dado1.begin(), dado1.end());
        std::sort(dado2.begin(), dado2.end());

        int i = 0, j = 0, inr = 0, jnr = 0;
        int suma1 = 0, suma2 = 0;
        while (i < n || j < n) {
            if (j == n || (i < n && dado1[i] < dado2[j])) {
                suma1 += j;
                i++;
                inr = i;
            } else if (i == n || (j < n && dado1[i] > dado2[j])) {
                suma2 += i;
                j++;
                jnr = j;
            } else {
                // dado1[i] = dado2[j]
                int repe = (i < n) ? dado1[i] : dado2[j];
                while (i < n && dado1[i] == repe) {
                    i++;
                    suma1 += jnr;
                }
                while (j < n && dado2[j] == repe) {
                    j++;
                    suma2 += inr;
                }

                inr = i;
                jnr = j;
            }
        }

        if (suma1 > suma2)
            printf("PRIMERO\n");
        else if (suma1 == suma2)
            printf("NO HAY DIFERENCIA\n");
        else
            printf("SEGUNDO\n");


        n = readInt();
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