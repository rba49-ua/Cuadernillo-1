#ifndef CUADERNILLO_1_TCALENDARIO_H
#define CUADERNILLO_1_TCALENDARIO_H
#include <iostream>
#include <string.h>

class TCalendario{
    private:
        int dia, mes, anyo;
        char* mensaje;
    public:
        TCalendario();
        TCalendario(int dia, int mes, int anyo, char* mens);
        TCalendario(TCalendario &);
        ~TCalendario();
        TCalendario & operator=(TCalendario &);
        TCalendario operator+(int);
        TCalendario operator-(int);
        TCalendario operator++(int);
        TCalendario & operator++();
        TCalendario operator--(int);
        TCalendario & operator--();
        bool ModFecha (int, int, int);
        bool ModMensaje(char *);
        bool operator ==(TCalendario &);
        bool operator !=(TCalendario &);
        bool operator>(TCalendario &);
        bool operator<(TCalendario &);
        bool EsVacio();
        int Dia();
        int Mes();
        int Anyo();
        char *Mensaje();

    friend ostream & operator<<(ostream &, TCalendario &);









};

#endif //CUADERNILLO_1_TCALENDARIO_H
