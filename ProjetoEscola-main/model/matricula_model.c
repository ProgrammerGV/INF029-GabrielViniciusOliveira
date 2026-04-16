#include <stdio.h>
#include "matricula_model.h"
#include "disciplina_model.h"
#include "aluno_model.h"
#include "utils.h"

Matricula listaMatricula[TAM_MATRICULA];

int qtdMatricula = 0;

int cadastrarAlunoDisciplina(Matricula novaMatricula)
{
    if (qtdMatricula == TAM_MATRICULA)
    {
        return -1;
    }
    if (novaMatricula.matriculaAluno == 0 || novaMatricula.codigoDisciplina == 0)
    {
        return -2;
    }
    if(verificarMatricula(novaMatricula.matriculaAluno,1) == 0){
        return -4;
    }
    for (int i = 0; i < qtdMatricula; i++)
    {
        if (novaMatricula.matriculaAluno == listaMatricula[i].matriculaAluno && novaMatricula.codigoDisciplina == listaMatricula[i].codigoDisciplina && novaMatricula.ativo == 1)
        {
            return -3;
        }
    }

    listaMatricula[qtdMatricula].matriculaAluno = novaMatricula.matriculaAluno;
    listaMatricula[qtdMatricula].codigoDisciplina = novaMatricula.codigoDisciplina;

    listaMatricula[qtdMatricula].ativo = 1;
    incrementarQuantidadeAlunos(listaMatricula[qtdMatricula].codigoDisciplina);
    incrementarQuantidadeDisciplinas(listaMatricula[qtdMatricula].matriculaAluno);
    qtdMatricula++;
    
    

    return qtdMatricula;
}

Matricula *listarMatricula()
{
    return listaMatricula;
}

int obterQtdMatricula()
{
    return qtdMatricula;
}

int excluirAlunoDisciplina(int matriculaAluno, int codigoDisciplina)
{
    if (matriculaAluno < 0 || codigoDisciplina < 0)
    {
        return -2;
    }

    for (int i = 0; i < qtdMatricula; i++)
    {
        if (matriculaAluno == listaMatricula[i].matriculaAluno && codigoDisciplina == listaMatricula[i].codigoDisciplina && listaMatricula[i].ativo)
        {
            for (int j = i; j < qtdMatricula - 1; j++)
            {
                listaMatricula[j] = listaMatricula[j + 1];
            }
            decrementarQuantidadeAlunos(codigoDisciplina);
            decrementarQuantidadeDisciplinas(matriculaAluno);
            qtdMatricula--;
            return 1;
        }
    }
    return -1;
}

void excluirTodasMatriculasAluno(int matriculaAluno)
{
    for (int i = 0; i < qtdMatricula; i++)
    {
        if (listaMatricula[i].matriculaAluno == matriculaAluno && listaMatricula[i].ativo == 1)
        {
            decrementarQuantidadeAlunos(listaMatricula[i].codigoDisciplina);

            for (int j = i; j < qtdMatricula - 1; j++)
            {
                listaMatricula[j] = listaMatricula[j + 1];
            }
            listaMatricula[i].ativo = 0;
            qtdMatricula--;

            i--; 
        }
    }
}