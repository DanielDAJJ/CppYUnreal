#include "../include/Jugador.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Jugador::Jugador(const string& n, int v, int aMin, int aMax, int d, int c) : Personaje (n, v, aMin, aMax, d), curaciones(c) {}

void Jugador::Atacar(Personaje& objetivo){
    int dano = ataqueMinimo + (rand() % ataqueMaximo - ataqueMinimo + 1);
    cout << nombre << " ataca a " << objetivo.getNombre() << " causando " << dano << " de dano." << endl;
    objetivo.RecibirDano(dano);
}

void Jugador::Curarse(){
    if (curaciones > 0)
    {
        vida += 20;
        curaciones --;
        cout << nombre << " se cura. Vida actual: " << vida << " | Curaciones restantes: " << curaciones << endl;
    }
    else
    {
        cout << nombre << " no tiene curaciones disponibles." << endl;
    }
}