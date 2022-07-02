# ifndef LISTA_H
# define LISTA_H


# include "Nodo.h"
# include "constantes.h"


template <typename Tipo>

class Lista {

private:

    int cantidad;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* actual;
    bool eliminar_dato;

public:

    // PRE: -
    // POST: Crea una lista vacia.
    Lista();

    void no_eliminar();
    // PRE: -
    // POST: eliminar_dato se pone en false. 
    // Al hacer la baja, simplemente se desconectara el nodo y no se eliminara el dato interno.
    void no_eliminar_dato();

    // PRE: -
    // POST: Mueve el actual al inicio de la lista.
    void inicializar();

    // PRE:
    // POST:
    void desinicializar();

    // PRE:
    // POST: Devuelve true si hay un nodo siguiente, false si se esta en el final.
    bool hay_siguiente();

    // PRE:
    // POST: Devuelve el dato de actual y mueve el actual hacia la siguiente posicion.
    Tipo siguiente();

    // PRE: -
    // POST: Devuelve true si esta vacia, false en caso contrario.
    bool vacia();

    // PRE: e es un dato valido. 0 <= Pos <= obtener.cantidad() + 1
    // POST: Agrega el elem en la posicion pos. (empieza en 0)
    void alta(Tipo e, int pos); 
    
    // PRE: 0 <= Pos <= obtener.cantidad().
    // POST: Da de baja al elemento en pos.
    void baja(int pos);

    // PRE: 0 <= Pos <= obtener.cantidad().
    // POST: Devuelve el elemento en pos.
    Tipo consulta(int pos);

    // PRE: La lista es de punteros a escritores.
    // POST: Imprime los elementos de la lista.
    void imprimir_lista_escritores();

    // PRE: La lista es de punteros a lecturas.
    // POST: Imprime los elementos de la lista. 
    void imprimir_lista_lecturas();

    // PRE: -
    // POST: Devuelve el tamaño de la lista.
    int obtener_cantidad();

    int obtener_posicion(Tipo d);
    //PRE: -
    //POST: Destruye la lista.
    ~Lista();

private:

    Nodo<Tipo>* obtener_nodo(int pos);

};


template <typename Tipo>

Lista<Tipo>::Lista() {
    cantidad = 0;
    primero = NULL;
    actual = NULL;
    eliminar_dato = true;
}


template <typename Tipo>

void Lista<Tipo>::no_eliminar_dato() {

    eliminar_dato = false;
}


template <typename Tipo>

void Lista<Tipo>::inicializar() {

    actual = primero;
}


template <typename Tipo>

void Lista<Tipo>::desinicializar() {

    actual = NULL;
}


template <typename Tipo>

bool Lista<Tipo>::hay_siguiente() {

    return actual != NULL;
}


template <typename Tipo>

Tipo Lista<Tipo>::siguiente() {

    Tipo devolver = actual -> obtener_dato();
    actual = actual -> obtener_siguiente();

    return devolver;
}


template <typename Tipo>

bool Lista<Tipo>::vacia() {

    return (primero == NULL);
}


template <typename Tipo>

int Lista<Tipo>::obtener_cantidad() {

    return cantidad;
}


template <typename Tipo>

Nodo<Tipo>* Lista<Tipo>::obtener_nodo(int pos) {

    Nodo<Tipo>* aux = primero;
    int contador = 0;

    while(contador < pos) {
        aux = aux -> obtener_siguiente();
        contador++;
    }

    return aux;
}


template <typename Tipo>

Tipo Lista<Tipo>::consulta(int pos) {

    Nodo<Tipo>* aux = obtener_nodo(pos);
    return aux -> obtener_dato();
}


template <typename Tipo>

int Lista<Tipo>::obtener_posicion(Tipo d) {

    if(cantidad == 0)
        return NO_ENCONTRADO;

    int pos = NO_ENCONTRADO;
    inicializar();
    bool esta = false;
    while(hay_siguiente() && !esta){
        if(siguiente() == d){
            esta = true;
        }
        pos++;
    }
    if(!esta)
        pos = NO_ENCONTRADO;

    return pos;
}


template <typename Tipo>

void Lista<Tipo>::alta(Tipo e, int pos) {

    Nodo<Tipo>* nuevo = new Nodo<Tipo>(e);

    if( pos == 0) {
        nuevo -> cambiar_siguiente(primero);
        primero = nuevo;

    }
    else {

        Nodo<Tipo>* anterior = obtener_nodo(pos - 1);
        nuevo -> cambiar_siguiente(anterior -> obtener_siguiente());

        anterior -> cambiar_siguiente(nuevo);

    }
    cantidad++;
}


template <typename Tipo>

void Lista<Tipo>::baja(int pos) {

    Nodo<Tipo>* borrar = primero;

    if(pos == 0)
        primero = primero -> obtener_siguiente();
    else {
        Nodo<Tipo>* anterior = obtener_nodo(pos - 1);
        borrar = anterior -> obtener_siguiente();
        anterior -> cambiar_siguiente(borrar -> obtener_siguiente());
    }
    cantidad--;

    if(!eliminar_dato) {
        borrar -> asignar_dato_a_null();
    }


    delete borrar; 
}


template <typename Tipo>

void Lista<Tipo>::imprimir_lista_escritores() {

    int indice = 1;
    inicializar();
    while(actual != NULL) {
        cout << "["<< indice <<"] - ";
        actual -> obtener_dato() -> mostrar_escritor();
        actual = actual -> obtener_siguiente();
        indice++;
    }
}


template <typename Tipo>

void Lista<Tipo>::imprimir_lista_lecturas() {

    int indice = 1;
    inicializar();
    while(actual != NULL) {
        cout << "["<< indice <<"] - ";
        actual -> obtener_dato() -> mostrar_lectura();
        actual = actual -> obtener_siguiente();
        indice++;
    }
}


template <typename Tipo>

Lista<Tipo>::~Lista() {
    while(!vacia())
        baja(0);
}


# endif