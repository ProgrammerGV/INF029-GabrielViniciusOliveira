#include "professor_controller.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void ModuloProfessor()
{
    int opcaoProfessor;
    int sairProfessor = 0;

    while (!sairProfessor)
    {
        opcaoProfessor = menuPessoa("Professor");

        switch (opcaoProfessor)
        {
        case 0:
        {
            sairProfessor = 1;
            mostrarMensagem("Voltando ao menu principal...");
            break;
        }
        case 1:
        { 
            mostrarMensagem(" --- Cadastrar Professor --- ");
            Professor novoProfessor = pedirDadosProfessor();
            int resultadoBusca = cadastrarProfessor(novoProfessor);

            if (resultadoBusca > 0)
            {
                novoProfessor.matricula = resultadoBusca;
                mostrarMensagem("Professor cadastrado com sucesso!");
                exibirProfessor(novoProfessor);
                pausarConsole();
            }

            else if (resultadoBusca == -1)
            {
                mostrarMensagem("Lista de professores cheia!");
                pausarConsole();
            }

            else if (resultadoBusca == -2)
            {
                mostrarMensagem("Cadastro cancelado. ");
                pausarConsole();
            }

            else if (resultadoBusca == 0)
            {
                mostrarMensagem("Já existe um professor cadastrado com essa matrícula! ");
                pausarConsole();
            }

            break;
        }
        case 2:
        { 
            mostrarMensagem(" --- Listar Professor --- ");
            int quantidade = obterQtdProfessor();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Professores Vazia!\nPrimeiro cadastre um professor.\n");
                pausarConsole();
                break;
            }
            else
            {
                Professor *listaCompleta = listarProfessor();
                exibirListaProfessores(listaCompleta, quantidade);
                free(listaCompleta);
                pausarConsole();
            }
            break;
        }
        case 3:
        { 
            mostrarMensagem(" --- Atualizar Professor --- ");
            int quantidade = obterQtdProfessor();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Professores Vazia!\nPrimeiro cadastre um professor.\n");
                pausarConsole();
                break;
            }
            int matriculaAntiga = lerMatricula("a matricula antiga", 2);
            int matriculaNova = lerMatricula("a matricula nova", 2);
            int resultadoAtualizacao = atualizarProfessor(matriculaAntiga, matriculaNova);

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
                mostrarMensagem("Já existe um professor cadastrado com a nova matrícula! ");
            }
            break;
        }
        case 4:
        { 
            mostrarMensagem(" --- Excluir Professor --- ");
            int quantidade = obterQtdProfessor();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Professores Vazia!\nPrimeiro cadastre um professor.\n");
                pausarConsole();
                break;
            }

            int matriculaExcluir = lerMatricula("a matricula a excluir", 2);

            int resultadoExclusao = excluirProfessor(matriculaExcluir);

            if (resultadoExclusao == 1)
            {
                mostrarMensagem("Professor excluído com sucesso!");
            }

            else if (resultadoExclusao == -2)
            {
                mostrarMensagem("Matrícula inválida. ");
            }

            else if (resultadoExclusao == -1)
            {
                mostrarMensagem("Matrícula não encontrada. ");
            }

            break;
        }
        case 5:
        { 

            int sairMenu = 0;
            int quantidade = obterQtdProfessor();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Professores Vazia!\nPrimeiro cadastre um professor.\n");
                pausarConsole();
                break;
            }

            while (!sairMenu)
            {
                int opcao = imprimirMenuRelatoriosProfessor();

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
                    char sexoRelatorio = lerSexo(sexoRelatorio);

                    Professor *listaAlfabetica = listarProfessor();
                    if (listaAlfabetica != NULL)
                    {
                        exibirListaProfessoresPorSexo(listaAlfabetica, quantidade, sexoRelatorio);
                        free(listaAlfabetica); 
                    }
                    pausarConsole();
                    break;
                }
                case 2:
                {
                    Professor *listaAlfabetica = listarProfessor();
                    if (listaAlfabetica != NULL)
                    {
                        exibirListaProfessoresAlfabetico(listaAlfabetica, quantidade);
                        free(listaAlfabetica);
                    }
                    pausarConsole();
                    break;
                }
                case 3:
                {
                    Professor *listaAlfabetica = listarProfessor();
                    if (listaAlfabetica != NULL)
                    {
                        exibirListaProfessoresPorNascimento(listaAlfabetica, quantidade);
                        free(listaAlfabetica);
                    }
                    pausarConsole();
                    break;
                }

                default:
                    break;
                }
            }
        }
        default:
        {
            mostrarMensagem("Opção Inválida!");
            break;
        }
        }
    }
}
