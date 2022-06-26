# include "Lector.h"
# include <string>


Lector::Lector() {

}

int Lector::obtener_isni(string isni) {

    string num = "";
    if(isni != "ANONIMO") {
        for(int i = 1; isni[i] != ')'; i++)
            num += isni[i];
    }
    else 
        num = "-1";

    return stoi(num);
}