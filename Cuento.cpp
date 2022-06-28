# include "Cuento.h"


Cuento::Cuento(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, bool leido, string libro) 
    : Lectura(titulo, minutos, anio, escritor, leido) {

        libro_ = libro;
}


string Cuento::obtener_libro() {

    return libro_;
}


void Cuento::mostrar_lectura() {
    
    cout << "Cuento" << endl;
    cout << titulo_ << endl;
    cout << "Minutos estimados: " << minutos_ << endl;
    cout << "Publicacion: " << anio_ << endl;
    cout << "Libro: " << libro_ << endl;
    
    cout << "Autor: ";

    if(escritor_ != NULL)
        escritor_ -> mostrar_escritor();
    else
        cout << "ANONIMO" << endl << endl;
}


char Cuento::tipo_lectura(){
    return 'C';
}

bool Cuento::coinciden_generos(int genero) {

    return false;
}