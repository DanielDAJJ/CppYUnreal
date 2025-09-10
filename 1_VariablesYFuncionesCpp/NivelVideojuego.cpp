#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int AplicarDano(int vida, int dano){
    vida -= dano;
    if(vida < 0) vida = 0;
    return vida;
}
int AplicarCura(int vida, int cura, int vidaMax){
    vida += cura;
    if(vida > vidaMax) vida = vidaMax;
    return vida;
}
int numeroRamdon(){
    int minimo = 1;
    int maximo = 25;

    int result = minimo + (rand() % (maximo - minimo + 1)) ;
    
    return result;
}
/*
int main(){
    int vidaJugador = 100;
    int vidaMaxJugador = 100;
    
    cout << "Vida inicial: " << vidaJugador <<endl;

    vidaJugador = AplicarDano(vidaJugador, 30);
    cout << "Después de recibir 30 de daño: " << vidaJugador << endl;

    vidaJugador = AplicarDano(vidaJugador, 80);
    cout << "Después de recibir 80 de daño: " <<vidaJugador <<endl;

    vidaJugador = AplicarCura(vidaJugador, 100, vidaMaxJugador);
    cout << "Después de recibir 100 de cura: " <<vidaJugador <<endl;

    return 0;
} */

/* 
Loop de juego en consola
*/


int main(){
    srand(time(0));

    int vidaJugador = 100;
    int vidaMaxJugador = 100;
    int hechizoCura = 25;
    
    int ataqueEnemigo = 0;
    
    int opcion = 0;

    cout << "=== Simulador de combate ===" << endl;
    cout << "vida inicial del jugador: " << vidaJugador << endl;

    // loop de combate

    while (vidaJugador > 0)
    {
        cout << "¿Que quieres hacer?" << endl;
        cout << "1. esperar" << endl;
        cout << "2. Curarse" << endl;
        cout << "3. Salir del juego" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == 1)
        {
            ataqueEnemigo = numeroRamdon();
            cout << "El enemigo hace: " <<ataqueEnemigo <<" de daño" << endl;
            vidaJugador =  AplicarDano(vidaJugador, ataqueEnemigo);
            cout << "tienes " << vidaJugador << " puntos de vida";
        }
        else if (opcion == 2)
        {
            cout << "Has usado tu hechizo de curación" << endl;
            vidaJugador = AplicarCura(vidaJugador, hechizoCura, vidaMaxJugador);
            cout << "Te has curado: " << hechizoCura << ", tus puntos de vida actuales son: " << vidaJugador << endl;
        }
        else if (opcion == 3)
        {
            cout << "Has salido del juego." << endl;
            break;
        }
        else{
            cout << "Opcion inválida." << endl;
        }
        
        if (vidaJugador == 0)
        {
            cout << "¡Has muerto en combate!" << endl;
            break;
        }
        
    }

    return 0;
}