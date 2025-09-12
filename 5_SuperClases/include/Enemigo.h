#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"

class Enemigo : public Personaje {
    public:
        Enemigo(const string& n, int v, int aMin, int aMax, int d);
        void Atacar(Personaje& objetivo) override;
};

#endif