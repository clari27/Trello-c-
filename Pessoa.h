// T5T - G8
// Clarissa Manfrinato e Enzo Sampronha
#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include "Recurso.h"

using namespace std;

class Pessoa : public Recurso {

    public:

        Pessoa(string nome, double valorPorHora, int horasDiarias);
        Pessoa(string nome, int horasDiarias);
        virtual ~Pessoa();

        virtual double getValorPorHora(); // valor por hora da pessoa
        virtual int getHorasDiarias();  // horas diarias
        virtual bool recebeValorPadrao();

        static void setValorPorHoraPadrao(double valor);
        static double getValorPorHoraPadrao();

        double getCusto(int dias); // custo
        void imprimir();

    private:

        static double valorPorHoraPadrao;
        double valorPorHora;
        int horasDiarias;


};

#endif // PESSOA_H