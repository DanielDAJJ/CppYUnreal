#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "./include/Jugador.h"
#include "./include/Goblin.h"
#include "./include/Orco.h"
#include "./include/Dragon.h"

using namespace std;

bool anyEnemyAlive(const vector<Personaje*>& enemigos){
    for (auto e : enemigos)
    {
        if(e && e->estaVivo()) return true;
    }
    return false;
}

void aplicarEfectosTurno(Personaje* p){
    if(!p) return;
    int turns = p->getEstadosPorTurno();
    if (turns > 0)
    {
        cout << p->getName() << " sufre efecto activo: recibe 10 puntos de dano (" << turns << " turnos restantes)." << endl;
        p->RecibirDano(10);
        p->setEstadosPorTurno(turns - 1);
    }
}

int main(){
    srand(static_cast<unsigned int>(time(0)));

    Jugador* jugador = new Jugador("Dani", "Bola de fuego", "Curar", 100, 10, 25, 5, 2, 25, 100, 3);

    vector<Personaje*> enemigos;
    enemigos.push_back(new Goblin("Goblin", "Mordisco", "Evasion", 50, 5, 12, 2, 2, 40));
    enemigos.push_back(new Orco("Orco", "Golpe", "Furia", 80, 12, 20, 6, 2, 60));
    enemigos.push_back(new Dragon("Dragon", "Llama", "Quemadura", 200, 20, 35, 10, 2, 100));

    int turno = 1;

    while (jugador->estaVivo() && anyEnemyAlive(enemigos))
    {
        cout << "\n============= Turno " << turno++ << " ==============\n";

        aplicarEfectosTurno(jugador);
        for (auto e : enemigos) aplicarEfectosTurno(e);

        if (!jugador->estaVivo()) break;
        
        cout << "\nEstado del jugador: " << jugador->getName() << " HP: " << jugador->getVida() << "/" << jugador->getVidaMax() << " Mana: " << jugador->getMana() << "/" << jugador->getManaMax() << "\n";
        cout << "Enemigos:\n";
        for(size_t i = 0 < enemigos.size(); ++i;){
            cout << (i+1) << ". " << enemigos[i]->getName() << "-" << enemigos[i]->getVida() << "/" << enemigos[i]->getVidaMax() << "\n";
            if (!enemigos[i]->estaVivo())
            {
                cout << " (muerto)";
                cout << "\n";
            }
        }
        cout << "\n¿Qué quieres hacer?\n1. Atacar\n2. Hechizo ofensivo (Hechizo1)\n3. Hechizo secundario / Curar (Hechizo2)\n4. Rendirse\n";
        int opcion = 0;
        cin >> opcion; 

        if (opcion == 1)
        {
            int idx = -1;
            cout << "Elige el objetivo (numero) ";
            cin >> idx;
            idx -= 1;
            if (idx >= 0 && idx < (int)enemigos.size() && enemigos[idx]->estaVivo())
            {
                jugador->Atacar(*enemigos[idx]);
            }
            else
            {
                cout << "Objetivo invalido o ya muerto. Pierdes el turno\n";
            }
        }
        else if (opcion == 2)
        {
            int idx = -1;
            cout << "Elige objetivo para lanzar Hechizo1: ";
            cin >> idx;
            idx -= 1;
            if (idx >= 0 && (int)enemigos.size() && enemigos[idx]->estaVivo())
            {
                jugador->LanzarHechizo1(*enemigos[idx]);
            }
            else
            {
                cout << "Objetivo inválido o ya muerto. Pierdes el turno.\n";
            }
        }
        else if (opcion == 3)
        {
            jugador->LanzarHechizo2(*jugador);
        }
        else if (opcion == 4)
        {
            cout << "Te rindes. Fin de la partida.\n";
            break;
        }
        else
        {
            cout << "Opción inválida. Pierdes el turno.\n";
        }
        for (auto e : enemigos)
        {
            if (!e || !e->estaVivo()) continue;
            int r = rand() % 100;
            if (r < 20)
            {
                e->LanzarHechizo1(*jugador);
            }
            else if (r >= 20 && r < 30)
            {
                e->LanzarHechizo2(*jugador);
            }
            else
            {
                e->Atacar(*jugador);
            }
            if (!jugador->estaVivo()) break; 
        }
        if (!jugador->estaVivo()) break;
    }
    
    if (!jugador->estaVivo()) {
        cout << "\nHas sido derrotado.\n";
    } else if (!anyEnemyAlive(enemigos)) {
        cout << "\n¡Has derrotado a todos los enemigos! ✅\n";
    } else {
        cout << "\nPartida terminada.\n";
    }

    for (auto e : enemigos) delete e;
    delete jugador;

    return 0;
}