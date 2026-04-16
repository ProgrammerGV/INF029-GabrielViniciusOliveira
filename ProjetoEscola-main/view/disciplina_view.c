#include "disciplina_view.h"
#include "disciplina_controller.h"
#include "professor_model.h"
#include "matricula_model.h"
#include "aluno_model.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include <stdlib.h>

Disciplina pedirDadosDisciplina()
{
    Disciplina d;

    lerNome(d.nome);
    lerSemestre(d.semestre);
    d.matricula_professor = lerMatriculaWhile("a matricula do professor da disciplina", 2);

    return d;
}

void exibirDisciplina(Disciplina d)
{
    converterParaMaiusculo(d.nome);

    Professor *lista = listarProfessor();
    int qtd = obterQtdProfessor();
    for (int i = 0; i < qtd; i++)
    {
        if (lista[i].matricula == d.matricula_professor && lista[i].ativo == 1)
        {
            converterParaMaiusculo(lista[i].nome);
            printf("Codigo: %d | Nome: %s | Semestre: %s | Quantidade de Alunos: %d | Professor Matricula: %d | Nome: %s\n", d.codigo, d.nome, d.semestre, d.quantidadeAlunos, d.matricula_professor, lista[i].nome);
        }
    }
}

void exibirAlunosDisciplina(int codigoDisciplina)
{
    Aluno *listaAluno = listarAlunos();
    Disciplina *listaDisciplina = listarDisciplina();
    Matricula *listaMatricula = listarMatricula();

    int qtdDisciplinas = obterQtdDisciplina();
    int qtdAlunos = obterQtdAlunos();
    int qtdMatriculas = obterQtdMatricula();

    int indiceDisciplina = -1;

    for (int i = 0; i < qtdDisciplinas; i++)
    {
        if (listaDisciplina[i].codigo == codigoDisciplina && listaDisciplina[i].ativo == 1)
        {
            indiceDisciplina = i;
            break;
        }
    }

    if (indiceDisciplina == -1)
    {
        printf("Erro: Disciplina nao encontrada!\n");
        return;
    }

    printf("\n--- Alunos da Disciplina: %s | Codigo: %d ---\n", listaDisciplina[indiceDisciplina].nome, listaDisciplina[indiceDisciplina].codigo);

    int contadorAlunos = 0;

    for (int i = 0; i < qtdMatriculas; i++)
    {
        if (listaMatricula[i].codigoDisciplina == codigoDisciplina && listaMatricula[i].ativo == 1)
        {
            for (int j = 0; j < qtdAlunos; j++)
            {
                if (listaAluno[j].matricula == listaMatricula[i].matriculaAluno && listaAluno[j].ativo == 1)
                {
                    converterParaMaiusculo(listaAluno[j].nome);
                    printf("Matricula: %d | Nome: %s\n", listaAluno[j].matricula, listaAluno[j].nome);
                    contadorAlunos++;
                    break;
                }
            }
        }
    }

    if (contadorAlunos == 0)
    {
        printf("Nenhum aluno matriculado nesta disciplina ainda.\n");
    }
    printf("-----------------------------------\n");
}

void exibirListaDisciplinas(Disciplina *lista, int qtd)
{
    printf("\n ----- Lista de Disciplinas ----- \n");
    for (int i = 0; i < qtd; i++)
    {
        if (lista[i].ativo == 1)
        {
            exibirDisciplina(lista[i]);
        }
    }
    printf("----------------------------\n");
}

int imprimirMenuRelatoriosDisciplina()
{
    limparConsole();
    printf("---  Relatorios  ---\n");
    printf("0 - Voltar ao menu Principal \n");
    printf("1 - Imprimir em ordem alfabetica\n");
    printf("2 - Imprimir disciplina com alunos\n");
    printf("3 - Imprimir disciplinas com mais de 40 alunos\n");
    return lerOpcao(3);
}

void exibirListaDisciplinasAlfabetico(Disciplina *lista, int qtd)
{
    Disciplina *listaOrdenadaAlfabetica = listarDisciplina();

    for (int i = 0; i < qtd; i++)
    {
        if (listaOrdenadaAlfabetica[i].ativo == 1)
        {
            exibirDisciplina(listaOrdenadaAlfabetica[i]);
        }
    }
    printf("----------------------------\n");
    free(listaOrdenadaAlfabetica);
}

void lerSemestre(char *destino)
{
    while (1)
    {
        printf("Digite 0 para sair.\nDigite o semestre (ex: 2024.1): ");
        scanf("%s", destino);
        getchar();

        if (!strcmp(destino, "0"))
        {
            break;
        }

        if (verificarSemestre(destino) == 1)
        {
            break;
        }
        else
        {
            printf("Semestre invalido! Use o formato correto (ex: 2024.1 ou 2023.2).\n\n");
        }
    }
}

void exibirDisciplinaMais40Vagas(Disciplina *lista)
{
    for (int i = 0; i < obterQtdDisciplina(); i++)
    {
        if (lista[i].ativo == 1 && lista[i].quantidadeAlunos > 40)
        {
            exibirDisciplina(lista[i]);
        }

        printf("----------------------------\n");
    }
}
int menuDisciplina(const char *nome)
{
    limparConsole();
    printf("---- Modulo %s ----\n", nome);
    printf("\n0 - Voltar ao menu Principal \n");
    printf("1 - Cadastrar %s\n", nome);
    printf("2 - Listar %s\n", nome);
    printf("3 - Atualizar %s\n", nome);
    printf("4 - Excluir %s\n", nome);
    printf("5 - Matricular Alunos %s\n", nome);
    printf("6 - Relatorios %s\n", nome);

    return lerOpcao(6);
}