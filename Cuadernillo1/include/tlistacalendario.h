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
        friend class TListaCalendario;

    public:
        TNodoCalendario();

        TNodoCalendario(const TNodoCalendario &);

        ~TNodoCalendario();

        TNodoCalendario & operator= (const TNodoCalendario &);

};

class TListaPos{
    private:
        TNodoCalendario *pos;
        friend class TListaCalendario;

    public:
        TListaPos();

        TListaPos(const TListaPos &);

        ~TListaPos();

        TListaPos & operator= (const TListaPos &);

        bool operator== (const TListaPos &) const;

        bool operator!= (const TListaPos &) const;

        TListaPos Siguiente();

        bool EsVacia() const;

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

        bool operator==(const TListaCalendario &) const;

        TListaCalendario operator+ (const TListaCalendario &);

        TListaCalendario operator- (const TListaCalendario &);

        bool Insertar(const TCalendario &);

        bool Borrar(const TCalendario &);

        bool Borrar (const TListaPos &);

        bool Borrar (int, int, int);

        bool EsVacia() const;

        TCalendario Obtener(const TListaPos &);

        bool Buscar (const TCalendario &) const;

        int Longitud() const;

        TListaPos Primera() const;

        TListaPos Ultima() const;

        TListaCalendario SumarSubl (int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2);

        TListaCalendario ExtraerRango (int n1, int n2);

};

#endif //PED_TLISTACALENDARIO_H
