#include "Arista.h"

Arista::Arista(Lectura* origen, Lectura* destino, int peso){
    origen_ = origen;
    destino_ = destino;
    peso_ = peso;
}


int Arista::obtener_peso(){
    return peso_;
}

string Arista::obtener_padres(){
    string titulo = origen_->obtener_titulo() + " " +  destino_->obtener_titulo();
    return titulo;
}

Lectura *Arista::devolver_origen(){
    return origen_;
}
Lectura *Arista::devolver_destino(){
    return destino_;
}

Arista::~Arista(){
}


