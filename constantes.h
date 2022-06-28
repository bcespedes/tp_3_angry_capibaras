# ifndef CONSTANTES_H
# define CONSTANTES_H


# include <string>


// CONSTANTES GENERALES
const int OPCION_MINIMA = 1;

const std::string VOLVER_A_INTENTAR = "\nIntentalo nuevamente. ";


// CONSTANTES DE LA CLASE NOVELA
enum generos {
    DRAMA = 1,
    COMEDIA,
    FICCION,
    SUSPENSO,
    TERROR,
    ROMANTICA,
    HISTORICA
};


// CONSTANTES DEL MENU PRINCIPAL.
const int OPCION_MAXIMA_MENU = 14;

const std::string OPCION_1 = "1. Agregar una nueva lectura a la lista";
const std::string OPCION_2 = "2. Quitar una lectura de la lista";
const std::string OPCION_3 = "3. Agregar un escritor";
const std::string OPCION_4 = "4. Cambiar fecha de fallecimiento de un escritor";
const std::string OPCION_5 = "5. Listar los escritores";
const std::string OPCION_6 = "6. Sortear una lectura random para leer en una de las tertulias";
const std::string OPCION_7 = "7. Listar todas las lecturas";
const std::string OPCION_8 = "8. Listar las lecturas entre determinados anios";
const std::string OPCION_9 = "9. Listar las lecturas de un determinado escritor";
const std::string OPCION_10 = "10. Listar las novelas de determinado genero";
const std::string OPCION_11 = "11. Armar una cola ordenada por tiempo de lectura";
const std::string OPCION_12 = "12. Mostrar orden y tiempo minimo para leer todas las lecturas";
const std::string OPCION_13 = "13. Salir\n";

const std::string OPCION_INVALIDA_MENU = "Por favor seleccione una opcion valida" ;
const std::string ESCRIBA_OPCION_MENU = "Escriba una opcion: ";
const std::string MENSAJE_BIENVENIDA_MENU =  "Bienvenidos al club de lectura de Sid! Elija lo que desea realizar. \n";
const std::string MENSAJE_DESPEDIDA_MENU =  "Gracias por venir al club de lectura de Sid! Esperamos verte pronto de vuelta <3\n";
const std::string PRESIONE_ENTER = "Presione Enter para continuar: ";

enum cant_opciones_menu {
     AGREGAR_LECTURA = 1,
     QUITAR_LECTURA,
     AGREGAR_ESCRITOR,
     CAMBIAR_FALLECIMIENTO,
     LISTAR_ESCRITORES,
     SORTEAR_LECTURA,
     LISTAR_LECTURAS,
     LISTAR_LECTURAS_POR_PERIODOS,
     LISTAR_LECTURA_POR_ESCRITOR,
     LISTAR_NOVELAS_POR_GENERO,
     ARMAR_COLA,
     MENOR_TIEMPO_LECTURA,
     SALIR,
     COCINAR_PASTEL_DE_PAPA
};

// CONSTANTES DE LA CLASE UTILIDADES
const std::string ERROR_TIPO_DE_DATO = "\nNo has ingresado el tipo de dato esperado.";

// CONSTANTES DE LA CLASE PROCESAMIENTO DE OPCIONES
const int OPCION_ALTERNATIVA = -1;
const int ISNI_MINIMO = 1000;
const int ISNI_MAXIMO = 9999;

const std::string LISTA_ESCRITORES_VACIA = "No hay escritores cargados. Puedes agregarlos manualmente.\n";
const std::string LISTA_LECTURAS_VACIA = "No hay lecturas cargadas. Puedes agregarlas manualmente.\n";
const std::string ERROR_INGRESO_INCORRECTO = "\nHas ingresado algo erroneo.";
const std::string SI_O_NO = " (S / N): ";

const char SI = 'S';
const char NO = 'N';

// CONSTANTES DE LAS CLASES DE LECTURA DE ARCHIVOS
const int EOF_NACIMIENTO_FALTANTE = 5;
const int EOF_AMBOS_ANIOS_FALTANTES = 4;
const int ANONIMO = -1;

const std::string ANIO_INEXISTENTE = "-1";
const std::string ERROR_APERTURA_ESCRITORES = "No se pudo abrir el archivo de escritores, puede agregarlos manualmente!\n";
const std::string ERROR_APERTURA_LECTURAS = "No se pudo abrir el archivo lecturas, puede agregarlas manualmente!\n";
const std::string ESCRITORES = "escritores.txt";
const std::string LECTURAS = "lecturas.txt";

const char NOVELA = 'N';
const char CUENTO = 'C';
const char POEMA = 'P';
const char NOV_HISTORICA = 'H';

// CONSTANTES DE LA CLASE LECTURA
const int ES_MAYOR = 1;
const int ES_MENOR = -1;
const int ES_IGUAL = 0;

// CONSTANTES DE LA CLASE ESCRITOR
const int ANIO_DESCONOCIDO = -1;

// CONSTANTES DE LA CLASE HASH
const int CANTIDAD_CLAVES = 20;

const double FACTOR_CARGA = 0.8;

const std::string ERROR_ISNI_INVALIDO = "\nNo se ha encontrado ningun escritor con ese ISNI.";
const std::string ERROR_ISNI_USADO = "\nYa hay un escritor cargado con ese ISNI.";


# endif