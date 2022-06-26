# ifndef LECTOR_LECTURAS_H
# define LECTOR_LECTURAS_H


# include "Lector.h"
# include "Utilidades.h"


class LectorLecturas : public Lector {

private:

    // METODOS
    Escritor* obtener_escritor(Hash* tabla, int isni);
    Lectura* crear_historica(string titulo, int minutos, int anio, string tema, Escritor* escritor, bool leido);
    Lectura* crear_novela(string titulo, int duracion, int anio, Hash* tabla_escritores, ifstream &archivo_lecturas, bool leido);
    Lectura* crear_cuento(string titulo, int duracion, int anio,  Hash* tabla_escritores, ifstream &archivo_lecturas, bool leido);
    Lectura* crear_poema(string titulo, int duracion, int anio, Hash* tabla_escritores, ifstream &archivo_lecturas, bool leido);
    Lectura* crear_lectura(ifstream &archivo_lecturas, Hash* tabla_escritores);
    generos convertir_a_genero(string genero);
    bool validar_archivo(ifstream &archivo_lecturas);

public: 

    // PRE: El metodo necesita un texto con lecturas.
    // POST: Devuelve una lista con las respectivas lecturas.
    Lista<Lectura *>* procesar_lecturas(Hash* tabla_escritores);

};


# endif