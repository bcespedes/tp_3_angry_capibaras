#ifndef ARISTA_H
#define ARISTA_H

#include <iostream>
#include "Lectura.h"

class Arista{

private:
    Lectura* origen_;
    Lectura* destino_;
    //int peso_;

public:
    Arista(Lectura* origen, Lectura* destino, int peso);

    int peso_;
    //int devolver_peso();

    //bool operator<(Arista &arista); 


};



#endif