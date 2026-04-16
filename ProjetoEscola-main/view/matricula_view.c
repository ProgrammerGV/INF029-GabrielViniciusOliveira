#include "matricula_view.h"
#include "matricula_controller.h"
#include "disciplina_model.h"
#include "aluno_model.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include <stdlib.h>

Matricula pedirDadosMatricula(int codigoDisciplina){
    Matricula m;

    m.codigoDisciplina = codigoDisciplina;
    m.matriculaAluno = lerMatricula("a matricula do aluno",1);

    return m;
}

void exibirMatricula(Matricula m)
{
    Disciplina *listaDisciplina = listarDisciplina();
    Aluno *listaAluno = listarAlunos();

    int qtdDisciplinas = obterQtdDisciplina();
    int qtdAlunos = obterQtdAlunos();

    int indiceDisciplina = -1;
    int indiceAluno = -1;

    for (int i = 0; i < qtdDisciplinas; i++)
    {
        if (listaDisciplina[i].codigo == m.codigoDisciplina && listaDisciplina[i].ativo == 1)
        {
            indiceDisciplina = i; 
            break; 
        }
    }

    for (int j = 0; j < qtdAlunos; j++)
    {
        if (listaAluno[j].matricula == m.matriculaAluno && listaAluno[j].ativo == 1)
        {
            indiceAluno = j; 
            break;
        }
    }

    if (indiceDisciplina != -1 && indiceAluno != -1)
    {
        converterParaMaiusculo(listaDisciplina[indiceDisciplina].nome);
        converterParaMaiusculo(listaAluno[indiceAluno].nome);
        printf("Codigo Disciplina: %d | Nome Disciplina: %s | Matricula Aluno: %d | Nome Aluno: %s\n", 
               listaDisciplina[indiceDisciplina].codigo, 
               listaDisciplina[indiceDisciplina].nome, 
               listaAluno[indiceAluno].matricula, 
               listaAluno[indiceAluno].nome);
    }
}

int menuMatricula()
{
    limparConsole();
    printf("---- Modulo Matricula ----\n");
    printf("\n0 - Voltar ao menu Principal \n");
    printf("1 - Cadastrar Matricula\n");
    printf("2 - Excluir Matricula\n");
    return lerOpcao(2);
}