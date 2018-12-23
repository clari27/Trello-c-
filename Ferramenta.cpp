#include "Ferramenta.h"
#include "stdexcept"
#include "Recurso.h"
#include <iostream>

using namespace std;
Ferramenta::Ferramenta(string nome, double custoDiario): Recurso(nome)
{
    this->custoDiario=custoDiario;
    {
        if(custoDiario<0){
            throw new invalid_argument("custo diario nao pode ser negativo");
            }
    //ctor
    }
}


Ferramenta::~Ferramenta()
{
    //dtor
}

double Ferramenta::getCustoDiario()
{

    return custoDiario;
}

double Ferramenta::getCusto(int dias){

    return dias*Ferramenta::getCustoDiario();


}

void Ferramenta::imprimir()
{
    cout << " " << Recurso::getNome()  << " - R$" << this -> custoDiario <<  " por dia" << endl;
}