#include "AtividadeDeEsforcoFixo.h"
#include "Atividade.h"
#include "Recurso.h"
#include "Pessoa.h"

using namespace std;


AtividadeDeEsforcoFixo::AtividadeDeEsforcoFixo(string nome, int horasNecessarias): Atividade(nome)
{
    this->horasNecessarias=horasNecessarias;
    if(horasNecessarias<=0){
        throw new invalid_argument("o numero de horas nao pode ser menor ou igual a 0");
    }
    //ctor
}

AtividadeDeEsforcoFixo::~AtividadeDeEsforcoFixo()
{
    //dtor
}

int AtividadeDeEsforcoFixo::getHorasNecessarias(){

    return horasNecessarias;
}

int AtividadeDeEsforcoFixo::getDuracao(){
    int i=0;
    int soma=0;

    if(estaTerminada()==true){
        return duracaoReal;
    }

    for(i=0;i< Atividade::getQuantidadeDeRecursos(); i++){

        Pessoa *p = dynamic_cast<Pessoa*>(recursos[i]);

        if(p!=NULL){

            soma += p->getHorasDiarias();
        }


    }
        if(soma==0){
            throw new logic_error("nao existem pessoas adicionadas a atividade");
        }

        return horasNecessarias/soma;

}

void AtividadeDeEsforcoFixo::imprimir(){

    cout << " " << Atividade::getNome() << " - " << AtividadeDeEsforcoFixo::getDuracao() << " dias - R$ " << Atividade::getCusto() <<  endl;

}