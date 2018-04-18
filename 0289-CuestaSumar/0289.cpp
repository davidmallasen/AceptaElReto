/**
 * Problema 0289: Lo que cuesta sumar
 * David Mallasén Quintana
 */

#include <cstdio>
#include <queue>
#include <vector>

#define lli long long int
#define gc getchar_unlocked

lli entrada [100000];

inline int readInt();

lli loQueCuestaSumar(int nSumandos) {
    lli elem, elem2;
    lli sumaTotal;
    std::priority_queue<lli, std::vector<lli>, std::greater<lli>> cola;

    for (int i = 0; i < nSumandos; ++i) {
        entrada[i] = readInt();
    }

    for (int i = 0; i < nSumandos; ++i) {
        cola.push(entrada[i]);
    }

    sumaTotal = 0;
    while (cola.size() > 1) {
        elem = cola.top();
        cola.pop();
        elem2 = cola.top();
        cola.pop();
        sumaTotal += elem + elem2;
        cola.push(elem + elem2);
    }

    return sumaTotal;
}

bool resuelveCaso() {
    int nSumandos = readInt();
    if (nSumandos == 0)
        return false;

    printf("%lli\n", loQueCuestaSumar(nSumandos));
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