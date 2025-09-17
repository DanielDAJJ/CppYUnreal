#if !defined(PERSONAJE_H)
#define PERSONAJE_H

#include <string>
using std::string; 

class Personaje
{
protected:
    string nombre;
    string hechizo1;
    string hechizo2;
    int vida;
    int vidaMax;
    int ataqueMin;
    int ataqueMax;
    int defensa;
    int numeroHechizos;
    int mana;
    int manaMax;
    bool inmuneProximoTurno = false;
    int estadosPorTurno = 0;

public:
    Personaje(const string& n, const string& h1, const string& h2, int v, int aMin, int aMax, int d, int nHechizos, int m);
    
    virtual ~Personaje() = default;

    string getName () const; 
    int getVida () const; 
    int getVidaMax () const; 
    int getMana () const; 
    int getManaMax () const; 
    bool estaVivo () const;
    int getEstadosPorTurno() const { return estadosPorTurno; }
    void setEstadosPorTurno(int valor) { estadosPorTurno = valor; }
    
    virtual void Atacar (Personaje& objetivo) = 0;
    void RecibirDano (int dano);
    virtual void LanzarHechizo1 (Personaje& objetivo) = 0;
    virtual void LanzarHechizo2 (Personaje& objetivo) = 0;
};

#endif // PERSONAJE_H