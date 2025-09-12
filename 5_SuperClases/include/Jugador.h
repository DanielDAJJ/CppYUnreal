#ifndef JUGADOR_H
#define JUGADOR_H
#include "Personaje.h"

class Jugador : public Personaje {
    private:
        int curaciones;

    public:
        Jugador(const string& n, int v, int aMin, int aMax, int d, int c);
        void Atacar(Personaje& objetivo) override;
        void Curarse() override;
};


#endif