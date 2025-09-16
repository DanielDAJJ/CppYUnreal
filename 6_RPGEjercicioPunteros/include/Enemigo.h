#if !defined(ENEMIGO_H)
#define ENEMIGO_H
#include "Personaje.h"
#include <string>

class Enemigo : public Personaje {
    public:
        Enemigo(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m);

        void Atacar (Personaje& objetivo) override;
        void LanzarHechizo1(string hechizo1) override;
        void LanzarHechizo2(string hechizo2) override;
};



#endif // ENEMIGO_H
