#include "../include/Orco.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Orco::Orco(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m)
    : Enemigo(n, h1, h2, v, aMin, aMax, d, nHechizos, m) {}

void Orco::LanzarHechizo1(Personaje& objetivo) {
    int dano = (ataqueMin * 1.5) + (rand() % (ataqueMax - ataqueMin + 15));
    if (mana > 0) {
        objetivo.RecibirDano(dano);
        mana -= 30;
        cout << nombre << " lanza " << hechizo1 << " ocasionando " << dano << " puntos de daño a " << objetivo.getName() << endl;
    } else {
        cout << nombre << " falla al lanzar " << hechizo1 << endl;
    }
    if (mana < 0) mana = 0;
}

void Orco::LanzarHechizo2(Personaje& objetivo) {
    if (mana > 0) {
        objetivo.RecibirDano(35);
        mana -= 20;
        cout << nombre << " lanza " << hechizo2 << " ocasionando 50 puntos de daño a " << objetivo.getName() << endl;
    } else {
        cout << nombre << " falla al lanzar " << hechizo2 << endl;
    }
    if (mana < 0) mana = 0;
}
