#include "disciplina_controller.h"
#include "matricula_controller.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ModuloDisciplina()
{
    int opcaoDisciplina;
    int sairDisciplina = 0;

    while (!sairDisciplina)
    {
        opcaoDisciplina = menuDisciplina("Disciplina");

        switch (opcaoDisciplina)
        {
        case 0:
        {
            sairDisciplina = 1;
            mostrarMensagem("Voltando ao menu principal...");
            break;
        }
        case 1:
        { 
            mostrarMensagem(" --- Cadastrar Disciplina --- ");
            Disciplina novaDisciplina = pedirDadosDisciplina();
            int resultadoBusca = cadastrarDisciplina(novaDisciplina);

            if (resultadoBusca > 0)
            {
                novaDisciplina.codigo = resultadoBusca;
                mostrarMensagem("Disciplina cadastrada com sucesso!");
                exibirDisciplina(novaDisciplina);
                pausarConsole();
            }

            else if (resultadoBusca == -1)
            {
                mostrarMensagem("Lista de Disciplinas cheia!");
            }

            else if (resultadoBusca == 0)
            {
                mostrarMensagem("Já existe uma Disciplina cadastrada com essa disciplina! ");
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
            mostrarMensagem(" --- Listar Disciplina --- ");
            int quantidade = obterQtdDisciplina();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Disciplinas Vazia!\nPrimeiro cadastre uma Disciplina.\n");
                pausarConsole();
                break;
            }
            else
            {
                Disciplina *listaCompleta = listarDisciplina();
                exibirListaDisciplinas(listaCompleta, quantidade);
                free(listaCompleta);
                pausarConsole();
            }
            break;
        }
        case 3:
        {
            mostrarMensagem(" --- Atualizar Disciplina --- ");
            int quantidade = obterQtdDisciplina();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Disciplinas Vazia!\nPrimeiro cadastre uma Disciplina.\n");
                pausarConsole();
                break;
            }
            int codigoAntigo = lerMatricula("a matricula antiga", 3);
            int codigoNovo = lerMatricula("a matricula nova", 3);
            int resultadoAtualizacao = atualizarDisciplina(codigoAntigo, codigoNovo);

            if (resultadoAtualizacao == 1)
            {
                mostrarMensagem("Codigo atualizado com sucesso! ");
            }

            else if (resultadoAtualizacao == -1)
            {
                mostrarMensagem("Codigo antigo não encontrado. ");
            }

            else if (resultadoAtualizacao == -2)
            {
                mostrarMensagem("Codigo novo inválido. ");
            }

            else if (resultadoAtualizacao == 0)
            {
                mostrarMensagem("Já existe uma disciplina cadastrada com o novo codigo! ");
            }
            break;
        }
        case 4:
        { 
            mostrarMensagem(" --- Excluir Disciplina --- ");
            int quantidade = obterQtdDisciplina();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Disciplinas Vazia!\nPrimeiro cadastre uma Disciplina.\n");
                pausarConsole();
                break;
            }

            int codigoExcluir = lerMatricula("a matricula a excluir", 3);

            int resultadoExclusao = excluirDisciplina(codigoExcluir);

            if (resultadoExclusao == 1)
            {
                mostrarMensagem("Disciplina excluída com sucesso!");
            }

            else if (resultadoExclusao == -2)
            {
                mostrarMensagem("Codigo inválido. ");
            }

            else if (resultadoExclusao == -1)
            {
                mostrarMensagem("Codigo não encontrado. ");
            }

            break;
        }
        case 5:
        {
            limparConsole();
            ModuloMatricula();
            break;
        }
        case 6:
        { 

            int sairMenu = 0;
            int quantidade = obterQtdDisciplina();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Disciplinas Vazia!\nPrimeiro cadastre uma Disciplina.\n");
                pausarConsole();
                break;
            }

            while (!sairMenu)
            {
                int opcao = imprimirMenuRelatoriosDisciplina();

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
                    Disciplina *listaAlfabetica = listarDisciplina();
                    if (listaAlfabetica != NULL)
                    {
                        exibirListaDisciplinasAlfabetico(listaAlfabetica, quantidade);
                        free(listaAlfabetica);
                    }
                    pausarConsole();
                    break;
                }
                case 2:
                {
                    int codigo = lerMatriculaWhile("o codigo da disciplina", 3);
                    exibirAlunosDisciplina(codigo);
                    pausarConsole();
                    break;
                }
                case 3:
                {
                    Disciplina *lista = listarDisciplina();
                    if (lista != NULL)
                    {
                        exibirDisciplinaMais40Vagas(lista);
                        free(lista);
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

int verificarSemestre(const char *semestre)
{
    if (strlen(semestre) != 6)
    {
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        if (semestre[i] < '0' || semestre[i] > '9')
        {
            return 0;
        }
    }

    if (semestre[4] != '.')
    {
        return 0;
    }

    if (semestre[5] != '1' && semestre[5] != '2')
    {
        return 0;
    }

    int ano = (semestre[0] - '0') * 1000 +
              (semestre[1] - '0') * 100 +
              (semestre[2] - '0') * 10 +
              (semestre[3] - '0');

    if (ano < 2000 || ano > 2026)
    {
        return 0;
    }

    return 1;
}