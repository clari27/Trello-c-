#ifndef ATIVIDADEDEPRAZOFIXO_H
#define ATIVIDADEDEPRAZOFIXO_H
#include "Atividade.h"

using namespace std;


class AtividadeDePrazoFixo : public Atividade
{
    public:
        AtividadeDePrazoFixo(string nome,int dias);
        virtual ~AtividadeDePrazoFixo();
        virtual int getPrazo();
        virtual int getDuracao();
        virtual void imprimir();


    protected:

    private:
        int dias;
};

#endif // ATIVIDADEDEPRAZOFIXO_H
