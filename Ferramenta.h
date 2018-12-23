#ifndef FERRAMENTA_H
#define FERRAMENTA_H
#include "Recurso.h"

using namespace std;

class Ferramenta: public Recurso
{
    public:
        Ferramenta(string nome, double custoDiario);
        virtual ~Ferramenta();
        virtual double getCustoDiario();
        void imprimir();
        virtual double getCusto(int dias);
    protected:

    private:
        double custoDiario;
        int dias;
};

#endif // FERRAMENTA_H
