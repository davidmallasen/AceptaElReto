/**
 * Problema 0116: Hola Mundo!
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

int main() {
    for (char ch = gc(); ch > 48; ch--)
        printf("Hola mundo.\n");

    return 0;
}