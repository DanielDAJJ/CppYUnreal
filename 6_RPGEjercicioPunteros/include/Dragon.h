#if !defined(DRAGON_H)
#define DRAGON_H

#include "Enemigo.h"

class Dragon : public Enemigo {
public:
    Dragon(const std::string& n, const std::string& h1, const std::string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m);

    void LanzarHechizo1(Personaje& objetivo) override;
    void LanzarHechizo2(Personaje& objetivo) override;
};

#endif // DRAGON_H