

#ifndef CUADERNILLO_1_TCALENDARIO_H
#define CUADERNILLO_1_TCALENDARIO_H
#include <iostream>
#include <string.h>
using namespace std;

class TCalendario {
private:
    int dia, mes, anyo;
    char *mensaje;
    bool comprobarFecha (int, int, int); //hecha
    bool bisiesto(int); //hecha
    int diasEnMes(int, int);
    TCalendario ajustarFecha(TCalendario &c);
    void defaultParameters();
    void copia(const TCalendario &); //hecha
public:
    TCalendario(); //hecha

    TCalendario(int dia, int mes, int anyo, char *mens); //hecho

    TCalendario(TCalendario &); //hecho

    ~TCalendario();

    TCalendario &operator=(const TCalendario &); //puede

    TCalendario operator+(int); //hecho

    TCalendario operator-(int); //hecho

    TCalendario operator++(int); //puede

    TCalendario &operator++(); //puede

    TCalendario operator--(int); //puede

    TCalendario &operator--(); //puede

    bool ModFecha(int, int, int); //hecha

    bool ModMensaje(char *); //hecha

    bool operator==(const TCalendario &); //hecho

    bool operator!=(const TCalendario &); //hecho

    bool operator>(const TCalendario &); //hecho

    bool operator<(const TCalendario &); //hecho

    bool EsVacio(); //hecho

    int Dia(); //hecho

    int Mes(); //hecho

    int Anyo(); //hecho

    char *Mensaje(); //hecho

    friend ostream &operator<<(ostream &, const TCalendario &);
};


#endif //CUADERNILLO1_TCALENDARIO_H
