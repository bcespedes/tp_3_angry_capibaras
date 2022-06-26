# include "LectorLecturas.h"
# include <string.h>


Escritor* LectorLecturas::obtener_escritor(Hash* tabla, int isni) {

    if(isni == ANONIMO)
        return NULL;

    return tabla -> consulta(isni);
}


bool LectorLecturas::validar_archivo(ifstream &archivo_lecturas) {
    bool abierto = true;
    if(!archivo_lecturas.is_open()) {
        cout << ERROR_APERTURA_LECTURAS << endl;
        abierto = false;
    }

    return abierto;
}


generos LectorLecturas::convertir_a_genero(string genero) {

    generos genero_en_enum;
    
    if(genero == "DRAMA") genero_en_enum = DRAMA;
    if(genero == "FICCION") genero_en_enum = FICCION;
    if(genero == "TERROR") genero_en_enum = TERROR;
    if(genero == "COMEDIA") genero_en_enum = COMEDIA;
    if(genero == "SUSPENSO") genero_en_enum = SUSPENSO;
    if(genero == "ROMANTICA") genero_en_enum = ROMANTICA;

    return genero_en_enum;
}


Lectura* LectorLecturas::crear_historica(string titulo, int minutos, int anio, string tema, Escritor* escritor, bool leido) {

    char* tema_historico = new char[tema.length() + 1];
    strcpy(tema_historico, tema.c_str());
    Lectura* historica = new Historica(titulo, minutos, anio, escritor, leido, HISTORICA, tema_historico);
    return historica;
}


Lectura* LectorLecturas::crear_novela(string titulo, int duracion, int anio, Hash* tabla_escritores, ifstream &archivo_lecturas, bool leido) {

    string genero, isni;
    getline(archivo_lecturas, genero);
    Lectura* novela;

    if(genero == "HISTORICA") {
        string tema_historico;
        getline(archivo_lecturas, tema_historico);
        getline(archivo_lecturas, isni);
        novela = crear_historica(titulo, duracion, anio , tema_historico, obtener_escritor(tabla_escritores, obtener_isni(isni)), leido);
    }
    else {
        getline(archivo_lecturas, isni);
        novela = new Novela(titulo, duracion, anio,  obtener_escritor(tabla_escritores, obtener_isni(isni)), leido, convertir_a_genero(genero));
    }
    
    return novela;
}


Lectura* LectorLecturas::crear_cuento(string titulo, int minutos, int anio, Hash* tabla_escritores, ifstream &archivo_lecturas, bool leido) {

    string libro_publicado, isni;
    
    getline(archivo_lecturas, libro_publicado);
    getline(archivo_lecturas, isni);
    
    Lectura* cuento = new Cuento(titulo, minutos, anio, obtener_escritor(tabla_escritores, obtener_isni(isni)), leido, libro_publicado);

    return cuento;
}


Lectura* LectorLecturas::crear_poema(string titulo, int minutos, int anio,  Hash* tabla_escritores, ifstream &archivo_lecturas, bool leido) {
    
    string cant_versos, isni;

    getline(archivo_lecturas, cant_versos);
    getline(archivo_lecturas, isni);
    
    Lectura* poema = new Poema(titulo, minutos, anio, obtener_escritor(tabla_escritores, obtener_isni(isni)), leido, stoi(cant_versos));

    return poema;
}


Lectura* LectorLecturas::crear_lectura(ifstream &archivo_lecturas, Hash* tabla_escritores) {

    char tipo_lectura;
    string titulo, duracion, anio, referencia, genero, tema_historico, cant_versos, libro_publicado;
    bool leido = false;
    archivo_lecturas >> tipo_lectura;
    archivo_lecturas.ignore();
    getline(archivo_lecturas, titulo);
    getline(archivo_lecturas, duracion);
    getline(archivo_lecturas, anio);

    Lectura* lectura;

    if(tipo_lectura == NOVELA)
        lectura = crear_novela(titulo, stoi(duracion), stoi(anio), tabla_escritores, archivo_lecturas, leido);

    else if (tipo_lectura == CUENTO)
        lectura = crear_cuento(titulo, stoi(duracion), stoi(anio), tabla_escritores, archivo_lecturas, leido);
        
    else
        lectura = crear_poema(titulo, stoi(duracion), stoi(anio), tabla_escritores, archivo_lecturas, leido);


    return lectura;

}

Lista<Lectura*>* LectorLecturas::procesar_lecturas(Hash* tabla_escritores) {

    Utilidades insertador;
    ifstream archivo_lecturas(LECTURAS);
    Lista<Lectura*>* lista_lecturas = new Lista<Lectura*>();

    if(validar_archivo(archivo_lecturas)) {

        Lectura* lectura;
        while(!archivo_lecturas.eof()) {

            lectura = crear_lectura(archivo_lecturas, tabla_escritores);
            insertador.insertar_lectura_ordenada(lectura, lista_lecturas);
        }
    }

    archivo_lecturas.close();

    return lista_lecturas;
}