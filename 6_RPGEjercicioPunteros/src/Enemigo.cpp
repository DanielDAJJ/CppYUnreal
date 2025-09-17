#include "../include/Enemigo.h"
#include <iostream>
using namespace std;

Enemigo::Enemigo(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m)
    : Personaje(n, h1, h2, v, aMin, aMax, d, nHechizos, m) {}

void Enemigo::Atacar(Personaje& objetivo) {
    int dano = ataqueMin + (rand() % (ataqueMax - ataqueMin + 1));
    cout << nombre << " ataca a " << objetivo.getName() << " causando " << dano << " puntos de daño." << endl;
    objetivo.RecibirDano(dano);
}

void Enemigo::LanzarHechizo1(Personaje& objetivo) {
    cout << nombre << " lanza " << hechizo1 << " contra " << objetivo.getName() << "!" << endl;
}

void Enemigo::LanzarHechizo2(Personaje& objetivo) {
    cout << nombre << " lanza " << hechizo2 << " contra " << objetivo.getName() << "!" << endl;
}