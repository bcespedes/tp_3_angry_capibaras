# ifndef CUENTO_H
# define CUENTO_H


# include "Lectura.h"


class Cuento: public Lectura {

private:

    string libro_;

public:

    // PRE: Los datos son validos.
    // POST: Se crea un Cuento.
    Cuento(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, bool leido, string libro);

    // PRE: -
    // POST: Devuelve el libro donde esta publicado el cuento.
    string obtener_libro();

    // PRE: -
    // POST: Muestra por pantalla las caracteristicas del cuento.
    void mostrar_lectura();

    // PRE: -
    // POST: devuelve un char 'C'.
    char tipo_lectura();

    // PRE: -
    // POST: Devuelve false, pues un Cuento no tiene genero.
    bool coinciden_generos(int genero);

};


# endif