#ifndef RECURSO_H
#define RECURSO_H
#include <iostream>

using namespace std;

class Recurso
{
    public:
        Recurso(string nome);
        virtual ~Recurso();
        virtual string getNome();
        virtual double getCusto(int dias)=0;
        virtual void imprimir()=0;
    protected:

    private:
        string nome;

        };

#endif // RECURSO_H
