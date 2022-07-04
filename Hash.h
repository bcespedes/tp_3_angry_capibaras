# ifndef HASH_H
# define HASH_H


# include <cmath>
# include "constantes.h"
# include "Lista.h"
# include "Escritor.h"


class Hash {

private:

    // ATRIBUTOS
    int tamanio_tabla_;
    Lista<Escritor*>** tabla_hash_;

    // METODOS
    int aplicar_division(int clave);
    int obtener_posicion_elemento(int clave);

public:

    // PRE: -
    // POST: Crea una tabla de hash con punteros a listas vacías.
    Hash();

    // PRE: -
    // POST: Devuelve true si la tabla de hash esta completamente vacia, false de lo contrario.
    bool vacia();

    // PRE: Recibe una clave que debe ser un entero.
    // POST: Devuelve true si se encuentra la clave en la tabla, false de lo contrario.
    bool esta_el_elemento(int clave);

    // PRE: Recibe un escritor valido.
    // POST: Da de alta al escritor en la tabla de hashing.
    void alta(Escritor* escritor);

    // PRE: Recibe una clave que debe ser un entero. La clave debe existir en la tabla.
    // POST: Da de baja el elemento con la clave correspondiente en caso de existir.
    void baja(int clave);

    // PRE: Recibe una clave que debe ser un entero. La clave debe existir en la tabla.
    // POST: Devuelve el escritor correspondiente a esa clave.
    Escritor* consulta(int clave);

    // PRE: Recibe un booleano que indica si se deben mostrar o no solo los nombres.
    // POST: Imprime los escritores que hay en la tabla segun corresponda.
    void imprimir_escritores(bool solo_nombres);

    // PRE: -
    // POST: Destruye todas las listas de la tabla y la tabla.
    ~Hash();

};


# endif