#ifndef PERSISTENCIADEPROJETO_H
#define PERSISTENCIADEPROJETO_H

#include "Projeto.h"
#include "Ferramenta.h"
#include "Pessoa.h"
#include "AtividadeDePrazoFixo.h"
#include "AtividadeDeEsforcoFixo.h"
#include "ErroDeArquivo.h"
#include <fstream>


using namespace std;

class PersistenciaDeProjeto {
public:
    PersistenciaDeProjeto();
    virtual ~PersistenciaDeProjeto(); 
    Projeto* carregar(string arquivo); 
    void salvar(Projeto* p, string arquivo);
};

#endif