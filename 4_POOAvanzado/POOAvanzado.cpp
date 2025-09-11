#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Personaje {
    protected:
        string nombre;
        int vida;
        int vidaMax;
        int ataqueMax;
        int ataqueMin;
        int defensa;

    public:
        Personaje(const string& n, int v, int aMin, int aMax, int d)
            : nombre(n), vida(v), vidaMax(v), ataqueMin(aMin), ataqueMax(aMax), defensa(d) {};
        virtual ~Personaje() = default;

        string getNombre() const {return nombre;}
        int getVida() const {return vida;}
        int getVidaMax() const {return vidaMax;}
        bool estaVivo() const {return vida > 0;}

        void RecibirDano(int dmg){
            vida -= dmg;
            if(vida < 0) vida = 0;
        };
        void CurarCantidad(int amount){
            vida += amount;
            if(vida > vidaMax) vida = vidaMax;
        };

        virtual void Atacar(Personaje &objetivo){
            int roll = ataqueMin + (rand() % (ataqueMax - ataqueMin + 1));
            int dano = roll - objetivo.defensa;
            if (dano < 0) dano = 0;
            objetivo.RecibirDano(dano);

            cout << nombre << " ataca a " << objetivo.nombre << " causando " << dano << " de dano. Vida de " << objetivo.nombre << ": " << objetivo.vida << endl;

        };
        virtual void Accion(Personaje &objetivo) = 0;
};

class Jugador : public Personaje {
    private:
        int curaciones;
    
        public:
            Jugador(const string& n, int v, int aMin, int aMax, int d, int c)
                : Personaje(n, v, aMin, aMax, d), curaciones(c) {}
        void Curar(){
            if (curaciones > 0)
            {
                int healAmount = 20;
                CurarCantidad(healAmount);
                curaciones --;
                cout << nombre << " se cura. Vida Actual: " << vida << " | Curaciones restantes: " << curaciones << endl;
            }
            else
            {
                cout << nombre << " no tiene curaciones disponibles." << endl;
            }
        };
        void Accion (Personaje &objetivo) override{
            int opcion;
            cout << "\nQue quieres hacer?" << endl;
            cout << "1. Atacar" << endl;
            cout << "2. Curarse (" <<curaciones <<" disponibles)" << endl;
            cout << "3. Rendirse" << endl;
            cout << "Elige una opción: " << endl;
            cin >> opcion;

            if (opcion == 1)
            {
                Atacar(objetivo);
            }
            else if (opcion == 2)
            {
                Curar();
            }
            else if (opcion == 3)
            {
                cout << nombre << " se rinde. Pierder la batalla" << endl;
                vida = 0;
            }
            else
            {
                cout << "Opcion Invalida, pierdes el turno." << endl; 
            }
        }
};

class Enemigo : public Personaje {
    private:
        int curaciones;
    
    public:
        Enemigo(const string& n, int v, int aMin, int aMax, int d, int c = 1)
            : Personaje(n, v, aMin, aMax, d), curaciones(c) {}
    
        void Accion(Personaje &objetivo) override {
            int prob = rand() % 10;
            if ((vida < (vidaMax / 3)) && (curaciones > 0) && (prob < 40))
            {
                int healAmount = 15;
                CurarCantidad(healAmount);
                curaciones--;
                cout << nombre << " utiliza curacion. Vida actual: " << vida << " | Curaciones restantes: " << curaciones << endl;
            }
            else{
                Atacar(objetivo);
            }
        }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Jugador player("Player", 100, 5, 25, 10, 2);
    Enemigo goblin("Goblin", 100, 5, 20, 8, 1);

    Personaje* pJugador = &player;
    Personaje* pEnemigo = &goblin;

    cout << "Comienza el combate" << endl;

    int turno = 1;
    while (pJugador->estaVivo() && pEnemigo->estaVivo())
    {
        cout << "\n======== Turno " << turno++ << " ===========" << endl;
        cout << pJugador->getNombre() << ": " << pJugador->getVida() << "/" << pJugador->getVidaMax() << " | " << pEnemigo->getNombre() << ": " << pEnemigo->getVida() << "/" << pEnemigo->getVidaMax() << endl;

        pJugador->Accion(*pEnemigo);
        if (!pEnemigo->estaVivo())
        {
            cout << pEnemigo->getNombre() << " ha sido derrotado." << endl;
            break;
        }
        
        pEnemigo->Accion(*pJugador);
        if (!pJugador->estaVivo())
        {
            cout << pJugador->getNombre() << " ha sido derrotado." << endl;
            break;
        }
    }

    cout << "\n======= Fin del combate =========" << endl;
    return 0;
}