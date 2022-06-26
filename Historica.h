# ifndef HISTORICA_H
# define HISTORICA_H


# include "Novela.h"


class Historica: public Novela {

private:

    char* tema_;

public:

    // PRE: Genero tiene que ser historica. El tema debe ser una cadena dinamica.
    // POST: Crea un objeto historica.
    Historica(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, bool leido, generos genero, char* tema);
    
    // PRE: -
    // POST: Se devuelve el tema de la novela historica.
    char* obtener_tema();

    // PRE: -
    // POST: Muestra por pantalla las caracteristicas de la novela historica.
    void mostrar_lectura();

    // PRE: Genero es un genero valido.
    // POST: Devuelve true si genero es HISTORICA, false de caso contrario.
    bool coinciden_generos(int genero);

    // PRE: -
    // POST: Destruye la novela historica.
    ~Historica();

};


# endif