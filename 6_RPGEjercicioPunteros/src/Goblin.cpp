#include "../include/Goblin.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Goblin::Goblin(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m) : Enemigo(n, h1, h2, v, aMin, aMax, d, nHechizos, m) {}

void Goblin::LanzarHechizo1(Personaje& objetivo) {
    int dano = (ataqueMin * 2) + (rand() % (ataqueMax - ataqueMin + 1));
    if (mana > 0) {
        objetivo.RecibirDano(dano);
        mana -= 25;
        cout << nombre << " lanza " << hechizo1 << " ocasionando " << dano << " puntos de daño a " << objetivo.getName() << endl;
    } else {
        cout << nombre << " falla al lanzar " << hechizo1 << endl;
    }
    if (mana < 0) mana = 0;
}

void Goblin::LanzarHechizo2(Personaje& objetivo) {
    if (mana > 0) {
        mana -= 15;
        inmuneProximoTurno = true;
        cout << nombre << " usa " << hechizo2 << " y se vuelve inmune al próximo ataque" << endl;
    } else {
        cout << nombre << " falla al lanzar " << hechizo2 << endl;
    }
    if (mana < 0) mana = 0;
}