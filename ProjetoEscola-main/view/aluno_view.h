#include <stdio.h>

#ifndef ALUNO_VIEW_H
#define ALUNO_VIEW_H

#include "aluno_model.h"

void exibirListaAlunos(Aluno* lista, int qtd);
Aluno pedirDadosAluno();
int pedirMatricula(const char* tipoMatricula);
void exibirAluno(Aluno aluno);
int imprimirMenuRelatoriosAluno();
void exibirListaAlunosPorSexo(Aluno *lista, int qtd, char sexoFiltro);
void exibirListaAlunosAlfabetico(Aluno *lista, int qtd);
void exibirListaAlunosPorNascimento(Aluno *lista, int qtd);
void exibirAlunosMatriculadosMenos3Disciplinas(Aluno *lista);
void exibirListaAlunosPorMes(Aluno *lista, int qtd, int mes);
void exibirListaAlunosPorNome(Aluno *lista, int qtd, char *pesquisa);

#endif
