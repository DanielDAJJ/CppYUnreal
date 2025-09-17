#include "../include/Personaje.h"
#include <iostream>
using namespace std;

Personaje::Personaje(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m) : nombre(n), hechizo1(h1), hechizo2(h2), vida(v), vidaMax(v), ataqueMin(aMin), ataqueMax(aMax), defensa(d), numeroHechizos(nHechizos), mana(m), manaMax(m) {};

void Personaje::RecibirDano(int dano){
    if (inmuneProximoTurno)
    {
        cout << nombre << " esquiva el ataque y no recibe dano este turno!" << endl;
        inmuneProximoTurno = false;
        return;
    }
    
    int danoReal = dano - defensa;
    if (danoReal < 0) danoReal = 0;
    vida -= danoReal;
    if (vida < 0) vida = 0;
};

bool Personaje::estaVivo() const {
    return vida > 0;
};

string Personaje::getName() const{
    return nombre;
};

int Personaje::getVida() const {
    return vida;
};

int Personaje::getVidaMax() const {
    return vidaMax;
};

int Personaje::getMana() const {
    return mana;
};

int Personaje::getManaMax() const {
    return manaMax;
};