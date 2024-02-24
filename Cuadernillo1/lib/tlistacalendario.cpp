#include "../include/tlistacalendario.h"

using namespace std;

void TNodoCalendario::CopiaNodo(const TNodoCalendario &n) {
    this->c = n.c;
    this->siguiente = n.siguiente;
}

// También se puede poner:
// TNodoCalendario::TNodoCalendario(): c(), siguiente(NULL){}
TNodoCalendario::TNodoCalendario(): c(){
    siguiente=NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &n) {
    CopiaNodo(n);
}

TNodoCalendario::~TNodoCalendario() {
    c.~TCalendario();
    siguiente=NULL;
}

TNodoCalendario &TNodoCalendario::operator=(const TNodoCalendario &n) {
    if(this == &n){
        return *this;
    }

    (*this).~TNodoCalendario();
    CopiaNodo(n);
    return *this;

}

TListaPos::TListaPos() {
    this->pos = NULL;
}

TListaPos::TListaPos(const TListaPos &lp) {
    this-> pos = lp.pos;
}

TListaPos::~TListaPos() {
    this->pos = NULL;

}

TListaPos &TListaPos::operator=(const TListaPos &lp) {
    if(this != &lp){
        (*this).~TListaPos();
        this->pos = lp.pos;
    }

    return *this;

}

bool TListaPos::operator==(const TListaPos &lp) {
    if (this-> pos == lp.pos){
        return true;
    }

    return false;

}

bool TListaPos::operator!=(const TListaPos &lp) {
    return !(*this == lp);
}

TListaPos TListaPos::Siguiente(){
    TListaPos lp;

    if(this->pos->siguiente != NULL){
        lp.pos = this->pos->siguiente;
    }
    return lp;

}

bool TListaPos::EsVacia() {
    if(pos == NULL){
        return true;
    }
    return false;

}


