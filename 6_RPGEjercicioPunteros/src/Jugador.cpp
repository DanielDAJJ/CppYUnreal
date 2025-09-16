#include "../include/Jugador.h"
#include <iostream>
#include <iostream>
#include <cstdlib>
using namespace std;

Jugador::Jugador(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int hAmount, int m, int cRest) : Personaje(n, h1, h2, v, aMin, aMax, d, nHechizos, m), healthAmount(hAmount), curacionesRestantes(cRest) {};

void Jugador::Atacar(Personaje& objetivo) {
    int dano = ataqueMin + (rand() % (ataqueMax - ataqueMin + 1));
    cout << nombre << " ataca a "<< objetivo.getName() << " causando " << dano << " puntos de dano. " << objetivo.getName() << " tiene " << objetivo.getVida() << " puntos de vida restantes." << endl;
    objetivo.RecibirDano(dano);
};
