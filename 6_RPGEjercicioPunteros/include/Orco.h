#if !defined(ORCO_H)
#define ORCO_H

#include "Enemigo.h"

class Orco : public Enemigo {
public:
    Orco(const std::string& n, const std::string& h1, const std::string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m);

    void LanzarHechizo1(Personaje& objetivo) override;
    void LanzarHechizo2(Personaje& objetivo) override;
};

#endif // ORCO_H
