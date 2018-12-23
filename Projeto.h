#ifndef PROJETO_H
#define PROJETO_H
#include "Atividade.h"
#include "Recurso.h"
#include <vector>
#include <list>

using namespace std;

class Projeto
{
    public:
        Projeto(string nome);
        virtual ~Projeto();
        virtual string getNome();

        virtual void adicionar(Atividade* a);
        virtual vector<Atividade*>* getAtividades();
        virtual void adicionar(Recurso* r);
        virtual list<Recurso*>* getRecursos();

        virtual int getDuracao();
        virtual int getDuracao(bool terminadas);
        virtual double getCusto();
        virtual void imprimir();

    protected:

    private:
    string nome;
    bool terminadas;
    vector<Atividade*> *atividades;
    list<Recurso*> *recursos;

};

#endif // PROJETO_H