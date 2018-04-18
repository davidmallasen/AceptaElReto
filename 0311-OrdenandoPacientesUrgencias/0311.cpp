/**
 * Problema 0311: Ordenando a los pacientes en urgencias
 * David Mallasén Quintana
 */

#include <cstdio>
#include <string>
#include <queue>
#include <vector>

#define gc getchar_unlocked
#define pc putchar_unlocked

inline int readInt();

inline std::string readString();

typedef struct {
    std::string nombre;
    int gravedad;
    int tiempo;
} tElem;

class Comparador {
public:
    bool operator()(tElem a, tElem b) {
        if (a.gravedad < b.gravedad)
            return true;
        else
            return a.gravedad == b.gravedad && a.tiempo > b.tiempo;
    }
};

void colaPacientes(int nEventos) {
    char evento;
    tElem paciente;
    std::priority_queue<tElem, std::vector<tElem>, Comparador> cola;

    for (int i = 0; i < nEventos; ++i) {
        evento = gc();
        if (evento == '\n') evento = gc();
        if (evento == 'A') {
            paciente = cola.top();
            cola.pop();
            for (int i = 0; i < paciente.nombre.length(); ++i)
                pc(paciente.nombre[i]);
            pc('\n');
        } else {
            paciente.nombre = readString();
            paciente.gravedad = readInt();
            paciente.tiempo = i;
            cola.push(paciente);
        }
    }
    pc('-');pc('-');pc('-');pc('-');pc('\n');
}

bool resuelveCaso() {
    int nEventos = readInt();
    if (nEventos == 0)
        return false;

    colaPacientes(nEventos);

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

std::string readString() {
    std::string s;
    char ch = gc();
    while (ch == ' ') ch = gc();
    while (ch != ' ') {
        s.append(1, ch);
        ch = gc();
    }
    return s;
}