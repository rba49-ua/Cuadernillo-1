//
// Created by Raúl on 08/04/2024.
//
#include <iostream>
using namespace std;

#ifndef CUADERNILLO2_TABBCALENDARIO_H
#define CUADERNILLO2_TABBCALENDARIO_H

#include "tcalendario.h"
#include "tvectorcalendario.h"

class TNodoABB;

class TABBCalendario{
    friend ostream & operator<<(ostream &, TABBCalendario &);
    private:
        void Copia(const TABBCalendario &);
        TNodoABB *raiz;
        void InordenAux(TVectorCalendario &, int &) const;
        void PreordenAux(TVectorCalendario &, int &) const;
        void PostordenAux(TVectorCalendario &, int &) const;

    public:
        TABBCalendario();
        TABBCalendario(const TABBCalendario &);
        ~TABBCalendario();
        TABBCalendario & operator=(const TABBCalendario &);
        bool operator==(const TABBCalendario &) const;

        bool EsVacio() const;
        bool Insertar(const TCalendario &);
        bool Borrar(const TCalendario &);
        bool Buscar(const TCalendario &) const;
        TCalendario Raiz() const;

        int Altura() const;
        int Nodos() const;
        int NodosHoja() const;

        TVectorCalendario Inorden() const;
        TVectorCalendario Preorden() const;
        TVectorCalendario Postorden() const;

        TVectorCalendario Niveles() const;

        TABBCalendario operator+(const TABBCalendario &);
        TABBCalendario operator-(const TABBCalendario &);
};

class TNodoABB{
    friend class TABBCalendario;
    private:
        void Copia(const TNodoABB &);
        TCalendario item;
        TABBCalendario iz, de;

    public:
        TNodoABB();
        TNodoABB(const TNodoABB &);
        ~TNodoABB();
        TNodoABB & operator=(const TNodoABB &);
};

#endif //CUADERNILLO2_TABBCALENDARIO_H
