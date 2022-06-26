# ifndef NODO_H
# define NODO_H


# include <iostream>
# include "Escritor.h"


template <typename Tipo>

class Nodo {

private:

    Tipo dato;
    Nodo* siguiente;

public:

    // PRE: d es un dato valido.
    // POST: Construye un nodo con d como dato y siguiente apuntado a null.
    Nodo(Tipo d);

    // PRE: Nodo es un nodo valido.
    // POST: Siguiente apunta a n.
    void cambiar_siguiente(Nodo* nodo);

    // PRE: -
    // POST: Devuelve el dato.
    Tipo obtener_dato();

    // PRE: -
    // POST: Devuelve el nodo siguiente, si no lo hubiera devuelve null.
    Nodo* obtener_siguiente();

    void asignar_dato(Tipo d);

    // PRE: -
    // POST: Se llama al destructor del dato y luego se destruye el nodo.
    ~Nodo();

};


template <typename Tipo>

Nodo<Tipo>::Nodo(Tipo d) {

    dato = d;
    siguiente = NULL;
}


template <typename Tipo>

void Nodo<Tipo>::cambiar_siguiente(Nodo* n) {

    siguiente = n;
}


template <typename Tipo>

Tipo Nodo<Tipo>::obtener_dato() {

    return dato;
}

template <typename Tipo>
void Nodo<Tipo>::asignar_dato(Tipo d){
    dato = d;
}

template <typename Tipo>

Nodo<Tipo>* Nodo<Tipo>::obtener_siguiente() {

    return siguiente;
}


template <typename Tipo>

Nodo<Tipo>::~Nodo() {

    delete dato;
}


# endif