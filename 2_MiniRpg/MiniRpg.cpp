#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---Funciones itulitarias---

int AplicarDano(int vida, int dano, int defensa){
    dano -= defensa;
    vida -= dano;
    if(vida < 0) vida = 0;
    return vida;
}
int AplicarCura(int vida, int cura, int vidaMax){
    vida += cura;
    if (vida > vidaMax) vida = vidaMax;
    return vida;
}
int NumeroRadom (int min, int max){
    return min + (rand() % (max - min + 1));
}

// ---Programa Principal---

int main (){
    srand(time(0));

    //Caracteristicas Jugador
    int vidaJugador = 100;
    int vidaMaxJugador = 100;
    int hechizoCura = 25;
    int curasRestante = 3;
    int ataqueMaxJugador = 25;
    int ataqueMinJugador = 15;
    int defensaMaxJugador = 15;
    int defensaMinJugador = 10;
    int defensaJugador;
    int danoJugador;
    
    // Caracteristicas Enemigo
    int vidaEnemigo = 80;
    int vidaMaxEnemigo = 80;
    int ataqueMaxEnemigo = 25;
    int ataqueMinEnemigo = 10;
    int defensaMaxEnemigo = 10;
    int defensaMinEnemigo = 5;
    int defensaEnemigo;
    int danoEnemigo;

    // Caracteristicas Juego
    int turno = 1;
    int opcion = 0;

    cout <<"=== Combate por turnos ===" << endl;
    cout <<"Jugador: " << vidaJugador <<"/" <<vidaMaxJugador << "HP" << endl;
    cout <<"Enemigo: " << vidaEnemigo <<"/" <<vidaMaxEnemigo << "HP" << endl;
    cout <<"=====================" << endl;

    while (vidaJugador > 0 && vidaEnemigo > 0)
    {
        cout <<"\n--- Turno " << turno++ <<" ---" << endl;
        cout <<"Tu vida " << vidaJugador <<"/" << vidaMaxJugador << " | Vida del enemigo: " << vidaEnemigo << "/" << vidaMaxEnemigo << endl; 

        // ---Acción del jugador ---

        cout << "\n ¿Qué quieres hacer?" << endl;
        cout << "1. Atacar" << endl;
        cout << "2. Curarse (" << curasRestante << " restantes)" << endl;
        cout << "3. Rendirse" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        danoEnemigo = NumeroRadom(ataqueMinEnemigo, ataqueMaxEnemigo);
        danoJugador = NumeroRadom(ataqueMinJugador, ataqueMaxJugador);
        defensaJugador = NumeroRadom(defensaMinJugador, defensaMaxJugador);
        defensaEnemigo = NumeroRadom(defensaMinEnemigo, defensaMaxEnemigo);
        
        if (opcion == 1)
        {
            vidaEnemigo = AplicarDano(vidaEnemigo, danoJugador, defensaEnemigo);
            cout << "Atacas al enemigo e infliges " << danoJugador << " de daño." << " El enemigo se defiende con: " <<defensaEnemigo << "puntos de defensa. La vida del enemigo es " << vidaEnemigo << " HP." <<endl;
        }
        else if (opcion == 2)
        {
            if(curasRestante > 0){
                vidaJugador = AplicarCura(vidaJugador, hechizoCura, vidaMaxJugador);
                cout << "Lanzas un hechizo de curación y recuperas " << hechizoCura << " HP." << endl;
                curasRestante --;
            } else {
                cout << "¡No te quedan curaciones!" << endl;
            }
        }
        else if (opcion == 3)
        {
            cout << "Te rendiste.  El enemigo gana." << endl;
            break;
        }
        else {
            cout << "Opción inválida" << endl;
            continue;
        }

        // Verificar si el enemigo murió
        if (vidaEnemigo <= 0)
        {
            cout << "\n ¡Has derrotado al enemigo!" << endl;
            break;
        }
        
        //--- Acción del enemigo ---
        vidaJugador = AplicarDano(vidaJugador, danoEnemigo, defensaJugador);
        cout << "El enemigo te ataca e inflige " << danoEnemigo << " de daño. Te defiendes con: " <<defensaJugador <<" puntos de defensa. Tienes " <<vidaJugador << " HP." << endl;

        if (vidaJugador == 0)
        {
            cout << "\n ¡Has muerto en combate!" << endl;
            break;
        }
    }
    
    cout << "\n === Fin del combate ===" << endl;

    return 0;
}