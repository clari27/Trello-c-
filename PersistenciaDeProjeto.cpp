#include "PersistenciaDeProjeto.h"

PersistenciaDeProjeto::PersistenciaDeProjeto() {
}

PersistenciaDeProjeto::~PersistenciaDeProjeto() {
}

void PersistenciaDeProjeto::salvar(Projeto* p, string arquivo) {
    int n, q;
    
    list<Recurso*>* l = p -> getRecursos();
    vector<Atividade*>* v = p -> getAtividades();
    
    ofstream output;
    output.open(arquivo);
    
    if (output.fail()) {
        output.close();
        throw new ErroDeArquivo("Erro ao escrever.");
    }
    
    output << p -> getNome() << endl;
    output << l -> size() << endl;
    
    list<Recurso*>::iterator i = l -> begin();
    
    Ferramenta *f = dynamic_cast<Ferramenta*>((*i));
    
    while (i != l -> end()) {
      
        if (f == NULL) {
            output << "P" << " " << (*i) -> getNome() << " ";
            Pessoa *peo = dynamic_cast<Pessoa*>((*i));
            if (peo -> recebeValorPadrao()) {
                cout << "-1" << " " << peo -> getHorasDiarias() << endl;
            }
            else {
                cout << peo -> getValorPorHora() << " " << peo -> getHorasDiarias() << endl;    
            }
            delete peo;
        }
        else {
            output << "F" << " " << f -> getNome() << " " << f -> getCustoDiario() << endl;
            delete f;
        }
        
        i++;
    }
    
    output << v -> size() << endl;
    
    vector<Atividade*>::iterator j = v -> begin();
    
    AtividadeDePrazoFixo *a = dynamic_cast<AtividadeDePrazoFixo*>((*j));
    
    while (j != v -> end()) {
        
        if (a == NULL) {
            AtividadeDeEsforcoFixo *ae = dynamic_cast<AtividadeDeEsforcoFixo*>((*j));
            output << "E" << " " << ae -> getNome() << " " << ae -> getHorasNecessarias() << " ";
            if (ae -> estaTerminada()) {
                output << "T" << " " << ae -> getDuracao() << endl; 
            }
            else {
                output << "N" << endl;
            }
            delete ae;
        }
        else {
            output << "P" << " " << a -> getNome() << " " << a -> getPrazo() << " ";
            if(a -> estaTerminada()) {
                output << "T" << " " << a -> getDuracao() << endl;
            }
            else {
                output << "N" << endl;
            }
            delete a;
        }
        
        q = (*j) -> getQuantidadeDeRecursos();
        
        output << q << endl;
        
        if (q > 0) {
            Recurso **r = (*j) -> getRecursos();
            for (n = 0; n < q; n++) {
                output << r[n] -> getNome() << " ";
            }
            output << endl;
            delete[] r;
        }
        
        j++;
    }
    
    output.close();
    delete l;
    delete v;
}

