#ifndef ARISTA_H
#define ARISTA_H

#include <iostream>
#include "Lectura.h"

class Arista{

private:
    Lectura* origen_;
    Lectura* destino_;
    int peso_;

public:
    Arista(Lectura* origen, Lectura* destino, int peso);


    Lectura *devolver_origen();
    Lectura *devolver_destino();
    int obtener_peso();

    string obtener_padres();
    //bool operator<(Arista &arista); 

    ~Arista();

};



#endif