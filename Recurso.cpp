#include "Recurso.h"
#include <iostream>

using namespace std;

Recurso::Recurso(string nome)
{
    this->nome=nome;
    //ctor
}


Recurso::~Recurso()
{
    //dtor
}

string Recurso::getNome()
{
    return nome;
}
