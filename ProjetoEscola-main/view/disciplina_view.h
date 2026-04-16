#ifndef DISCIPLINA_VIEW_H
#define DISCIPLINA_VIEW_H

#include "disciplina_model.h"

Disciplina pedirDadosDisciplina();
void exibirDisciplina(Disciplina d);
void exibirListaDisciplinas(Disciplina *lista, int qtd);
int imprimirMenuRelatoriosDisciplina();
void exibirListaDisciplinasAlfabetico(Disciplina *lista, int qtd);
void exibirAlunosDisciplina(int codigoDisciplina);
void lerSemestre(char *destino);
void exibirDisciplinaMais40Vagas(Disciplina *lista);
int menuDisciplina(const char *nome);
#endif