#include "../include/Dragon.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Dragon::Dragon(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m) : Enemigo(n, h1, h2, v, aMin, aMax, d, nHechizos, m) {}

void Dragon::LanzarHechizo1(Personaje& objetivo) {
    if (mana > 0) {
        objetivo.RecibirDano(75);
        mana -= 50;
        cout << nombre << " lanza " << hechizo1 << " ocasionando 75 puntos de daño a " << objetivo.getName() << endl;
    } else {
        cout << nombre << " falla al lanzar " << hechizo1 << endl;
    }
    if (mana < 0) mana = 0;
}

void Dragon::LanzarHechizo2(Personaje& objetivo) {
    if (mana > 0) {
        mana -= 25;
        objetivo.setEstadosPorTurno(3);
        cout << nombre << " lanza " << hechizo2 << ". " << objetivo.getName() << " arderá durante 3 turnos." << endl;
    } else {
        cout << nombre << " falla al lanzar " << hechizo2 << endl;
    }
    if (mana < 0) mana = 0;
}
