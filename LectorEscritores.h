# ifndef LECTOR_ESCRITORES_H
# define LECTOR_ESCRITORES_H


# include "Lector.h"


class LectorEscritores : public Lector {

private:

    // METODOS
    void faltan_anios(string &anio_nacimiento, string &anio_fallecimiento);
    void validar_anios_fin_archivo(int leidos, string &anio_nacimiento, string &anio_fallecimiento);
    void falta_fallecimiento(string &anio_fallecimiento);
    bool validar_archivo(ifstream &archivo_escritores);
    Escritor* crear_escritor(ifstream &archivo_escritores);

public:

    // PRE: El metodo necesita un texto con escritores para procesar.
    // POST: Devuelve una lista con los respectivos escritores
    Lista<Escritor*>* procesar_escritores();

};


# endif