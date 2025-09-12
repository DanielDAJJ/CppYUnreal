#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
using std::string;

class Personaje
{
protected:
    string nombre;
    int vida;
    int vidaMax;
    int defensa;
    int ataqueMaximo;
    int ataqueMinimo;

public:
    Personaje(const string& n, int v, int aMin, int aMax, int d);

    virtual ~Personaje() = default;

    string getNombre() const;  
    int getVida() const;
    int getVidaMax() const;
    bool estaVivo() const;
    
    virtual void Atacar(Personaje& objetivo) = 0;
    void RecibirDano(int dano);
};

#endif