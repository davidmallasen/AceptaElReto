/**
 * Problema 0445: Semana de la informatica
 *
 * Fase local Ada Byron 2018. Equipo MineFinder:
 * David Mallasen Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

#define gc getchar_unlocked

using namespace std;

inline int readInt();

bool lpairfst(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

bool resuelveCaso() {
    int n;
    scanf("%i", &n);
    if (feof(stdin)) return false;

    vector<pair<int, int>> tiempos;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        p.first = readInt();
        p.second = readInt();
        tiempos.push_back(p);
    }

    sort(tiempos.begin(), tiempos.end(), lpairfst);

    vector<int> empty;
    priority_queue<int, std::vector<int>, std::greater<int>> tiemposFinales;

    int maxim = 0;
    while (!tiemposFinales.empty() || curr < tiempos.size()) {
        if (tiemposFinales.empty()) {
            tiemposFinales.push(tiempos[curr].second);
            curr++;
        } else if (curr == tiempos.size()) {
            tiemposFinales.pop();
        } else {
            if (tiempos[curr].first < tiemposFinales.top()) {
                tiemposFinales.push(tiempos[curr].second);
                curr++;
            } else {
                tiemposFinales.pop();
            }
        }
        maxim = max(maxim, (int) tiemposFinales.size());
    }

    printf("%i\n", maxim - 1);
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