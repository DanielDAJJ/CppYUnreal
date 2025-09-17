#include "../include/Jugador.h"
#include <iostream>
#include <iostream>
#include <cstdlib>
using namespace std;

Jugador::Jugador(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int hAmount, int m, int cRest) : Personaje(n, h1, h2, v, aMin, aMax, d, nHechizos, m), healthAmount(hAmount), curacionesRestantes(cRest) {};

void Jugador::Atacar(Personaje& objetivo) {
    int dano = ataqueMin + (rand() % (ataqueMax - ataqueMin + 1));
    objetivo.RecibirDano(dano);
    cout << nombre << " ataca a "<< objetivo.getName() << " causando " << dano << " puntos de dano. " << objetivo.getName() << " tiene " << objetivo.getVida() << " puntos de vida restantes." << endl;
};

void Jugador::Curarse(int& healtAmount){
    if (curacionesRestantes > 0) vida += healtAmount;
    if (vida > vidaMax) vida = vidaMax;
    curacionesRestantes --;
};

void Jugador::LanzarHechizo1(Personaje& objetivo){
    int dano =  (ataqueMin * 2) + (rand() % (ataqueMax - ataqueMin + 1));
    if (mana > 0)
    {
        objetivo.RecibirDano(dano);
        mana -= 25;
        cout << nombre << " lanza " << hechizo1 << " ocasionando " << dano << " puntos de dano a " << objetivo.getName() << endl; 
    }
    else
    {
        cout << "No tienes mana suficiente para lanzar " << hechizo1 << endl;
    }
    if(mana < 0) mana = 0;
};

void Jugador::LanzarHechizo2(Personaje& objetivo) {
    int curacion = 25;
    if (mana > 0)
    {
        Jugador::Curarse(curacion);
        mana -= 20;
        cout << "Te has curado " << curacion << " puntos de salud." << endl;
    }
    else
    {
        cout << "No tienes mana suficiente para lanzar " << hechizo2 << endl;
    }
    if(mana < 0) mana = 0;
};