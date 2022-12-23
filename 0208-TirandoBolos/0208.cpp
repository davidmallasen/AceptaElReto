/**
 * Problema 0208: Tirando bolos
 * David Mallasén Quintana
 */

#include <cstdio>
#include <cstdint>

#define gc getchar_unlocked

inline int readInt();

inline bool resuelveCaso() {
    int64_t f, b;

    f = readInt();
    if (f == 0) 
        return false;
    b = readInt();

    int64_t n = b - 1;
    // Serie aritmetica
    int64_t cont = n * (f + f - n + 1) / 2;

    printf("%ld\n", cont);

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

