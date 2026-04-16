#include <stdio.h>
#include "aluno_model.h"
#include <string.h>
#include <stdlib.h>
#include "utils.h"

Aluno listaAluno[TAM_ALUNO];
int qtdAluno = 0;
int geradorMatricula = 1;

int cadastrarAluno(Aluno novoAluno)
{
    
    if (qtdAluno == TAM_ALUNO)
        return -1; 


    if(!strcmp(novoAluno.cpf,"0")|| novoAluno.sexo == '0'  || novoAluno.dataNascimento.dia == 0 || novoAluno.dataNascimento.mes == 0 || novoAluno.dataNascimento.ano == 0){
        return -2;
    }
    

    int matriculaCriada = geradorMatricula;

    listaAluno[qtdAluno].matricula = geradorMatricula; 
    geradorMatricula++;

    listaAluno[qtdAluno].sexo = novoAluno.sexo;
    strcpy(listaAluno[qtdAluno].nome, novoAluno.nome);
    listaAluno[qtdAluno].dataNascimento.dia = novoAluno.dataNascimento.dia;
    listaAluno[qtdAluno].dataNascimento.mes = novoAluno.dataNascimento.mes;
    listaAluno[qtdAluno].dataNascimento.ano = novoAluno.dataNascimento.ano;
    strcpy(listaAluno[qtdAluno].cpf, novoAluno.cpf);
    listaAluno[qtdAluno].quantidadeDisciplinas = 0;
    listaAluno[qtdAluno].ativo = 1;
    qtdAluno++;


    return matriculaCriada; 
}

Aluno *listarAlunos()
{
    Aluno *listaOrdenada = obterListaAlunosAlfabetica();
    return listaOrdenada;
}

int obterQtdAlunos() {
    return qtdAluno;
}

int atualizarAluno(int matricula_antiga, int matricula_nova)
{
    if (matricula_nova < 0)
        return -2; 

    for (int i = 0; i < qtdAluno; i++){
        if (verificarMatricula(matricula_nova, 1)){
            return 0; 
        }
    }

    for (int i = 0; i < qtdAluno; i++){
        if(listaAluno[i].matricula == matricula_antiga && listaAluno[i].ativo == 1){
            listaAluno[i].matricula = matricula_nova;
            return 1;
        }
    }

    return -1; 
}

int excluirAluno(int matricula)
{
    if (matricula < 0) return -2;

    for (int i = 0; i < qtdAluno; i++){
        if(matricula == listaAluno[i].matricula && listaAluno[i].ativo){
            for(int j = i; j < qtdAluno - 1; j++){
                listaAluno[j] = listaAluno[j + 1];
            }
            qtdAluno--;
            return 1; 
        }
    }
    
    return -1; 
}

Aluno* obterListaAlunosAlfabetica()
{
    int qtd = qtdAluno;

    Aluno *listaOrdenada = malloc(qtd * sizeof(Aluno));
    
    if (listaOrdenada == NULL) {
        return NULL; 
    }

    for (int i = 0; i < qtd; i++)
    {
        listaOrdenada[i] = listaAluno[i];
    }

    for (int i = 0; i < qtd; i++)
    {
        for (int j = i + 1; j < qtd; j++)
        {
            if (listaOrdenada[i].ativo == 1 && listaOrdenada[j].ativo == 1)
            {
                if (strcmp(listaOrdenada[i].nome, listaOrdenada[j].nome) > 0)
                {
                    Aluno aux = listaOrdenada[i];
                    listaOrdenada[i] = listaOrdenada[j];
                    listaOrdenada[j] = aux;
                }
            }
        }
    }
        return listaOrdenada;
}

void incrementarQuantidadeDisciplinas(int matriculaAluno)
{
   
    for (int i = 0; i < obterQtdAlunos(); i++)
    {
        if (matriculaAluno == listaAluno[i].matricula && listaAluno[i].ativo == 1)
        {
            listaAluno[i].quantidadeDisciplinas++;
        }
    }
}

void decrementarQuantidadeDisciplinas(int matriculaAluno)
{
   
    for (int i = 0; i < obterQtdAlunos(); i++)
    {
        if (matriculaAluno == listaAluno[i].matricula && listaAluno[i].ativo == 1)
        {
            listaAluno[i].quantidadeDisciplinas--;
        }
    }
}

int obterQuantidadeDisciplinas(int matriculaAluno)
{
    for (int i = 0; i < obterQtdAlunos(); i++)
    {
        if (matriculaAluno == listaAluno[i].matricula && listaAluno[i].ativo == 1)
        {
            return listaAluno[i].quantidadeDisciplinas;
        }
    }
    return 0;
}
