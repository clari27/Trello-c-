#include <iostream>
#include "PersistenciaDeProjeto.h"
#include "Ferramenta.h"
#include "Pessoa.h"
#include "AtividadeDePrazoFixo.h"
#include "AtividadeDeEsforcoFixo.h"
using namespace std;


int main () {
    
    int i, resp, hd, tn, dr;
    resp = 7;
    double custo, vph;
    char c;
    string nome;
    bool term;
    cout << "Deseja carregar um novo projeto (s/n)?" << endl;
    cin >> c;
    if (c == 'n') {
        cout << "Digite o nome do projeto:" << endl;
        cin >> nome;
        Projeto *pro = new Projeto(nome);
    }
    else {
        cout << "Digite o nome do arquivo:" << endl;
        cin >> nome;
        PersistenciaDeProjeto *per = new PersistenciaDeProjeto(); 
        Projeto *pro = per -> carregar(nome);
        delete per;
    }
    Projeto *pro;
    while (resp != 0) {
        cout << "1 - Adicionar Recurso" << endl;
        cout << "2 - Adicionar Atividade" << endl;
        cout << "3 - Terminar Atividade" << endl;
        cout << "4 - Imprimir Projeto" << endl;
        cout << "5 - Definir valor por hora padrao" << endl;
        cout << "6 - Salvar" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao:" << endl;
        cin >> resp;
        
        if (resp == 1) {
            cout << "Ferramenta (f) ou Pessoa (p):" << endl;
            cin >> c;
            if (c == 'f') {
                cout << "Nome:" << endl;
                cin >> nome;
                cout << "Custo diario:" << endl;
                cin >> custo;
                Ferramenta *f = new Ferramenta(nome, custo);
                pro -> adicionar(f);
            }
            if (c == 'p') {
                cout << "Nome:" << endl;
                cin >> nome;
                cout << "Horas diarias:" << endl;
                cin >> hd;
                cout << "Valor por hora padrão (s/n)?" << endl;
                cin >> c;
                if (c == 'n') {
                    cout << "Valor por hora (em reais):" << endl;
                    cin >> vph;
                    Pessoa *pes = new Pessoa(nome, vph, hd);
                    pro -> adicionar(pes);
                }
                if (c == 's'){
                    Pessoa *pes = new Pessoa(nome, hd);
                    pro -> adicionar(pes);
                }
            }
            
        resp = 7;
        
        }
        
        if(resp == 2) {
            cout << "Nome:" << endl;
            cin >> nome;
            cout << "Prazo fixo (p) ou trabalho fixo (t)?" << endl;
            cin >> c;
            if (c == 'p') {
                cout << "Dias necessarios:" << endl;
                cin >> tn;
                AtividadeDePrazoFixo *a = new AtividadeDePrazoFixo(nome, tn);
                pro -> adicionar(a);
            }
            if (c == 't') {
                cout << "Horas Necessarias:" << endl;
                cin >> tn;
                AtividadeDeEsforcoFixo *a = new AtividadeDeEsforcoFixo(nome, tn);
                pro -> adicionar(a);
            }
            Atividade *a;
            list<Recurso*>::iterator j;
            while (c != 'n') {
                cout << "Deseja adicionar um recurso (s/n)?" << endl;
                cin >> c;
                if (c == 's') {
                    i = 1;
                    j = pro -> getRecursos() -> begin();
                    while(j != pro -> getRecursos() -> end()) {
                        cout << i << " - ";
                        (*j) -> imprimir();
                        cout << endl;
                        i++;
                        j++;
                    }
                    j = pro -> getRecursos() -> begin();
                    cout << "Escolha um Recurso ou 0 para cancelar:" << endl;
                    cin >> resp;
                    if(resp != 0) {
                        for(i = 0; i < (resp - 1); i++) {
                            j++;
                        }
                        try {
                            a -> adicionar((*j));
                        } catch (overflow_error *e) {
                            cout << "Erro: " << e -> what() << endl;
                            delete e;
                        } catch (invalid_argument *e) {
                            cout << "Erro: " << e -> what() << endl;
                            delete e;
                        }
                    }
                }
                if (c == 'n') {
                    resp = 7;
                }
            }
        }
        
        if (resp == 3) {
            i = 1;
            vector<Atividade*>::iterator k = pro -> getAtividades() -> begin();
            while (k != pro -> getAtividades() -> end()) {
                cout << i << " - " << (*k) -> getNome() << endl;
                i++;
                k++;
            }
            cout << "Escolha uma atividade ou 0 para retornar:" << endl;
            k = pro -> getAtividades() -> begin();
            cin >> resp;
            if (resp != 0) {
                for(i = 0; i < resp - 1; i++){
                    k++;        
                }
                term = (*k) -> estaTerminada();
                if (term == true) {
                    cout << "Atividade ja terminada" << endl;
                }
                else {
                    cout << "Duracao real:" << endl;
                    cin >> dr;
                    (*k) -> terminar(dr);
                }
            }
            
            resp = 7;
        }
        
        if (resp == 4) {
            pro -> imprimir();
            resp = 7;
        }
        
        if (resp == 5) {
            cout << "Valor atual: " << Pessoa::getValorPorHoraPadrao() << " reais por hora" << endl;
            cout << "Novo valor: " << endl;
            cin >> vph;
            Pessoa::setValorPorHoraPadrao(vph);
            resp = 7;
        }
        
        if (resp == 6) {
            cout << "Nome do arquivo: " << endl;
            cin >> nome;
            PersistenciaDeProjeto *per = new PersistenciaDeProjeto();
            per -> salvar(pro, nome);
            delete per;
            resp = 7;
        }
    }
    delete pro;
    return 0;
}