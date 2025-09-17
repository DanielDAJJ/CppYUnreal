#if !defined(GOBLIN_H)
#define GOBLIN_H

#include "Enemigo.h"

class Goblin : public Enemigo {
public:
    Goblin(const std::string& n, const std::string& h1, const std::string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m);

    void LanzarHechizo1(Personaje& objetivo) override;
    void LanzarHechizo2(Personaje& objetivo) override;
};

#endif // GOBLIN_H
