/* 
*POO en C++

Programación Orientada a Objetos, donde utilizaremos clases, para poder crear objetos que podran tener sus po=ropios parametros y caracterizticas junto con sus metodos. 

esto con el fin de escalar y poder hacer más manejable el codigo.

?Crear una clase Personajes
donde vamos a definir lo siguiente:
    ?Vida
    ?Ataque
    ?defensa
    ?Curaciones

para crear una clase utilizamos la palabra reservada 
    ?class
y tambien tendremos lo modificadores de acceso como lo son:
    ?private
    ?public
    ?protected
los cuales determinan la visibilidad de los miembros de una clase desde fuera.
?Public:
El modificador permite que los miembropos de una clase sean accesibles desde cualquier parte del código.
?Private
Esto restringe el acceso a los miembros de la clase a la propia clase.
?Protected
Permiten que las clase  derivadas de la  misma clase puedan utilizar los metodos y caracteristicas de la clase padre.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Personaje {
    private:
        string nombre;
        int vida;
        int ataqueMin = 10;
        int ataque;
        int defensa;
        int curaciones;
    
    public:
        // Constructor
        // *n:nombre, v:vida, a:ataque, d:defensa, c:curaciones
        Personaje(string n, int v, int a, int d, int c)
            : nombre(n), vida(v), ataque(a), defensa(d), curaciones(c) {}

        /*
        *Getters
        son metodos que permiten controlar como se accede y modifca el estado interno de un objeto.
        ?getter permite acceder al valor de una propiedad privada o protegida de una clase
        ?setter permite modificar el valor de una propiedad
        */

        string getNombre() {return nombre;}
        int getVida() {return vida;}
        int getCuraciones (){return curaciones;}
        int getAtaque() {return ataque;}

        //método para atacar
        void Atacar(Personaje &objetivo){
            int dano = (ataqueMin + (rand() % (ataque - ataqueMin + 1))) - defensa;
            if (dano < 0) dano = 0;
            objetivo.vida -= dano;
            if(objetivo.vida < 0) objetivo.vida = 0;

            cout << nombre << " ataca a " << objetivo.nombre << " causando " << dano << " de daño. Vida de " << objetivo.nombre << ": " << objetivo.vida << endl;
        };
        // Método para curarse
        void Curar (){
            if (curaciones > 0)
            {
                vida += 20;
                curaciones --;
                cout << nombre << " se cura. Vida actual: " << vida << " | Curaciones restantes: " << curaciones << endl;
            } else {
                cout << nombre << " no tiene curaciones dispponibles." << endl;
            };
        };
        //Verificar si está vivo
        bool estaVivo() {
            return vida > 0;
        };
};

int main(){
    srand(time(0));
    //Caracteristicas partida
    int turno = 1;
    int opcion;

    //*Creamos personajes
    Personaje jugador("Jugador", 100, 30, 10, 2);
    Personaje enemigo("Enemigo", 100, 30, 10, 2);

    cout << "🔥 ¡Comienza la batalla! 🔥" << endl;
    
    while (jugador.getVida() > 0 && enemigo.getVida() > 0)
    {
        cout << "======= Turno " << turno ++ << " =======" <<endl;
        cout << jugador.getNombre() << ": puntos de vida " << jugador.getVida() << " | " << enemigo.getNombre() << ": Puntos de vida " << enemigo.getVida() << endl;
        cout << "¿Qué quieres Hacer?" << endl;
        cout << "1. Atacar" << endl;
        cout << "2. Curarse (" << jugador.getCuraciones() << ")"<< endl;
        cout << "3. Rendirse" << endl;
        cout << "Elige una opción: " << endl;
        cin >> opcion;

        if (opcion == 1)
        {
            jugador.Atacar(enemigo);
        }
        else if (opcion == 2)
        {
            jugador.Curar();
        }
        else if (opcion == 3)
        {
            cout << "Te rendiste.  El enemigo gana." << endl;
            break;
        }
        else
        {
            cout << "Opción inválida" << endl;
            continue;
        }
        enemigo.Atacar(jugador);

        //Verificar si alguien perdió
        if(!enemigo.estaVivo()) {
            cout << enemigo.getNombre() <<" ha sido derrotado." << endl;
            break;
        };
        if(!jugador.estaVivo()) {
            cout << jugador.getNombre() <<" ha sido derrotado." << endl;
            break;
        };
    };

    cout << "\n === Fin del combate ===" << endl;
    return 0;
};