#include "Atividade.h"
#include "Recurso.h"
#include "Ferramenta.h"
#include "Pessoa.h"
#include <stdexcept>

using namespace std;

Atividade::Atividade(string nome)
{
    this->nome =nome;
    quantidadeDeRecursos=0; //quantidade de recursos adicionados
    recursos = new Recurso*[MAX_RECURSOS];
    //ctor
}

Atividade::~Atividade()
{
    //dtor
}

string Atividade::getNome(){

    return nome;
}

int Atividade::getQuantidadeDeRecursos(){

    return quantidadeDeRecursos;
}

void Atividade::adicionar(Recurso* r){
    int i;
    if(getQuantidadeDeRecursos()== MAX_RECURSOS){
        throw new overflow_error("Quantidade de recursos adicionados chegou ao limite");
    }
    for(int i=0; i< getQuantidadeDeRecursos();i++){ //verifica repeticao
        if(r == recursos[i]){
            throw new invalid_argument("recurso ja adicionado previamente");
        }
    }
    //atualiza atributos
    recursos[quantidadeDeRecursos] = r;
    quantidadeDeRecursos ++;
}

Recurso** Atividade::getRecursos(){

    return recursos;
}

double Atividade::getCusto(){
    double custoPessoa=0;
    double custoFerramenta=0;


    for(int i=0;i< Atividade::getQuantidadeDeRecursos(); i++){

        Pessoa *p = dynamic_cast<Pessoa*>(recursos[i]);

        if(p!=NULL){

            custoPessoa += p->getCusto( this->getDuracao() );
        }

        Ferramenta *f = dynamic_cast<Ferramenta*>(recursos[i]);

        if(f!=NULL){

            custoFerramenta += f->getCusto( this->getDuracao() );

        }

    }

        if((custoFerramenta+custoPessoa)==0){
            throw new logic_error("nao existem recursos adicionados a atividade");
            return 0;
        }


}

void Atividade::terminar(int duracaoReal){

    if (duracaoReal<=0){
        throw new invalid_argument("a duracao real nao pode ser menor ou igual a 0");
    }


}

bool Atividade::estaTerminada(){

    if(duracaoReal!=0){
        return false;
    }
    return true;

}
