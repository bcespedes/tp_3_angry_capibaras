# ifndef COLA_H
# define COLA_H


# include "Nodo.h"


template <typename Tipo>

class Cola {

private:

    int cantidad;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;

public:

    // PRE: -
    // POST: Crea una cola vacia.
    Cola();

    // PRE: -
    // POST: Devuelve true si la cola esta vacia, false en caso contrario.
    bool vacia();

    // PRE: elemento es un dato valido.
    // POST: Agrega el dato e al final de la cola.
    void alta(Tipo elemento);

    // PRE: La cola no puede estar vacia.
    // POST: Elimina el primer elemento de la cola.
    Tipo baja();

    // PRE: La cola no puede estar vacia.
    // POST: Devuelve el primer elemento de la cola (sin modificarla).
    Tipo consulta();

    // PRE: -
    // POST: Devuelve la cantidad de elementos de la cola.
    int obtener_cantidad();

    // PRE: -
    // POST: Destruye la cola.
    ~Cola();

};

template <typename Tipo>

Cola<Tipo>::Cola() {

    cantidad = 0;
    primero = NULL;
    ultimo = NULL;
}

template <typename Tipo>
int Cola<Tipo>::obtener_cantidad(){
    return cantidad;
}


template <typename Tipo>

bool Cola<Tipo>::vacia() {

    return ultimo == NULL;
}


template <typename Tipo>

Tipo Cola<Tipo>::consulta() {

    return primero -> obtener_dato();
}


template <typename Tipo>

void Cola<Tipo>::alta(Tipo d) {

    Nodo<Tipo>* nuevo = new Nodo<Tipo>(d);

    if(primero)
        ultimo -> cambiar_siguiente(nuevo);
    else
        primero = nuevo;
    
    ultimo = nuevo;
    cantidad++;
}


template <typename Tipo>

Tipo Cola<Tipo>::baja() {

    Nodo<Tipo>* borrar = primero;

    Tipo dato = borrar -> obtener_dato();

    primero = primero -> obtener_siguiente();

    if(!primero)
        ultimo = NULL;

    borrar->asignar_dato_a_null();
    delete borrar;
    cantidad--;
 
    return dato;
}


template <typename Tipo>

Cola<Tipo>::~Cola() {

    while(!vacia())
        baja();
}


# endif