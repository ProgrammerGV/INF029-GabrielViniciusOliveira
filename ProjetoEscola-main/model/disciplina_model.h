#ifndef DISCIPLINA_MODEL_H
#define DISCIPLINA_MODEL_H

#define TAM_DISCIPLINA 20
#define TAM_NOME 100
#define TAM_SEMESTRE 8

typedef struct disciplina
{
    int codigo;
    char nome[TAM_NOME];
    char semestre[TAM_SEMESTRE];
    int ativo;
    int matricula_professor;
    int quantidadeAlunos;
} Disciplina;

int cadastrarDisciplina(Disciplina novaDisciplina);
int excluirDisciplina(int codigo);
Disciplina *listarDisciplina();
int obterQtdDisciplina();
int atualizarDisciplina(int codigo_antigo, int codigo_novo);
Disciplina* obterListaDisciplinasAlfabetica();
void incrementarQuantidadeAlunos(int codigoDisciplina);
int obterQuantidadeAlunos(int codigoDisciplina);
void decrementarQuantidadeAlunos(int codigoDisciplina);


#endif