Projeto* PersistenciaDeProjeto::carregar(string arquivo) {
    int i, nrp, nra, na, hd, hn, dur, prazo;
    string nome, tipo, ter;
    double vph, cd;
    list<Recurso*>::iterator j;
    
    ifstream input;
    input.open(arquivo);
    
    if(input.fail()){
        input.close();
        throw new ErroDeArquivo("Erro ao ler.");
    }
    
    input >> nome;
    
    if(input.fail()){
        input.close();
        throw new ErroDeArquivo("Erro ao ler.");
    }
    
    Projeto* pro = new Projeto(nome);
    
    input >> nrp;
    
    if(input.fail()){
        input.close();
        throw new ErroDeArquivo("Erro ao ler.");
    }
    
    if(nrp < 0) {
        input.close();
        throw new ErroDeArquivo("Arquivo Invalido.");
    }
    
    for(i = 0; i < nrp; i++) {
        input >> tipo;
        if(input.fail()) {
            input.close();
            throw new ErroDeArquivo("Erro ao ler.");
        }
        if(tipo != "P" && tipo != "F") {
            input.close();
            throw new ErroDeArquivo("Arquivo Invalido.");    
        }
        if(tipo == "P") {
            input >> nome;
            if(input.fail()) {
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");
            }
            input >> vph;
            if(input.fail()) {
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");
            }
            if(vph < -1) {
                input.close();
                throw new ErroDeArquivo("Arquivo Invalido.");
            }
            input >> hd;
            if(input.fail()) {
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");
            }
            if(hd < 0) {
                input.close();
                throw new ErroDeArquivo("Arquivo Invalido.");
            }
            if(vph == -1) {
                vph = Pessoa::getValorPorHoraPadrao();
            }
            Pessoa *pes = new Pessoa(nome, vph, hd);
            pro -> adicionar(pes);
            
        }
        if(tipo == "F") {
            input >> nome;
            if(input.fail()) {
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");
            }
            input >> cd;
            if(input.fail()) {
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");
            }
            if(cd < 0) {
                input.close();
                throw new ErroDeArquivo("Arquivo Invalido.");    
            }
            Ferramenta *fer = new Ferramenta(nome, cd);
            pro -> adicionar(fer);
        }
    }
    
    input >> na;
    
    if (input.fail()) {
        input.close();
        throw new ErroDeArquivo("Erro ao ler.");
    }
    
    if (na < 0) {
        input.close();
        throw new ErroDeArquivo("Arquivo Invalido.");    
    }
    
    for(i = 0; i < na; i++) {
        input >> tipo;
        if (input.fail()) { 
            input.close();
            throw new ErroDeArquivo("Erro ao ler.");    
        }
        if (tipo != "E" && tipo != "P") {
            input.close();
            throw new ErroDeArquivo("Arquivo Invalido.");
        }
        if(tipo == "E") {
            input >> nome;
            if(input.fail()) { 
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");    
            }
            input >> hn;
            if(input.fail()) { 
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");    
            }
            if(hn < 0) {
                input.close();
                throw new ErroDeArquivo("Arquivo Invalido");
            }
            input >> ter;
            if(input.fail()) { 
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");    
            }
            if(ter != "T" && ter != "N") {
                input.close();
                throw new ErroDeArquivo("Arquivo Invalido");    
            }
            if(ter == "T") {
                input >> dur;
                if(input.fail()) { 
                    input.close();
                    throw new ErroDeArquivo("Erro ao ler.");    
                }
                if(dur < 0) {
                    input.close();
                    throw new ErroDeArquivo("Arquivo Invalido");    
                }
            }
            AtividadeDeEsforcoFixo *a = new AtividadeDeEsforcoFixo(nome, hn);
        }
        
        if(tipo == "P") {
            input >> nome;
            if(input.fail()) { 
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");    
            }
            input >> prazo;
            if(input.fail()) { 
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");    
            }
            if (prazo < 0) {
                input.close();
                throw new ErroDeArquivo("Arquivo Invalido");    
            }
            input >> ter;
            if(input.fail()) { 
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");    
            }
            if(ter != "T" && ter != "N") {
                input.close();
                throw new ErroDeArquivo("Arquivo Invalido");    
            }
            if (ter == "T") {
                input >> dur;
                if(input.fail()) { 
                    input.close();
                    throw new ErroDeArquivo("Erro ao ler.");    
                }
                if(dur < 0) {
                    input.close();
                    throw new ErroDeArquivo("Arquivo Invalido");    
                }
            }
            AtividadeDePrazoFixo *a = new AtividadeDePrazoFixo(nome, prazo);
        }
        
        input >> nra;
        if(input.fail()) { 
            input.close();
            throw new ErroDeArquivo("Erro ao ler.");    
        }
        if(nra < 0) {
            input.close();
            throw new ErroDeArquivo("Arquivo Invalido"); 
        }
        
        j = pro -> getRecursos() -> begin();
        
        for(i = 0; i < nra; i++) {
            
            input >> nome;
            if(input.fail()) { 
                input.close();
                throw new ErroDeArquivo("Erro ao ler.");    
            }
            Atividade *a;
            while(j != pro -> getRecursos() -> end()) {
                if ( nome == ((*j) -> getNome()) ) {
                    a -> adicionar((*j));   
                }
                j++;
            }
            
            j = pro -> getRecursos() -> begin();
            
        }
        Atividade *a;
        if (ter == "T") {
            a -> terminar(dur);
        }
        
        pro -> adicionar(a);
    }
    
    input.close();
    return pro;
}