/**
 * Problema 0306: Dos igualdades sorprendentes
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

void multiplicar(long long int M1[2][2], long long int M2[2][2]);
void pow(long long int M[2][2], int n);
int fib(int n);
int readInt();

int main() {
    int n;

    n = readInt();
    while (n != 0) {
        printf("%i\n", fib(n));
        n = readInt();
    }

    return 0;
}

int fib(int n) {
    long long int M[2][2] = { { 1, 1 }, { 1, 0 } };

    if (n == 0)
        return 0;
    else {
        pow(M, n - 1);
        return M[0][0];
    }
}

void pow(long long int M[2][2], int n) {
    if (n > 1) {
        long long int M2[2][2] = { { 1, 1 }, { 1, 0 } };

        pow(M, n / 2);
        multiplicar(M, M);

        if (n % 2 != 0) {
            multiplicar(M, M2);
        }
    }
}

void multiplicar(long long int M1[2][2], long long int M2[2][2]) {
    long long int num00 = (M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0]) % 46337;
    long long int num01 = (M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1]) % 46337;
    long long int num10 = (M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0]) % 46337;
    long long int num11 = (M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1]) % 46337;

    M1[0][0] = num00;
    M1[0][1] = num01;
    M1[1][0] = num10;
    M1[1][1] = num11;
}

int readInt() {
    int num = 0;
    char ch = gc();

    while (ch < '0')
        ch = gc();
    while (ch >= '0') {
        num = num * 10 + ch - 48;
        ch = gc();
    }

    return num;
}