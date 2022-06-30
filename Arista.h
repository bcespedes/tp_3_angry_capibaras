# ifndef ARISTA_H
# define ARISTA_H


# include <iostream>
# include "Lectura.h"


class Arista {

private:

    Lectura* origen_;
    Lectura* destino_;
    int peso_;

public:

    // PRE: Los datos son validos.
    // POST: Crea una arista.
    Arista(Lectura* origen, Lectura* destino, int peso);

    // PRE: -
    // POST: Devuelve el origen de la arista.
    Lectura* devolver_origen();

    // PRE: -
    // POST: Devuelve el destino de la arista.
    Lectura* devolver_destino();

    // PRE: -
    // POST: Devuelve el peso de la arista.
    int obtener_peso();

    // PRE: -
    // POST: Devuelve un string con ambos padres.
    string obtener_padres();

    ~Arista();

};


# endif