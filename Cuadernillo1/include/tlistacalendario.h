#ifndef PED_TLISTACALENDARIO_H
#define PED_TLISTACALENDARIO_H

#include "tcalendario.h"
#include "tvectorcalendario.h"

class TNodoCalendario{
    private:
        TCalendario c;
        TNodoCalendario *siguiente;
        void CopiaNodo (const TNodoCalendario &);
        friend class TListaPos;

    public:
        TNodoCalendario();

        TNodoCalendario(const TNodoCalendario &);

        ~TNodoCalendario();

        TNodoCalendario & operator= (const TNodoCalendario &);

};

class TListaPos{
    private:
        TNodoCalendario *pos;

    public:
        TListaPos();

        TListaPos(const TListaPos &);

        ~TListaPos();

        TListaPos & operator= (const TListaPos &);

        bool operator== (const TListaPos &);

        bool operator!= (const TListaPos &);

        TListaPos Siguiente();

        bool EsVacia();

};

class TListaCalendario{
    friend ostream & operator<< (ostream &, const TListaCalendario &);
    private:
        TNodoCalendario *primero;

    public:
        TListaCalendario();

        TListaCalendario(const TListaCalendario &);

        ~TListaCalendario();

        TListaCalendario & operator= (const TListaCalendario &);

        bool operator==(TListaCalendario &);

        TListaCalendario operator+ (const TListaCalendario &);

        TListaCalendario operator- (const TListaCalendario &);

        bool Insertar(const TCalendario &);

        bool Borrar(const TCalendario &);

        bool Borrar (const TListaPos &);

        bool Borrar (int, int, int);

        bool EsVacia();

        TCalendario Obtener(const TListaPos &);

        bool Buscar (TCalendario &);

        int Longitud();

        TListaPos Primera();

        TListaPos Ultima();

        TListaCalendario SumarSubl (int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2);

        TListaCalendario ExtraerRango (int n1, int n2);

};

#endif //PED_TLISTACALENDARIO_H
