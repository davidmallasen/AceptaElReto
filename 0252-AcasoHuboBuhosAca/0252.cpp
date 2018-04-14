/**
 * Problema 0252: Acaso hubo buhos aca
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

int main() {
    char pal[101];
    char ch = '\0';
    bool ok;
    int i, j;

    for (i = 0; ch != '\n'; i++) {
        ch = gc();
        pal[i] = ch;
    }
    i -= 2;

    while (pal[0] != 'X' || pal[1] != 'X' || pal[2] != 'X' || pal[3] != '\n') {
        for (j = 0; j <= i; j++)     //Quita mayusculas
            if (pal[j] >= 'A' && pal[j] <= 'Z') pal[j] += 32;

        ok = true;
        for (j = 0, i; i > j && ok; j++, i--) {
            while (pal[i] == ' ') i--;
            while (pal[j] == ' ') j++;
            if (pal[i] != pal[j]) ok = false;
        }

        if (ok) printf("SI\n");
        else printf("NO\n");

        ch = '\0';
        for (i = 0; ch != '\n'; i++) {
            ch = gc();
            pal[i] = ch;
        }
        i -= 2;
    }

    return 0;
}