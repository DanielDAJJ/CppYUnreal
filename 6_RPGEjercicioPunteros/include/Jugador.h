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
    void LanzarHechizo1(string hechizo1) override;
    void LanzarHechizo2(string hechizo2) override;
    virtual void Curarse(int& healtAmount) = 0;
};



#endif // JUGADOR_H