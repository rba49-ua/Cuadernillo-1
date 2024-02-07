//
// Created by Raúl on 07/02/2024.
//

#define CUADERNILLO1_TCALENDARIO_H

#ifndef CUADERNILLO_1_TCALENDARIO_H
#define CUADERNILLO_1_TCALENDARIO_H
#include <iostream>
#include <string.h>

class TCalendario {
private:
    int dia, mes, anyo;
    char *mensaje;
    bool comprobarFecha (int, int, int);
public:
    TCalendario();

    TCalendario(int dia, int mes, int anyo, char *mens);

    TCalendario(TCalendario &);

    ~TCalendario();

    TCalendario &operator=(TCalendario &);

    TCalendario operator+(int);

    TCalendario operator-(int);

    TCalendario operator++(int);

    TCalendario &operator++();

    TCalendario operator--(int);

    TCalendario &operator--();

    bool ModFecha(int, int, int);

    bool ModMensaje(char *);

    bool operator==(TCalendario &);

    bool operator!=(TCalendario &);

    bool operator>(TCalendario &);

    bool operator<(TCalendario &);

    bool EsVacio();

    int Dia();

    int Mes();

    int Anyo();

    char *Mensaje();

    friend std::ostream &operator<<(std::ostream &, TCalendario &);
};


#endif //CUADERNILLO1_TCALENDARIO_H
