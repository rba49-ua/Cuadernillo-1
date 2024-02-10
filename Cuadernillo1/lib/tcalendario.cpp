#include "../include/tcalendario.h"

bool TCalendario::comprobarFecha(int dia, int mes, int anyo) {
    if(anyo<1900 || dia<1 || dia>31 || mes<1 || mes>12){
        return false;
    }
    if(!bisiesto(anyo) && mes==2 && dia>28){
        return false;
    }
    else{
        if(bisiesto(anyo) && mes==2 && dia>29){
            return false;
        }
    }
    if((mes==4 || mes==6 || mes==9 || mes==11) && dia>30){
        return false;
    }
    return true;
}

bool TCalendario::bisiesto(int anyo) {
    if(anyo %4 == 0 and (anyo %100 != 0 or anyo %400 == 0)){
        return true;
    }
    return false;
}

void TCalendario::defaultParameters(){
    this->dia = 1;
    this->mes = 1;
    this->anyo = 1900;
    mensaje = NULL;
}


void TCalendario::copia(const TCalendario &c){
    dia=c.dia;
    mes=c.mes;
    anyo=c.anyo;
    mensaje=c.mensaje;
}
TCalendario::TCalendario(){
    defaultParameters();
}

TCalendario::TCalendario(int dia, int mes, int anyo, char *mens) {
    if(comprobarFecha(dia, mes, anyo)){
        this->dia=dia;
        this->mes=mes;
        this->anyo=anyo;
        this->mensaje=mens;
    }
    else{
        defaultParameters();
    }
}

TCalendario::TCalendario(TCalendario & c) {
    copia(c);
}

TCalendario::~TCalendario() {
    defaultParameters();
}

TCalendario& TCalendario::operator=(const TCalendario & op2) {
    if(this != &op2){
        (*this).~TCalendario();
        copia(op2);
    }

    return *this;
}

TCalendario TCalendario::operator+(int cantDias) {
    TCalendario temp(*this);

    for(int i=0;i<cantDias; i++){
        temp++;
    }
    return temp;
}

TCalendario TCalendario::operator-(int cantDias) {
    TCalendario temp(*this);

    for(int i=0;i<cantDias; i++){
        temp--;
    }

    if(!comprobarFecha(temp.dia, temp.mes, temp.anyo)){
        defaultParameters();
    }
    return temp;
}

TCalendario TCalendario::operator++(int cantDias) {
    TCalendario temp(*this);
}

TCalendario &TCalendario::operator++() {

}

TCalendario TCalendario::operator--(int op2) {
    TCalendario temp(*this);
}

TCalendario &TCalendario::operator--() {

}



bool TCalendario::operator==(const TCalendario &op2) {
    bool temp;
    if(dia==op2.dia && mes==op2.mes && anyo==op2.anyo && mensaje==op2.mensaje){
        temp=true;
    }
    else{
        temp=false;
    }
    return temp;
}

bool TCalendario::operator!=(const TCalendario &op2) {
    return !(*this == op2);
}

bool TCalendario::EsVacio() {
    return (this->dia == 1 and this->mes == 1 and this->anyo == 1900 and mensaje == NULL);
}

int TCalendario::Dia() {
    return this->dia;
}

int TCalendario::Mes() {
    return this->mes;
}

int TCalendario::Anyo() {
    return this->anyo;
}

char* TCalendario::Mensaje() {
    return this->mensaje;
}





