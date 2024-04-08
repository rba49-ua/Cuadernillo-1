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

bool TListaPos::operator==(const TListaPos &lp) const{
    if (this-> pos == lp.pos){
        return true;
    }

    return false;

}

bool TListaPos::operator!=(const TListaPos &lp) const{
    return !(*this == lp);
}

TListaPos TListaPos::Siguiente(){
    TListaPos lp;

    if(this->pos->siguiente != NULL){
        lp.pos = this->pos->siguiente;
    }
    return lp;

}

bool TListaPos::EsVacia() const{
    if(pos == NULL){
        return true;
    }
    return false;

}


TListaCalendario::TListaCalendario() {
    primero = NULL;

}

TListaCalendario::TListaCalendario(const TListaCalendario &lc) {
    this->primero = NULL;
    for (TListaPos i = lc.Primera(); !i.EsVacia(); i = i.Siguiente()){
        Insertar(i.pos-> c);
    }

}

TListaCalendario::~TListaCalendario() {
    TListaPos p, q;
    q = Primera();
    while (!q.EsVacia()){
        p = q;
        q = q.Siguiente();
        delete p.pos;
    }

    primero = NULL;
}

TListaCalendario &TListaCalendario::operator=(const TListaCalendario &lc) {
    if(this != &lc){
        this -> ~TListaCalendario();

        for (TListaPos i = lc.Primera(); !i.EsVacia(); i = i.Siguiente()){
            Insertar(i.pos-> c);
        }
    }
    return (*this);

}

bool TListaCalendario::operator==(const TListaCalendario &lc) const{
    TListaPos lista1 = this->Primera();
    TListaPos lista2 = lc.Primera();

    if (this->Longitud() != lc.Longitud()){
        return false;
    }

    while (!lista1.EsVacia() && !lista2.EsVacia()){
        if (lista1.pos -> c != lista2.pos -> c){
            return false;
        }

        lista1 = lista1.Siguiente();
        lista2 = lista2.Siguiente();
    }
    return true;

}

TListaCalendario TListaCalendario::operator+ (const TListaCalendario &lc){
    TListaCalendario total(*this);
    for (TListaPos i = lc.Primera(); !i.EsVacia(); i = i.Siguiente()){
        total.Insertar(i.pos-> c);
    }

    return total;
}

TListaCalendario TListaCalendario::operator- (const TListaCalendario &lc){
    TListaCalendario total(*this);
    for (TListaPos i = lc.Primera(); !i.EsVacia(); i = i.Siguiente()){
        if(total.Buscar(i.pos->c)){
            total.Borrar(i.pos->c);
        }
    }

    return total;
}

bool TListaCalendario::Insertar(const TCalendario &cal){
    TListaCalendario total(*this);
    TNodoCalendario *nuevoNodo = new TNodoCalendario();
    nuevoNodo->c = cal;

    TNodoCalendario *nodoSiguiente = primero;
    TNodoCalendario *nodoAnterior = NULL;

    for (TListaPos i = total.Primera(); !i.EsVacia(); i = i.Siguiente()){
        if(i.pos->c == cal){
            return false;
        }
    }


    if (this-> EsVacia() || nuevoNodo->c < primero->c){
        nuevoNodo->siguiente = primero;
        primero = nuevoNodo;
        return true;
    }


    while (nodoSiguiente != NULL && nodoSiguiente->c < nuevoNodo->c){
        nodoAnterior = nodoSiguiente;
        nodoSiguiente = nodoSiguiente->siguiente;
    }

    nuevoNodo->siguiente = nodoSiguiente;
    nodoAnterior->siguiente = nuevoNodo;
    return true;

}



bool TListaCalendario::Borrar(const TCalendario &cal){

    for (TListaPos i = Primera(); !i.EsVacia(); i = i.Siguiente()){
        if(i.pos->c == cal){
            Borrar(i);
            return true;
        }
    }
    return false;

}

bool TListaCalendario::Borrar (const TListaPos &lp){
    TListaPos posicionActual = Primera();
    TListaPos posicionAnterior = Primera();

    if(lp.EsVacia()){
        return false;
    }

    if(lp.pos == primero){
        primero = lp.pos->siguiente;
        delete lp.pos;
        return true;
    }

    while(!posicionActual.EsVacia()){
        if(posicionActual == lp){
            posicionAnterior.pos->siguiente = posicionActual.pos->siguiente;
            delete posicionActual.pos;
            return true;
        }
        posicionAnterior = posicionActual;
        posicionActual = posicionActual.Siguiente();
    }

    return false;

}

bool TListaCalendario::Borrar(int dia, int mes, int anyo) {
    TCalendario cal(dia, mes, anyo, NULL);
    TListaPos i = Primera();
    TListaPos siguiente;

    while (!i.EsVacia()) {
        siguiente = i.Siguiente();

        if (i.pos->c < cal) {
            Borrar(i);
            i = siguiente;
            continue;
        }

        i = siguiente;
    }

    return !EsVacia();
}





bool TListaCalendario::EsVacia() const{

    if (primero == NULL){
        return true;
    }
    return false;

}

TCalendario TListaCalendario::Obtener(const TListaPos &lp) const{
    if(lp.EsVacia()){
        return TCalendario();
    }
    return lp.pos->c;
}

bool TListaCalendario::Buscar (const TCalendario &c) const{
    TListaCalendario total(*this);
    for (TListaPos i = total.Primera(); !i.EsVacia(); i = i.Siguiente()){
        if (i.pos->c == c){
            return true;
        }
    }
    return false;

}

int TListaCalendario::Longitud() const{
    int longitud = 0;
    TListaPos pos = Primera();

    while(!pos.EsVacia()){
        longitud++;
        pos = pos.Siguiente();
    }
    return longitud;

}

TListaPos TListaCalendario::Primera() const{
    TListaPos pos;

    if(primero==NULL){
        return pos;
    }

    pos.pos = primero;
    return pos;


}

TListaPos TListaCalendario::Ultima() const{
    TListaPos pos = Primera();

    if(primero == NULL) {
        return pos;
    }

    while(!pos.EsVacia()){
        if (pos.Siguiente().EsVacia()){
            break;
        }
        pos = pos.Siguiente();
    }
    return pos;

}

TListaCalendario TListaCalendario::SumarSubl (int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2){
    TListaCalendario lista1_aux(*this);
    TListaCalendario lista2_aux(L2);

    TListaCalendario lista1 = lista1_aux.ExtraerRango(I_L1, F_L1);
    TListaCalendario lista2 = lista2_aux.ExtraerRango(I_L2, F_L2);

    TListaCalendario resultado = lista1 + lista2;
    return resultado;

}

TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2) {
    TListaCalendario resultado;
    TListaPos pos = Primera();
    TListaPos temp;
    int contador = 1;

    while (!pos.EsVacia() && contador <= n2) {
        if (contador < n1){
            pos = pos.Siguiente();
        }
        else{
            resultado.Insertar(pos.pos->c);
            temp = pos;
            pos = pos.Siguiente();
            Borrar(temp.pos->c);
        }

        contador++;
    }

    return resultado;
}


ostream & operator<< (ostream &s, const TListaCalendario &lc){
    s << "<";

    if (lc.EsVacia()){
        s << ">";
        return s;
    }

    for (TListaPos i = lc.Primera(); !i.EsVacia(); i = i.Siguiente()){
        s << lc.Obtener(i) ;
        if (!i.Siguiente().EsVacia()){
            s << " ";
        }

    }
    s << ">";

    return s;

}
