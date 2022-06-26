# include "Lectura.h"


Lectura::Lectura(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, bool leido) {

    titulo_ = titulo;
    minutos_ = minutos;
    anio_ = anio;
    escritor_ = escritor;
    leido_ = leido;
};

string Lectura::obtener_titulo() {

    return titulo_;
}

unsigned int Lectura::obtener_minutos() {

    return minutos_;
}

unsigned int Lectura::obtener_anio() {

    return anio_;
}

Escritor* Lectura::obtener_escritor() {

    return escritor_;
}


bool Lectura::fue_leido() {

    return leido_;
}


void Lectura::leido(bool leido) {
    leido_ = leido;
}


int Lectura::comparar_por_anio(Lectura* a_comparar) {

    int devolver;

    if(anio_ < a_comparar -> obtener_anio())
        devolver = ES_MENOR;
    else if(anio_ > a_comparar -> obtener_anio())
        devolver = ES_MAYOR;
    else devolver = ES_IGUAL;


    return devolver;
}

int Lectura::comparar_por_duracion(Lectura* a_comparar){

    int devolver;

    if(minutos_ < a_comparar -> obtener_minutos())
        devolver = ES_MENOR;
    else if(minutos_ > a_comparar -> obtener_minutos())
        devolver = ES_MAYOR;
    else devolver = ES_IGUAL;


    return devolver;

}


Lectura::~Lectura() {

}