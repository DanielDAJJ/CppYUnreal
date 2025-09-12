#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Jugador.h"
#include "../include/Enemigo.h"

using namespace std;

int main(){
    srand(static_cast<unsigned int>(time(0)));

    Jugador player("Pauis", 100, 10, 25, 10, 3);
    Enemigo goblin("Goblin", 80, 10, 20, 5);

    Personaje* pJugador = &player;
    Personaje* pEnemigo = &goblin;

    int turno = 1;
    int opcion;

    while (pJugador->estaVivo() && pEnemigo->estaVivo())
    {
        cout << "\n========= Turno " << turno << " ========\n";
        cout << "Jugador: vida " << player.getVida() << " | Enemigo: Vida " << goblin.getVida() << endl;
        cout << " " << endl;

        cout << "Que quieres hacer?\n" << endl;
        cout << "1. Atacar\n" << endl;
        cout << "2. Curarse\n" << endl;
        cout << "3. Rendirse\n" << endl;

        cin >> opcion;

        if (opcion == 1)
        {
            player.Atacar(goblin);
        }
        else if (opcion == 2)
        {
            player.Curarse();
        }
        else if (opcion == 3)
        {
            cout << "Te has rendido...\n" << endl;
            break;
        }
        
        if (goblin.estaVivo())
        {
            goblin.Atacar(player);
        }
        
        turno ++;
    }
    if (!player.estaVivo())
    {
        cout << "\nEl jugador " << player.getNombre() << " ha sido derrotado.\n" << endl;
    } 
    else if (!goblin.estaVivo())
    {
        cout << "\nEl enemigo " << goblin.getNombre() << " ha sido derrotado.\n" << endl;
    }
    
    cout << "\n====== fin del combate ============\n" << endl;

    return 0;
}