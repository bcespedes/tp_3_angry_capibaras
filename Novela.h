# ifndef NOVELA_H
# define NOVELA_H

# include "constantes.h"
# include "Lectura.h"


class Novela: public Lectura {

protected:

    generos genero_;

public:

    // PRE: Los datos son validos.
    // POST: Crea una novela.
    Novela(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, bool leido, generos genero);

    // PRE: -
    // POST: Devuelve el genero de la novela.
    generos obtener_genero();

    // PRE: -
    // POST: Muestra por pantalla las caracteristicas de la novela.
    void mostrar_lectura();

    // PRE: -
    // POST: Devuelve un string con el genero de la novela.
    string convertir_genero_a_string();

    // PRE: genero es un genero valido. (ver indices de genero en enum)
    // POST: Devuelve true si genero es igual al genero de la novela, false en caso contrario.
    bool coinciden_generos(int genero);

};


# endif