#include "../include/tlistacalendario.h"

using namespace std;

void TNodoCalendario::Copia(const TNodoCalendario &n) {
    this->c = n.c;
    this.siguiente = n.siguiente;
}

// También se puede poner:
// TNodoCalendario::TNodoCalendario(): c(), siguiente(NULL){}
TNodoCalendario::TNodoCalendario() {
    c.TCalendario();
    siguiente=NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &n) {
    Copia(n);
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
    Copia(n);
    return *this;

}


