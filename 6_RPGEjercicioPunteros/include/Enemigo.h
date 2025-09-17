#if !defined(ENEMIGO_H)
#define ENEMIGO_H
#include "Personaje.h"
#include <string>

class Enemigo : public Personaje {
    public:
        Enemigo(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m);

        void Atacar (Personaje& objetivo) override;
        void LanzarHechizo1(Personaje& objetivo) override;
        void LanzarHechizo2(Personaje& objetivo) override;
};



#endif // ENEMIGO_H
