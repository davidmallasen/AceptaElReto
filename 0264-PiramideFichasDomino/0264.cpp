/**
 * Problema 0264: Piramide de fichas de domino
 * David Mallasén Quintana
 *
 * Idea: N = p + (p-1) + ... + (p-k+1) donde k es la altura de la piramide y
 *  p es el numero de fichas en la base de la piramide. Desarrollando:
 *  N = kp - k*(k-1)/2
 *  Damos valores a k desde sqrt(2*N) (sabemos que es cota superior de k)
 *  hasta 1 parando cuando el numero anterior "cuadre" (sea entero).
 */

#include <stdio.h>
#include <cmath>

using namespace std;

bool resuelveCaso() {
    int N;
    scanf("%d", &N);
    if (feof(stdin)) return false;

    int k = (int) floor(sqrt(2 * N));
    double p = (N / (double) k) + ((k - 1) / 2.0);

    while (p != trunc(p)) { //p no es entero
        k--;
        p = N / (double) k + (k - 1) / 2.0;
    }

    printf("%d\n", k);

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}