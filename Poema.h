# ifndef POEMA_H
# define POEMA_H


# include "Lectura.h"


class Poema: public Lectura {

private:

    int versos_;

public:

    // PRE: Los datos son validos.
    // POST: Crea un poema.
    Poema(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, bool leido, int versos);

    // PRE: -
    // POST: Devuelve la cantidad de versos del poema. 
    int obtener_versos();

    // PRE: -
    // POST: Muestra por pantalla las caracteristicas del poema.
    void mostrar_lectura();

    char tipo_lectura();

    // PRE: - 
    // POST: Devuelve false, pues un Poema no tiene genero.
    bool coinciden_generos(int genero);
    
};


# endif