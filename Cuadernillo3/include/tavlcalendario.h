//
// Created by Raúl on 08/05/2024.
//
#include <iostream>
using namespace std;

#ifndef CUADERNILLO2_TAVLCALENDARIO_H
#define CUADERNILLO2_TAVLCALENDARIO_H

#include "tcalendario.h"
#include "tvectorcalendario.h"

class TNodoAVL;

class TAVLCalendario{
    friend class TNodoAVL;
    friend ostream & operator<<(ostream &, TAVLCalendario &);
    private:
        void Copia(const TAVLCalendario &);
        TNodoAVL *raiz;
        void InordenAux(TVectorCalendario &, int &) const;
        void PreordenAux(TVectorCalendario &, int &) const;
        void PostordenAux(TVectorCalendario &, int &) const;

    public:
        TAVLCalendario();
        TAVLCalendario(const TAVLCalendario &);
        ~TAVLCalendario();
        TAVLCalendario & operator=(const TAVLCalendario &);
        bool operator==(const TAVLCalendario &) const;

        bool operator!=(const TAVLCalendario &) const;
        bool EsVacio() const;
        bool Insertar(const TCalendario &);
        bool Buscar(const TCalendario &) const;

        int Altura() const;
        int Nodos() const;
        int NodosHoja() const;

        TVectorCalendario Inorden() const;
        TVectorCalendario Preorden() const;
        TVectorCalendario Postorden() const;

        bool Borrar(const TCalendario &);
        TCalendario Raiz() const;

};

class TNodoAVL{
    friend class TAVLCalendario;
    private:
        void Copia(const TNodoAVL &);
        TCalendario item;
        TAVLCalendario iz, de;
        int fe;

    public:
        TNodoAVL();
        TNodoAVL(const TNodoAVL &);
        ~TNodoAVL();
        TNodoAVL & operator=(const TNodoAVL &);
};

#endif //CUADERNILLO2_TAVLCALENDARIO_H
