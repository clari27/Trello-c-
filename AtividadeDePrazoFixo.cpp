#include "AtividadeDePrazoFixo.h"
#include "Atividade.h"

using namespace std;


AtividadeDePrazoFixo::AtividadeDePrazoFixo(string nome, int dias):Atividade(nome)
{
    this->dias =dias;
    if(dias<=0){
        throw new invalid_argument("o numero de dias nao pode ser menor ou igual a 0");
    }
}

AtividadeDePrazoFixo::~AtividadeDePrazoFixo()
{
    //dtor
}

int AtividadeDePrazoFixo::getPrazo(){

    return dias;

}

int AtividadeDePrazoFixo::getDuracao(){

    if(estaTerminada()==true){
        return dias;
    }

return dias;
}

void AtividadeDePrazoFixo::imprimir(){

    cout << " " << Atividade::getNome() << " - " << AtividadeDePrazoFixo::getDuracao() << " dias - R$ " << Atividade::getCusto() <<  endl;

}