using namespace std;
#include "../include/tcalendario.h"

bool TCalendario::ComprobarFecha(int dia, int mes, int anyo) {
    if(anyo<1900 || dia<1 || dia>31 || mes<1 || mes>12){
        return false;
    }
    if(!Bisiesto(anyo) && mes==2 && dia>28){
        return false;
    }
    else{
        if(Bisiesto(anyo) && mes==2 && dia>29){
            return false;
        }
    }
    if((mes==4 || mes==6 || mes==9 || mes==11) && dia>30){
        return false;
    }
    return true;
}

bool TCalendario::Bisiesto(int anyo) {
    if(anyo %4 == 0 and (anyo %100 != 0 or anyo %400 == 0)){
        return true;
    }
    return false;

}


void TCalendario::Copia(const TCalendario &c){
    dia=c.dia;
    mes=c.mes;
    anyo=c.anyo;
    mensaje=c.mensaje;
}
TCalendario::TCalendario(){
    this->dia = 1;
    this->mes = 1;
    this->anyo = 1900;
    mensaje = NULL;
}

TCalendario::TCalendario(int dia, int mes, int anyo, char *mens) {

}

TCalendario::TCalendario(TCalendario & c) {
    Copia(c);
}

TCalendario::~TCalendario() {

}

TCalendario& TCalendario::operator=(TCalendario & op2) {
    if(this != &op2){
        (*this).~TCalendario();
        Copia(op2);
    }

    return *this;
}

TCalendario &TCalendario::operator++() {

}

TCalendario TCalendario::operator++(int op2) {
    TCalendario temp(*this);


}

bool TCalendario::operator==(TCalendario &op2) {
    bool temp;
    if(dia==op2.dia && mes==op2.mes && anyo==op2.anyo && mensaje==op2.mensaje){
        temp=true;
    }
    else{
        temp=false;
    }
    return temp;
}

bool TCalendario::operator!=(TCalendario &op2) {
    return !(*this == op2);
}

bool TCalendario::EsVacio() {
    if(this->dia == 1 and this->mes == 1 and this->anyo == 1900 and mensaje == NULL){
        return true;
    }
    return false;
}




