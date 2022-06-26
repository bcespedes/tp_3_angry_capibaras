# include "Novela.h"
# include "Historica.h"


Novela::Novela(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, bool leido, generos genero)
 : Lectura(titulo, minutos, anio, escritor, leido) {

    genero_ = genero;
}


generos Novela::obtener_genero() {

    return genero_;
}


string Novela::convertir_genero_a_string() {

    string gen;
    
    if(genero_ == DRAMA) gen = "DRAMA";
    if(genero_ == FICCION)gen = "FICCION";
    if(genero_ == TERROR) gen = "TERROR";
    if(genero_ == COMEDIA) gen = "COMEDIA";
    if(genero_ == SUSPENSO) gen = "SUSPENSO";
    if(genero_ == ROMANTICA) gen = "ROMANTICA";

    return gen;
}


void Novela::mostrar_lectura() {
    
    cout << "Novela" << endl;
    cout << titulo_ << endl;
    cout << "Minutos estimados: " << minutos_ << endl;
    cout << "Publicacion: " << anio_ << endl;
    cout << "Genero: " << convertir_genero_a_string() << endl;

    cout << "Autor: ";
    if(escritor_ != NULL)
        escritor_ -> mostrar_escritor();
    else
        cout << "ANONIMO" << endl << endl;
}


bool Novela::coinciden_generos(int genero) {

    bool coinciden = false;

    if(genero_ == genero)
        coinciden = true;

    return coinciden;
}