# include "Escritor.h"


Escritor::Escritor(string nombre, string apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento) {

    nombre_ = nombre;
    apellido_ = apellido;
    nacionalidad_ = nacionalidad;
    anio_nacimiento_ = anio_nacimiento;
    anio_fallecimiento_ = anio_fallecimiento;
}


string Escritor::obtener_nombre_completo() {

    return (nombre_ + " ") + apellido_;
}

string Escritor::obtener_nacionalidad() {

    return nacionalidad_;
}

bool Escritor::verificar_fallecimiento() {

    return anio_fallecimiento_ == ANIO_DESCONOCIDO;
}


void Escritor::asignar_fallecimiento(int anio) {

    anio_fallecimiento_ = anio;
}

void Escritor::mostrar_escritor() {

    cout << obtener_nombre_completo() << endl;

    cout << "Nacionalidad: " << nacionalidad_ << endl;

    if(anio_fallecimiento_ != ANIO_DESCONOCIDO && anio_nacimiento_ != ANIO_DESCONOCIDO)
        cout << anio_nacimiento_ << " - " << anio_fallecimiento_ << endl;

    else if (anio_nacimiento_ == ANIO_DESCONOCIDO && anio_fallecimiento_ != ANIO_DESCONOCIDO)
        cout << "Desconocido" << " - " << anio_fallecimiento_ << endl;

    else if (anio_nacimiento_ != ANIO_DESCONOCIDO && anio_fallecimiento_ == ANIO_DESCONOCIDO)
        cout << anio_nacimiento_ << " - " << "actualidad o desconocido" << endl;

    else 
        cout << "Desconocido" << " - " << "actualidad o desconocido" << endl;
    cout << endl;
}

Escritor::Escritor() {

}