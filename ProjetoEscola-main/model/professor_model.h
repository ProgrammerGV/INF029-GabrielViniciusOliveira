#ifndef PROFESSOR_MODEL_H
#define PROFESSOR_MODEL_H
#include "data_model.h"

#define TAM_PROFESSOR 200
#define TAM_CPF 16
#define TAM_NOME 100

typedef struct professor
{
    int matricula;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char sexo;
    int ativo;
    Data dataNascimento;
} Professor;

int cadastrarProfessor(Professor novoProfessor);
int excluirProfessor(int matricula);
Professor *listarProfessor();
int obterQtdProfessor();
int atualizarProfessor(int matricula_antiga, int matricula_nova);
Professor* obterListaProfessoresAlfabetica();

#endif