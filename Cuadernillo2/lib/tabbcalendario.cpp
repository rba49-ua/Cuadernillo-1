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
        raiz->iz.Copia(origen.raiz->iz);
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
    if(raiz != NULL){
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
    return Inorden() == abb.Inorden();
}

bool TABBCalendario::EsVacio() const {
    return this->raiz==NULL;

}

TCalendario TABBCalendario::Raiz() const {
    if (!EsVacio()){
        return raiz->item;
    }
    return TCalendario();
}

int TABBCalendario::Altura() const {
    if (EsVacio()){
        return 0;
    }
    return 1 + max(raiz->iz.Altura(), raiz->de.Altura());
}

int TABBCalendario::Nodos() const {
    if (EsVacio()){
        return 0;
    }
    return 1 + raiz->iz.Nodos() + raiz->de.Nodos();
}

int TABBCalendario::NodosHoja() const {
    if (EsVacio()){
        return 0;
    }
    if (raiz->iz.EsVacio() && raiz->de.EsVacio()){
        return 1;
    }
    return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
}

void TABBCalendario::InordenAux(TVectorCalendario &v, int &pos) const {
    if (!EsVacio()){
        raiz->iz.InordenAux(v,pos);
        v[pos++] = this->Raiz();
        raiz->de.InordenAux(v,pos);
    }
}

TVectorCalendario TABBCalendario::Inorden() const {
    TVectorCalendario v (this->Nodos());
    int pos = 1;
    InordenAux(v, pos);
    return v;
}

void TABBCalendario::PreordenAux(TVectorCalendario &v, int &pos) const {
    if (!EsVacio()){
        v[pos++] = this->Raiz();
        raiz->iz.PreordenAux(v,pos);
        raiz->de.PreordenAux(v,pos);
    }
}

TVectorCalendario TABBCalendario::Preorden() const {
    TVectorCalendario v (this->Nodos());
    int pos = 1;
    PreordenAux(v, pos);
    return v;
}

void TABBCalendario::PostordenAux(TVectorCalendario &v, int &pos) const {
    if (!EsVacio()){
        raiz->iz.PostordenAux(v,pos);
        raiz->de.PostordenAux(v,pos);
        v[pos++] = this->Raiz();
    }
}

TVectorCalendario TABBCalendario::Postorden() const {
    TVectorCalendario v (this->Nodos());
    int pos = 1;
    PostordenAux(v, pos);
    return v;
}








