#if !defined(JUGADOR_H)
#define JUGADOR_H
#include "Personaje.h"
#include <string>

class Jugador : public Personaje
{
private:
    int healthAmount;
    int curacionesRestantes;

public:
    Jugador(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int hAmount, int m, int cRest);
    
    void Atacar (Personaje& objetivo) override;
    void LanzarHechizo1(Personaje& objetivo) override;
    void LanzarHechizo2(Personaje& objetivo) override;
    void Curarse(int& healtAmount);
};



#endif // JUGADOR_H