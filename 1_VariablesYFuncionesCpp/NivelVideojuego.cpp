#include <iostream>
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
}