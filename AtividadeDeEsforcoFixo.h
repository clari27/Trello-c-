#ifndef ATIVIDADEDEESFORCOFIXO_H
#define ATIVIDADEDEESFORCOFIXO_H
#include "Atividade.h"

using namespace std;


class AtividadeDeEsforcoFixo : public Atividade
{
    public:
        AtividadeDeEsforcoFixo(string nome, int horasNecessarias);
        virtual ~AtividadeDeEsforcoFixo();

        virtual int getHorasNecessarias();
        virtual int getDuracao();
        virtual void imprimir();

    protected:

    private:
        string nome;
        int horasNecessarias;
};

#endif // ATIVIDADEDEESFORCOFIXO_H
