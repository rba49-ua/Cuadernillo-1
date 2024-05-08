#include "../include/tavlcalendario.h"

void TNodoAVL::Copia(const TNodoAVL &other){
    item = other.item;
    iz = other.iz;
    de = other.de;
    fe = other.fe;
}

TNodoAVL::TNodoAVL():item(), iz(),de(), fe(){}

TNodoAVL::TNodoAVL(const TNodoAVL &other) {
    Copia(other);
}

TNodoAVL::~TNodoAVL() {}

TNodoAVL &TNodoAVL::operator=(const TNodoAVL &other){
    if(this != &other){
        (*this).~TNodoAVL();
        Copia(other);
    }
    return *this;
}

void TAVLCalendario::Copia(const TAVLCalendario &origen) {
    if (origen.raiz != NULL){
        TNodoAVL *aux = new TNodoAVL( );
        aux->item = origen.raiz->item;
        raiz = aux;
        raiz-> de.Copia(origen.raiz->de);
        raiz->iz.Copia(origen.raiz->iz);
    }
    else raiz = NULL;
}

TAVLCalendario::TAVLCalendario(){
    raiz = NULL;
}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &other){
    Copia(other);
}

TAVLCalendario::~TAVLCalendario(){
    if(raiz != NULL){
        delete raiz;
        raiz = NULL;
    }
}

TAVLCalendario &TAVLCalendario::operator= (const TAVLCalendario & avl){
    if(this != &avl){
        this -> ~TAVLCalendario( );
        Copia(avl);
    }
    return *this;
}

bool TAVLCalendario::operator== (const TAVLCalendario &avl) const {
    return Inorden() == avl.Inorden();
}

bool TAVLCalendario::operator!= (const TAVLCalendario &avl) const {
    return !(*this == avl);
}

bool TAVLCalendario::EsVacio() const {
    return this->raiz==NULL;
}

TCalendario TAVLCalendario::Raiz() const {
    if (!EsVacio()){
        return raiz->item;
    }
    return TCalendario();
}

int TAVLCalendario::Altura() const {
    if (EsVacio()){
        return 0;
    }
    return 1 + max(raiz->iz.Altura(), raiz->de.Altura());
}

int TAVLCalendario::Nodos() const {
    if (EsVacio()){
        return 0;
    }
    return 1 + raiz->iz.Nodos() + raiz->de.Nodos();
}

int TAVLCalendario::NodosHoja() const {
    if (EsVacio()){
        return 0;
    }
    if (raiz->iz.EsVacio() && raiz->de.EsVacio()){
        return 1;
    }
    return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
}

bool TAVLCalendario::Insertar(const TCalendario &c) {
    if (EsVacio()){
        raiz = new TNodoAVL();
        raiz->item = c;
        return true;
    }

    if (this->Buscar(c)){
        return false;
    }

    if (raiz->item < c){
        return raiz->de.Insertar(c);
    }
    else{
        return raiz->iz.Insertar(c);
    }
}

bool TAVLCalendario::Borrar(const TCalendario &c) {
    if(EsVacio()){
        return false;
    }

    if (raiz->item < c){
        return raiz->de.Borrar(c);
    }

    if (raiz->item > c){
        return raiz->iz.Borrar(c);
    }

    if(raiz->item == c && raiz->de.EsVacio()){
        this->raiz = this->raiz->iz.raiz;
        return true;
    }

    if(raiz->item == c && raiz->iz.EsVacio()){
        this->raiz = this->raiz->de.raiz;
        return true;

    }

    if(raiz->item == c && !raiz->de.EsVacio() && !raiz->iz.EsVacio()){
        TCalendario maxItem = raiz->iz.Maximo();
        raiz->item = maxItem;
        raiz->iz.Borrar(maxItem);
        return true;
    }
    return false;
}

bool TAVLCalendario::Buscar(const TCalendario &c) const {
    if (EsVacio()){
        return false;
    }

    if (raiz->item < c){
        return raiz->de.Buscar(c);
    }

    if (raiz->item > c){
        return raiz->iz.Buscar(c);
    }

    return true;
}

void TAVLCalendario::InordenAux(TVectorCalendario &v, int &pos) const {
    if (!EsVacio()){
        raiz->iz.InordenAux(v,pos);
        v[pos++] = this->Raiz();
        raiz->de.InordenAux(v,pos);
    }
}

TVectorCalendario TAVLCalendario::Inorden() const {
    TVectorCalendario v (this->Nodos());
    int pos = 1;
    InordenAux(v, pos);
    return v;
}

void TAVLCalendario::PreordenAux(TVectorCalendario &v, int &pos) const {
    if (!EsVacio()){
        v[pos++] = this->Raiz();
        raiz->iz.PreordenAux(v,pos);
        raiz->de.PreordenAux(v,pos);
    }
}

TVectorCalendario TAVLCalendario::Preorden() const {
    TVectorCalendario v (this->Nodos());
    int pos = 1;
    PreordenAux(v, pos);
    return v;
}

void TAVLCalendario::PostordenAux(TVectorCalendario &v, int &pos) const {
    if (!EsVacio()){
        raiz->iz.PostordenAux(v,pos);
        raiz->de.PostordenAux(v,pos);
        v[pos++] = this->Raiz();
    }
}

TVectorCalendario TAVLCalendario::Postorden() const {
    TVectorCalendario v (this->Nodos());
    int pos = 1;
    PostordenAux(v, pos);
    return v;
}

ostream & operator<<(ostream & os, TAVLCalendario &elements){
    os << elements.Inorden();
    return os;
}









