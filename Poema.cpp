# include "Poema.h"


Poema::Poema(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, bool leido, int versos) 
    : Lectura(titulo, minutos, anio, escritor, leido) {

        versos_ = versos;
}


int Poema::obtener_versos() {

    return versos_;
}


void Poema::mostrar_lectura() {

    cout << "Poema" << endl;
    cout << titulo_ << endl;
    cout << "Minutos estimados: " << minutos_ << endl;
    cout << "Publicacion: " << anio_ << endl;
    cout << "Cant de versos: " << versos_ << endl;
    
    cout << "Autor: ";
    if(escritor_ != nullptr)
        escritor_ -> mostrar_escritor();
    else
        cout << "ANONIMO" << endl << endl;
}

char Poema::tipo_lectura(){
    return 'P';
}


bool Poema::coinciden_generos(int genero) {

    return false;
}