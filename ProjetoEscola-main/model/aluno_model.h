#ifndef ALUNO_MODEL_H
#define ALUNO_MODEL_H

#define TAMANHO_NOME 100
#define TAMANHO_CPF 16
#define TAM_ALUNO 1000
#include "data_model.h"

typedef struct aluno
{
    int matricula;
    char nome [TAMANHO_NOME];
    char sexo;
    Data dataNascimento;
    char cpf [TAMANHO_CPF];
    int ativo;
    int quantidadeDisciplinas;
} Aluno;

int cadastrarAluno(Aluno novoAluno);
int atualizarAluno(int matricula_antiga, int matricula_nova);
int excluirAluno(int matricula);
Aluno* listarAlunos();
int obterQtdAlunos();
Aluno* obterListaAlunosAlfabetica();
void incrementarQuantidadeDisciplinas(int matriculaAluno);
void decrementarQuantidadeDisciplinas(int matriculaAluno);
int obterQuantidadeDisciplinas(int matriculaAluno);
#endif