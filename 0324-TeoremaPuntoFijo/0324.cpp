/**
 * Problema 0324: El teorema del punto fijo
 *
 * Ada Byron 2016. Equipo Compiler Error:
 * David Mallasén Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>
#include <vector>
#include <cmath>

#define gc getchar_unlocked

using namespace std;

inline int readInt();

int mcd(int a, int b) {
    while (b != 0) {
        int aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int mcd(const vector<int> &num, int start) {
    if (start < num.size() - 1) {
        int a = num[start];
        int b = mcd(num, start + 1);

        while (b != 0) {
            int aux = b;
            b = a % b;
            a = aux;
        }

        return a;
    } else {
        return num[start];
    }
}

int mcm(const vector<int> &num, int start) {
    if (start < num.size() - 1) {
        int a = num[start];
        int b = mcm(num, start + 1);
        return a * b / mcd(a, b);
    } else {
        return num[start];
    }
}

int main() {
    int mol = readInt();

    while (mol != 0) {
        vector<int> perm(mol);
        vector<bool> visited(mol);
        vector<int> tamCiclos;

        for (int i = 0; i < mol; i++)
            perm[i] = readInt() - 1;

        for (int i = 0; i < mol; i++)
            visited[i] = false;

        for (int i = 0; i < mol; i++) {
            if (!visited[i] && perm[i] != i) {
                int tam = 0;
                int nextI = perm[i];
                while (nextI != i) {
                    visited[nextI] = true;
                    nextI = perm[nextI];
                    tam++;
                }
                tam++;
                tamCiclos.push_back(tam);
            }
        }

        if (!tamCiclos.empty())
            printf("%d\n", mcm(tamCiclos, 0));
        else
            printf("1\n");

        mol = readInt();
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
