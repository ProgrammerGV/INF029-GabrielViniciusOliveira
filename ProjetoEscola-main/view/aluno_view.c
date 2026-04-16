#include "aluno_view.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include "data_model.h"
#include <stdlib.h>

void exibirListaAlunos(Aluno* lista, int quantidade){
    printf("\n ----- Lista de Alunos ----- \n");

    for(int i = 0 ; i < quantidade; i++){
        if(lista[i].ativo == 1){
            exibirAluno(lista[i]);
        }
    }
    printf("----------------------------\n");
}

Aluno pedirDadosAluno() {
    Aluno aluno;
    
    lerNome(aluno.nome);
    aluno.sexo = lerSexo(aluno.sexo);
    lerCPF(aluno.cpf);
    lerDataNascimento(&aluno.dataNascimento);

    return aluno;
}

int pedirMatricula(const char* tipoMatricula){
    limparConsole();
    int matricula;
    printf("\nDigite a matricula %s: ", tipoMatricula);
    scanf("%d", &matricula);
    return matricula;
}

void exibirAluno(Aluno aluno)
{
    converterParaMaiusculo(aluno.nome);

    printf("Matricula: %d | Nome: %s | Sexo: %c | Data de Nascimento: %02d/%02d/%04d | CPF: %s | Disciplinas: %d\n", 
           aluno.matricula, 
           aluno.nome, 
           toupper(aluno.sexo), 
           aluno.dataNascimento.dia,
           aluno.dataNascimento.mes,
           aluno.dataNascimento.ano,
           aluno.cpf,aluno.quantidadeDisciplinas);
}

int imprimirMenuRelatoriosAluno()
{
    limparConsole();
    printf("---  Relatorios  ---\n");
    printf("0 - Voltar ao menu Principal \n");
    printf("1 - Imprimir por Sexo\n");
    printf("2 - Imprimir em ordem alfabetica\n");
    printf("3 - Imprimir por data de nascimento\n");
    printf("4 - Imprimir alunos matriculados em menos de 3 disciplinas");
    return lerOpcao(4);
}

void exibirListaAlunosPorSexo(Aluno *lista, int qtd, char sexoFiltro)
{
    for (int i = 0; i < qtd; i++)
    {
        if (lista[i].ativo == 1 && lista[i].sexo == sexoFiltro)
        {
            exibirAluno(lista[i]);
        }
    }
    printf("----------------------------\n");
}

void exibirListaAlunosAlfabetico(Aluno *lista, int qtd)
{
    Aluno *listaOrdenadaAlfabetica = listarAlunos(); 

    for (int i = 0; i < qtd; i++)
    {
        if (listaOrdenadaAlfabetica[i].ativo == 1)
        {
            exibirAluno(listaOrdenadaAlfabetica[i]);
        }
    }
    printf("----------------------------\n");
    
    free(listaOrdenadaAlfabetica); 
}

void exibirListaAlunosPorNascimento(Aluno *lista, int qtd)
{
    Aluno listaOrdenada[100]; 
    for (int i = 0; i < qtd; i++)
    {
        listaOrdenada[i] = lista[i];
    }
    for (int i = 0; i < qtd; i++)
    {
        for (int j = i + 1; j < qtd; j++)
        {
            if (listaOrdenada[i].ativo == 1 && listaOrdenada[j].ativo == 1)
            {
                if ((listaOrdenada[i].dataNascimento.ano > listaOrdenada[j].dataNascimento.ano) || 
                    (listaOrdenada[i].dataNascimento.ano == listaOrdenada[j].dataNascimento.ano && listaOrdenada[i].dataNascimento.mes > listaOrdenada[j].dataNascimento.mes) || 
                    (listaOrdenada[i].dataNascimento.ano == listaOrdenada[j].dataNascimento.ano && listaOrdenada[i].dataNascimento.mes == listaOrdenada[j].dataNascimento.mes && listaOrdenada[i].dataNascimento.dia > listaOrdenada[j].dataNascimento.dia))
                {
                    Aluno aux;
                    aux = listaOrdenada[i];
                    listaOrdenada[i] = listaOrdenada[j];
                    listaOrdenada[j] = aux;
                }
            }
        }
    }
    for (int i = 0; i < qtd; i++)
    {
        if (listaOrdenada[i].ativo == 1)
        {
            exibirAluno(listaOrdenada[i]);
        }
    }
    printf("----------------------------\n");
}

void exibirAlunosMatriculadosMenos3Disciplinas(Aluno *lista){

    for (int i = 0; i < obterQtdAlunos(); i++)
    {
        if (lista[i].ativo == 1 && lista[i].quantidadeDisciplinas < 3)
        {
            exibirAluno(lista[i]);
        }
    }
    printf("----------------------------\n");
}
void exibirListaAlunosPorMes(Aluno *lista, int qtd, int mes) {
    int encontrou = 0;
    printf("\n --- Aniversariantes do Mes %d (Alunos) --- \n", mes);
    
    for (int i = 0; i < qtd; i++) {
        if (lista[i].ativo == 1 && lista[i].dataNascimento.mes == mes) {
            exibirAluno(lista[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum aluno faz aniversario neste mes.\n");
    }
    printf("-------------------------------------------\n");
}


void exibirListaAlunosPorNome(Aluno *lista, int qtd, char *pesquisa) {
    int encontrou = 0;
    printf("\n --- Resultados da Busca por: '%s' (Alunos) --- \n", pesquisa);

    for (int i = 0; i < qtd; i++) {
        if (lista[i].ativo == 1) {

            if (strstr(lista[i].nome, pesquisa) != NULL) {
                exibirAluno(lista[i]);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum aluno encontrado com esse termo.\n");
    }
    printf("----------------------------------------------\n");
}
