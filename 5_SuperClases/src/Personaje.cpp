#include "../include/Personaje.h"
#include <iostream>
using namespace std;

Personaje::Personaje(const string& n, int v, int aMin, int aMax, int d) : nombre(n), vida(v), vidaMax (v), ataqueMinimo (aMin), ataqueMaximo(aMax), defensa(d) {}

void Personaje::RecibirDano(int dano){
    dano -= defensa;
    vida -= dano;
    if (vida < 0) vida = 0;
}

void Personaje::Curarse(){
    vida += 20;
    if (vida > vidaMax) vida = vidaMax; 
}

bool Personaje::estaVivo() const {
    return vida > 0;
}

string Personaje::getNombre() const {
    return nombre;
}

int Personaje::getVida() const {
    return vida;
}

int Personaje::getVidaMax() const {
    return vidaMax;
}

