#include "../include/tvectorcalendario.h"
using namespace std;


void TVectorCalendario::defaultParameters() {
    this-> c = NULL;
    this-> tamano = 0;
}


void TVectorCalendario::copia(const TVectorCalendario &vc){
    this->tamano=vc.tamano;
    if(tamano ==0)
    {
        c = NULL;
    }
    else{
        c= new TCalendario[tamano];
        for (int i=1;i<=tamano;i++){
            c[i]=vc[i];
        }
    }
}


TVectorCalendario::TVectorCalendario() {
    defaultParameters();
}

TVectorCalendario::TVectorCalendario(int tam) {
    if(tam<0){
        defaultParameters();
    }
    else{
        this-> tamano = tam;
        this -> c = new TCalendario[this->tamano];
    }
}

TVectorCalendario::TVectorCalendario(TVectorCalendario & vc) {
    copia(vc);
}

TVectorCalendario::~TVectorCalendario(){
    tamano = 0;
    if (c != NULL){
        delete [] c;
        c = NULL;
    }
}

TVectorCalendario &TVectorCalendario::operator=(const TVectorCalendario &vc) {

}

bool TVectorCalendario::operator==(const TVectorCalendario & vc){
    if(this->tamano != vc.tamano){
        return false;
    }
}


bool TVectorCalendario::operator!=(const TVectorCalendario & vc) {
    return !(*this == vc);
}

TCalendario &TVectorCalendario::operator[] (int a){

}

TCalendario TVectorCalendario::operator[] (int a) const{

}


int TVectorCalendario::Tamano(){
    return tamano;
}
