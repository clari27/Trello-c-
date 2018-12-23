# Trello-c-
Software de gerenciamento de projeto similar ao Trello. Foi desenvolvido em C++ para a disciplina de laboratório de programação orientada a objetos - PCS3111 da Poli-USP 


Classes:

Pessoa: Subclasse de Recurso. Representa um trabalhador que executa parcialmente ou totalmente uma atividade dentro do projeto 
Atividade: Atividade é um trabalho a ser executado por uma ou mais pessoas dentro de um projeto.
Projeto: atividades que deverão ser executadas utilizando recursos.
Recurso: algo que é necessário para executar uma atividade. Podem ser pessoas ou ferramentas.
Ferramenta: subclasse de Recurso que representa uma ferramenta necessária (ex: codeblocks, caminhão, pá)
AtividadeDeEsforçoFixo: representa uma atividade que demanda quantidade fixa de esforço
AtividadeDePrazoFixo: ativdade cujo prazo independe da quantidade de pessoas trabalhando (em oposição à classe AtividadeDeEsforçoFixo);

