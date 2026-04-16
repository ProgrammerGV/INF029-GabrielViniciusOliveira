#include <stdio.h>
#include "aluno_controller.h"
#include "aluno_model.h"
#include "aluno_view.h"
#include "utils.h"
#include <stdlib.h>

void ModuloAluno()
{
    int sairAluno = 0;
    int opcaoAluno;

    while (!sairAluno)
    {
        opcaoAluno = menuPessoa("Aluno");

        switch (opcaoAluno)
        {
        case 0:
        {
            sairAluno = 1;
            mostrarMensagem("Voltando ao menu principal...");
            break;
        }

        case 1:
        {
            mostrarMensagem(" --- Cadastrar Aluno --- ");
            Aluno novoAluno = pedirDadosAluno();

            int resultadoBusca = cadastrarAluno(novoAluno);

            if (resultadoBusca > 0)
            {
                novoAluno.matricula = resultadoBusca;  
                mostrarMensagem("Aluno cadastrado com sucesso!");                 
                exibirAluno(novoAluno);
                pausarConsole();                
            }

            else if (resultadoBusca == -1)
            {
                mostrarMensagem("Lista de alunos cheia!  ");
            }

            else if (resultadoBusca == 0)
            {
                mostrarMensagem("Já existe um aluno cadastrado com essa matrícula! ");
            }

            else if (resultadoBusca == -2)
            {
                mostrarMensagem("Cadastro cancelado. ");
                pausarConsole();
            }
            break;
        }

        case 2:
        {
            mostrarMensagem(" --- Listar Aluno --- ");
            
            int quantidade = obterQtdAlunos();

            if (quantidade == 0) {
                mostrarMensagem("Lista de alunos vazia!\nPrimeiro cadastre um aluno.\n ");
                pausarConsole();
                break;
            }
            else{
                Aluno *listaCompleta = listarAlunos();
                exibirListaAlunos(listaCompleta, quantidade);
                free(listaCompleta);
                pausarConsole();
            }
            break;
        }
        case 3:
        {
            mostrarMensagem("  --- Atualizar Aluno ---  ");
            int matriculaAntiga = pedirMatricula("antiga");

            int matriculaNova = pedirMatricula("nova");

            int resultadoAtualizacao = atualizarAluno(matriculaAntiga, matriculaNova);

            if (resultadoAtualizacao == 1)
            {
                mostrarMensagem("Matrícula atualizada com sucesso! ");
            }

            else if (resultadoAtualizacao == -1)
            {
                mostrarMensagem("Matrícula antiga não encontrada. ");
            }

            else if (resultadoAtualizacao == -2)
            {
                mostrarMensagem("Matrícula nova inválida. ");
            }

            else if (resultadoAtualizacao == 0)
            {
                mostrarMensagem("Já existe um aluno cadastrado com a nova matrícula! ");
            }
            break;
        }

        case 4:
        {
            mostrarMensagem("  --- Excluir matricula de Aluno ---  ");

            int matriculaExcluir = pedirMatricula("a excluir");
            excluirTodasMatriculasAluno(matriculaExcluir);

            int resultadoExclusao = excluirAluno(matriculaExcluir);

            if (resultadoExclusao == 1)
            {
                mostrarMensagem("Aluno e suas matriculas foram excluidos com sucesso!");
            }

            else if (resultadoExclusao == -2)
            {
                mostrarMensagem("Matrícula inválida. ");
            }

            else if (resultadoExclusao == -1)
            {
                mostrarMensagem("Matrícula não encontrada. ");
            }
            pausarConsole();
            break;
        }
        case 5:
        { 

            int sairMenu = 0;
            int quantidade = obterQtdAlunos();
            
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Alunos Vazia!\nPrimeiro cadastre um aluno.\n");
                pausarConsole();
                break;
            }

            while (!sairMenu)
            {
                int opcao = imprimirMenuRelatoriosAluno();

                switch (opcao)
                {
                case 0:
                {
                    sairMenu = 1;
                    mostrarMensagem("Voltando ao menu principal...");
                    break;
                }
                case 1:
                {
                    char sexoRelatorio = ' ';
                    sexoRelatorio = lerSexo(sexoRelatorio); 

                    Aluno *listaAlfabetica = listarAlunos();
                    if (listaAlfabetica != NULL)
                    {
                        exibirListaAlunosPorSexo(listaAlfabetica, quantidade, sexoRelatorio);
                        free(listaAlfabetica); 
                    }
                    pausarConsole();
                    break;
                }
                case 2:
                {
                    Aluno *listaAlfabetica = listarAlunos();
                    if (listaAlfabetica != NULL)
                    {
                        exibirListaAlunosAlfabetico(listaAlfabetica, quantidade);
                        free(listaAlfabetica);
                    }
                    pausarConsole();
                    break;
                }
                case 3:
                {
                    Aluno *listaAlfabetica = listarAlunos();
                    if (listaAlfabetica != NULL)
                    {
                        exibirListaAlunosPorNascimento(listaAlfabetica, quantidade);
                        free(listaAlfabetica); 
                    }
                    pausarConsole();
                    break;
                }
                case 4:{
                    Aluno *lista = listarAlunos();
                    if (lista != NULL)
                    {
                        exibirAlunosMatriculadosMenos3Disciplinas(lista);
                        free(lista);
                    }
                    pausarConsole();
                    break;
                }

                default:
                {
                    mostrarMensagem("Opção Inválida!");
                    pausarConsole();
                    break;
                }
                }
            }
            break;
        }
        default:
        {
            mostrarMensagem("Opção Inválida!");
            break;
        }   
        }   

    }
}