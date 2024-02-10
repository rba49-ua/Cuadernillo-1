#include "../include/tcalendario.h"
#include <cstring>

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

int TCalendario::diasEnMes(int mes, int anyo){
    switch(mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if(bisiesto(anyo)){
                return 29;
            }
            return 28;
    }
}


TCalendario TCalendario::ajustarFecha(TCalendario &c) {
    while(c.dia> diasEnMes(c.mes, c.anyo)){
        c.dia--;
        if(c.dia == 0){
            c.mes--;
            if(c.mes == 0){
                c.anyo--;
                c.mes=12;
            }
        }
    }
    return c;
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
    if(c.mensaje != NULL){
        this->mensaje = new char[strlen(c.mensaje)+1];
        strcpy(this->mensaje, c.mensaje);
    }
    else this->mensaje = NULL;
}


TCalendario::TCalendario(){
    defaultParameters();
}


TCalendario::TCalendario(int dia, int mes, int anyo, char *mens) {
    if(comprobarFecha(dia, mes, anyo)){
        this->dia=dia;
        this->mes=mes;
        this->anyo=anyo;
        if(mens == NULL){
            this->mensaje= NULL;
        }
        else{
            this->mensaje= new char[strlen(mens) +1];
            strcpy(this->mensaje,mens);
        }
    }
    else{
        defaultParameters();
    }
}

TCalendario::TCalendario(TCalendario & c) {
    copia(c);
}

TCalendario::~TCalendario() {
    this->dia=1;
    this->mes=1;
    this->anyo=1900;

    if(this->mensaje != NULL){
        delete [] this->mensaje;
    }
    this->mensaje= NULL;

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
        temp.dia++;
    }
    ajustarFecha(temp);
    return temp;
}

TCalendario TCalendario::operator-(int cantDias) {
    TCalendario temp(*this);

    for(int i=0;i<cantDias; i++){
        temp.dia--;
    }
    ajustarFecha(temp);

    if(!comprobarFecha(temp.dia, temp.mes, temp.anyo)){
        temp.~TCalendario();
    }
    return temp;
}

TCalendario TCalendario::operator++(int cantDias) {
    TCalendario temp(*this);
    temp.dia++;
    temp.mes++;
    temp.anyo++;
    ajustarFecha(temp);
    return temp;


}

TCalendario &TCalendario::operator++() {
    TCalendario temp(*this);
    temp.dia++;
    temp.mes++;
    temp.anyo++;
    ajustarFecha(temp);
    return *this;
}

TCalendario TCalendario::operator--(int cantDias) {
    TCalendario temp(*this);
    temp.dia--;
    temp.mes--;
    temp.anyo--;
    ajustarFecha(temp);

    if(!comprobarFecha(temp.dia, temp.mes, temp.anyo)){
        temp.~TCalendario();
    }
    return temp;
}

TCalendario &TCalendario::operator--() {
    TCalendario temp(*this);
    temp.dia--;
    temp.mes--;
    temp.anyo--;
    ajustarFecha(temp);

    if(!comprobarFecha(temp.dia, temp.mes, temp.anyo)){
        temp.~TCalendario();
    }
    return *this;
}

bool TCalendario::ModFecha(int dia, int mes, int anyo) {
    if(!comprobarFecha(dia, mes, anyo)){
        return false;
    }
    this->dia=dia;
    this->mes=mes;
    this->anyo=anyo;
    return true;
}

bool TCalendario::ModMensaje(char * mensaje) {
    if(mensaje ==NULL){
        this->mensaje=NULL;
        return true;
    }

    if(strcmp(this->mensaje, mensaje) ==0){
        return false;
    }

    delete [] this->mensaje;
    this->mensaje=new char [strlen(mensaje)+1];
    strcpy(this->mensaje,mensaje);
    return true;
}


bool TCalendario::operator==(const TCalendario &c) {
    if(dia==c.dia && mes==c.mes && anyo==c.anyo){
        if(mensaje==NULL && c.mensaje==NULL){
            return true;
        }
        else{
            if(strcmp(mensaje, c.mensaje) == 0){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        return false;
    }
}

bool TCalendario::operator!=(const TCalendario &c) {
    return !(*this == c);
}

bool TCalendario::operator>(const TCalendario &c) {
    if(this->anyo > c.anyo){
        return true;
    }

    if(this->anyo == c.anyo && this->mes > c.mes){
        return true;
    }

    if(this->anyo == c.anyo && this->mes == c.mes && this->dia > c.dia){
        return true;
    }

    if(this->anyo == c.anyo && this->mes == c.mes && this->dia == c.dia){
        if(this->mensaje == NULL){
            return false;
        }

        if(c.mensaje == NULL){
            return true;
        }

        if(strcmp(this->mensaje, c.mensaje) > 0){
            return true;
        }
    }
    return false;
}

bool TCalendario::operator<(const TCalendario &c) {
    return !(*this > c);
}

bool TCalendario::EsVacio() {
    return (this->dia == 1 and this->mes == 1 and this->anyo == 1900 and this->mensaje == NULL);
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

ostream &operator<<(ostream &s, const TCalendario &c){
    if(c.dia < 10){
        s << "0";
    }
    s << c.dia << "/";

    if(c.mes < 10){
        s << "0";
    }
    s << c.mes << "/" << c.anyo << " ";

    if(c.mensaje == NULL){
        s << "\"\"";
    }
    else{
        s <<  "\"" << c.mensaje << "\"";
    }

    return s;
}





