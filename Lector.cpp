# include "Lector.h"
# include <string>


Lector::Lector() {

}

int Lector::obtener_referencia(string referencia) {

    string num = "";
    if(referencia != "ANONIMO") {
        for(int i = 1; referencia[i] != ')'; i++)
            num += referencia[i];
    }
    else 
        num = "-1";

    return stoi(num);
}