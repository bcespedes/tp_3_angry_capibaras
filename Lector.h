# ifndef LECTOR_H
# define LECTOR_H


# include <fstream>
# include "Escritor.h"
# include "Lista.h"
# include "Historica.h"
# include "Poema.h"
# include "Cuento.h"
# include "constantes.h"


class Lector {
    
protected:

    // METODOS
    int obtener_referencia(string referencia);
    virtual bool validar_archivo(ifstream &archivo) = 0;

public:

    Lector();
    

};


# endif