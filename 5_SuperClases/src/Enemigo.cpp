#include "../include/Enemigo.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Enemigo::Enemigo(const string& n, int v, int aMin, int aMax, int d) : Personaje(n, v, aMin, aMax, d) {}

void Enemigo::Atacar(Personaje& objetivo) {
    int dano = ataqueMinimo + (rand() % (ataqueMaximo - ataqueMinimo +1));
    cout << nombre << " ataca a " << objetivo.getNombre() << " causando " << dano << " de dano " << endl;
    objetivo.RecibirDano(dano);
}