

#ifndef CUADERNILLO_1_TCALENDARIO_H
#define CUADERNILLO_1_TCALENDARIO_H
#include <iostream>
#include <string.h>

class TCalendario {
private:
    int dia, mes, anyo;
    char *mensaje;
    bool comprobarFecha (int, int, int); //hecha
    bool bisiesto(int); //hecha
    void defaultParameters();
    void copia(const TCalendario &); //hecha
public:
    TCalendario(); //hecha

    TCalendario(int dia, int mes, int anyo, char *mens);

    TCalendario(TCalendario &);

    ~TCalendario();

    TCalendario &operator=(const TCalendario &);

    TCalendario operator+(int); //hecho

    TCalendario operator-(int); //hecho

    TCalendario operator++(int);

    TCalendario &operator++();

    TCalendario operator--(int);

    TCalendario &operator--();

    bool ModFecha(int, int, int);

    bool ModMensaje(char *);

    bool operator==(const TCalendario &);

    bool operator!=(const TCalendario &);

    bool operator>(const TCalendario &);

    bool operator<(const TCalendario &);

    bool EsVacio(); //hecho

    int Dia(); //hecho

    int Mes(); //hecho

    int Anyo(); //hecho

    char *Mensaje(); //hecho

    friend std::ostream &operator<<(std::ostream &, const TCalendario &);
};


#endif //CUADERNILLO1_TCALENDARIO_H
