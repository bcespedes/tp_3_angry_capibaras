# include "LectorEscritores.h"


void LectorEscritores::faltan_anios(string &anio_nacimiento, string &anio_fallecimiento) {

    anio_nacimiento = ANIO_INEXISTENTE;
    anio_fallecimiento = ANIO_INEXISTENTE;
}


void LectorEscritores::falta_fallecimiento(string &anio_fallecimiento) {

    anio_fallecimiento = ANIO_INEXISTENTE;
}


void LectorEscritores::validar_anios_fin_archivo(int leido, string &anio_nacimiento, string &anio_fallecimiento) {

    if(leido == EOF_NACIMIENTO_FALTANTE) 
        anio_fallecimiento = ANIO_INEXISTENTE;

    else if(leido == EOF_AMBOS_ANIOS_FALTANTES) {
        anio_nacimiento = ANIO_INEXISTENTE;
        anio_fallecimiento = ANIO_INEXISTENTE;
    }
}


Escritor* LectorEscritores::crear_escritor(ifstream &archivo_escritores) {

    string nombre, apellido, nacionalidad, referencia, anio_nacimiento, anio_fallecimiento;

    int leido = 0;
            
    archivo_escritores >> referencia;
    archivo_escritores.ignore();
    getline(archivo_escritores, nombre, ' ');
    getline(archivo_escritores, apellido);
    getline(archivo_escritores, nacionalidad);
    leido = 4;
    if(getline(archivo_escritores, anio_nacimiento))       
        leido++;
    if(anio_nacimiento.empty()) {
        faltan_anios(anio_nacimiento, anio_fallecimiento);
        leido++;  
    }      
    else if(getline(archivo_escritores, anio_fallecimiento))
        leido++;
    if(anio_fallecimiento.empty())
        falta_fallecimiento(anio_fallecimiento);
    validar_anios_fin_archivo(leido, anio_nacimiento, anio_fallecimiento);

    Escritor* escritor = new Escritor(nombre, apellido, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento));

    return escritor;
}


bool LectorEscritores::validar_archivo(ifstream &archivo_escritores) {

    bool abierto = true;
    if(!archivo_escritores.is_open()) {
        cout << ERROR_APERTURA_ESCRITORES << endl;
        abierto = false;
    }

    return abierto;
}


Lista<Escritor*>* LectorEscritores::procesar_escritores() {

    ifstream archivo_escritores(ESCRITORES);

    Lista<Escritor*>* lista_escritores = new Lista<Escritor*>();
    if(validar_archivo(archivo_escritores)) { 

        int indice = 0;
        
        while(!archivo_escritores.eof()) {

            Escritor* escritor = crear_escritor(archivo_escritores);
            lista_escritores -> alta(escritor, indice);
            indice++;

        }

    }

    archivo_escritores.close();

    return lista_escritores;
}