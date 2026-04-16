#include "busca_controller.h"
#include "aluno_model.h"
#include "professor_model.h"
#include "aluno_view.h"
#include "professor_view.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menuAniversario()
{
    limparConsole();
    printf("---- Modulo Aniversariantes ----\n");
    printf("\n0 - Voltar ao menu Principal \n");
    printf("1 - Ver apenas Alunos\n");
    printf("2 - Ver apenas Professores\n");
    printf("3 - Ver Ambos (Alunos e Professores)\n");
    return lerOpcao(3);
}

int lerMes()
{
    int mes;
    while (1)
    {
        printf("Digite o mês desejado (1 a 12): ");
        scanf("%d", &mes);
        getchar(); 
        if (mes >= 1 && mes <= 12)
        {
            return mes;
        }
        mostrarMensagem("Mês inválido! Tente novamente.");
    }
}

void ModuloAniversario()
{
    int opcaoAniversario;
    int sairAniversario = 0;

    while (!sairAniversario)
    {
        opcaoAniversario = menuAniversario();

        switch (opcaoAniversario)
        {
        case 0:
        {
            sairAniversario = 1;
            mostrarMensagem("Voltando ao menu principal...");
            break;
        }
        case 1:
        {
            mostrarMensagem(" --- Aniversariantes: Alunos --- ");
            int quantidade = obterQtdAlunos();
            
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Alunos Vazia!\nPrimeiro cadastre um aluno.\n");
                pausarConsole();
                break;
            }
            
            int mes = lerMes();
            Aluno *listaCompleta = listarAlunos();
            
            if (listaCompleta != NULL)
            {
                exibirListaAlunosPorMes(listaCompleta, quantidade, mes);
                free(listaCompleta);
            }
            pausarConsole();
            break;
        }
        case 2:
        {
            mostrarMensagem(" --- Aniversariantes: Professores --- ");
            int quantidade = obterQtdProfessor();
            
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Professores Vazia!\nPrimeiro cadastre um professor.\n");
                pausarConsole();
                break;
            }

            int mes = lerMes();
            Professor *listaCompleta = listarProfessor();
            
            if (listaCompleta != NULL)
            {
                exibirListaProfessoresPorMes(listaCompleta, quantidade, mes);
                free(listaCompleta);
            }
            pausarConsole();
            break;
        }
        case 3:
        {
            mostrarMensagem(" --- Aniversariantes: Ambos --- ");
            int qtdAlunos = obterQtdAlunos();
            int qtdProf = obterQtdProfessor();

            if (qtdAlunos == 0 && qtdProf == 0)
            {
                mostrarMensagem("Nenhum Aluno ou Professor cadastrado no sistema!\n");
                pausarConsole();
                break;
            }

            int mes = lerMes();

            if (qtdAlunos > 0)
            {
                Aluno *listaA = listarAlunos();
                if (listaA != NULL)
                {
                    exibirListaAlunosPorMes(listaA, qtdAlunos, mes);
                    free(listaA);
                }
            }

            if (qtdProf > 0)
            {
                Professor *listaP = listarProfessor();
                if (listaP != NULL)
                {
                    exibirListaProfessoresPorMes(listaP, qtdProf, mes);
                    free(listaP);
                }
            }
            
            pausarConsole();
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

int menuBusca()
{
    limparConsole();
    printf("---- Modulo de Busca por Nome ----\n");
    printf("\n0 - Voltar ao menu Principal \n");
    printf("1 - Buscar Alunos\n");
    printf("2 - Buscar Professores\n");
    printf("3 - Buscar Ambos\n");
    return lerOpcao(3);
}

void lerTermoBusca(char *termo)
{
    while (1)
    {
        printf("Digite o nome (minimo 3 letras): ");
        scanf(" %100[^\n]", termo);
        getchar(); 

        if (strlen(termo) >= 3)
        {
            break;
        }
        mostrarMensagem("Termo muito curto! Digite pelo menos 3 letras.");
    }
}

void ModuloBusca()
{
    int opcaoBusca;
    int sairBusca = 0;
    char termo[101];

    while (!sairBusca)
    {
        opcaoBusca = menuBusca();

        switch (opcaoBusca)
        {
        case 0:
        {
            sairBusca = 1;
            mostrarMensagem("Voltando ao menu principal...");
            break;
        }
        case 1:
        {
            mostrarMensagem(" --- Buscar Alunos --- ");
            int quantidade = obterQtdAlunos();
            
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Alunos Vazia!\n");
                pausarConsole();
                break;
            }

            lerTermoBusca(termo);
            Aluno *listaCompleta = listarAlunos();
            
            if (listaCompleta != NULL)
            {
                exibirListaAlunosPorNome(listaCompleta, quantidade, termo);
                free(listaCompleta);
            }
            pausarConsole();
            break;
        }
        case 2:
        {
            mostrarMensagem(" --- Buscar Professores --- ");
            int quantidade = obterQtdProfessor();
            
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Professores Vazia!\n");
                pausarConsole();
                break;
            }

            lerTermoBusca(termo);
            Professor *listaCompleta = listarProfessor();
            
            if (listaCompleta != NULL)
            {
                exibirListaProfessoresPorNome(listaCompleta, quantidade, termo);
                free(listaCompleta);
            }
            pausarConsole();
            break;
        }
        case 3:
        {
            mostrarMensagem(" --- Buscar Ambos --- ");
            int qtdAlunos = obterQtdAlunos();
            int qtdProf = obterQtdProfessor();

            if (qtdAlunos == 0 && qtdProf == 0)
            {
                mostrarMensagem("Nenhum Aluno ou Professor cadastrado no sistema!\n");
                pausarConsole();
                break;
            }

            lerTermoBusca(termo);

            if (qtdAlunos > 0)
            {
                Aluno *listaA = listarAlunos();
                if (listaA != NULL)
                {
                    exibirListaAlunosPorNome(listaA, qtdAlunos, termo);
                    free(listaA);
                }
            }

            if (qtdProf > 0)
            {
                Professor *listaP = listarProfessor();
                if (listaP != NULL)
                {
                    exibirListaProfessoresPorNome(listaP, qtdProf, termo);
                    free(listaP);
                }
            }
            
            pausarConsole();
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