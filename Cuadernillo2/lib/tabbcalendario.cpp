#include "../include/tabbcalendario.h"

void TNodoABB::Copia(const TNodoABB &other){
    item = other.item;
    iz = other.iz;
    de = other.de;
}

TNodoABB::TNodoABB( ):item(), iz(),de(){}

TNodoABB::TNodoABB(const TNodoABB &other) {
    Copia(other);
}

TNodoABB::~TNodoABB() {}

TNodoABB &TNodoABB::operator=(const TNodoABB &other){
    if(this != &other){
        (*this).~TNodoABB();
        Copia(other);
    }
    return *this;
}


void TABBCalendario::Copia(const TABBCalendario &origen) {
    if (origen.raiz != NULL){
        TNodoABB *aux = new TNodoABB( );
        aux->item = origen.raiz->item;
        raiz = aux;
        raiz-> de.Copia(origen.raiz->de);
        raiz->iz.Copia(origen.raiz->de);
    }
    else raiz = NULL;
}

TABBCalendario::TABBCalendario(){
    raiz = NULL;
}

TABBCalendario::TABBCalendario(const TABBCalendario &other){
    Copia(other);
}

TABBCalendario::~TABBCalendario(){
    TNodoABB *aux= new TNodoABB();

    while (!EsVacio()){
        aux = raiz;
        raiz-> de.~TABBCalendario();
        raiz->iz.~TABBCalendario();
        delete raiz;
        raiz = NULL;
    }
}

TABBCalendario &TABBCalendario::operator= (const TABBCalendario & abb){
    if(this != &abb){
        this -> ~TABBCalendario( );
        Copia(abb);
    }
    return *this;
}

bool TABBCalendario::operator== (const TABBCalendario &abb) const {
    TVectorCalendario a = abb.Inorden();
    TVectorCalendario b = Inorden();
    return b == a;
}

bool TABBCalendario::EsVacio() const {
    return this->raiz==NULL;

}

TVectorCalendario TABBCalendario::Inorden() const {


}








