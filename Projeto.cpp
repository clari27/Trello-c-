#include "Projeto.h"
#include "Atividade.h"
#include "Recurso.h"
#include <vector>
#include <list>
#include "stdexcept"

using namespace std;

Projeto::Projeto(string nome)
{
    this->nome=nome;
    atividades = new vector<Atividade*>();
    recursos = new list<Recurso*>();
    //ctor
}


Projeto::~Projeto()
{
    //dtor
}

string Projeto::getNome(){

    return nome;
}

void Projeto::adicionar(Atividade* a){

    atividades->push_back(a);

}

vector<Atividade*>* Projeto::getAtividades(){

    return atividades;

}

void Projeto::adicionar(Recurso* r){


    list<Recurso*>::iterator i = recursos->begin();

    while(i!= recursos->end()){
        if(r ==(*i)){

            throw new invalid_argument("recurso ja adicionado ");
        }
        i++;
    }
        recursos->push_back(r);


}

list<Recurso*>* Projeto::getRecursos(){

    return recursos;

}

int Projeto::getDuracao(){

    double soma=0;

    vector<Atividade*>::iterator i = atividades->begin();

    while(i!= atividades->end()){

        soma += (*i)->getDuracao();
        i++;
    }

    return soma;
}

int Projeto::getDuracao(bool terminadas){
 bool soma=0;

    vector<Atividade*>::iterator i = atividades->begin();

    while(i!= atividades->end()){

        if((*i)->estaTerminada()==true){

            soma += (*i)->getDuracao();
        }
        i++;
    }

    return soma;
}

double Projeto::getCusto(){

double soma=0;

    vector<Atividade*>::iterator i = atividades->begin();

    while(i!= atividades->end()){

        soma +=(*i)->getCusto();
        i++;
    }
}

void Projeto::imprimir(){



}