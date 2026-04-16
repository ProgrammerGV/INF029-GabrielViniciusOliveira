#include "matricula_controller.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "matricula_model.h"
void ModuloMatricula()
{
    int opcaoMatricula;
    int sairMatricula = 0;

    while (!sairMatricula)
    {
        opcaoMatricula = menuMatricula();

        switch (opcaoMatricula)
        {
        case 0:
        {
            sairMatricula = 1;
            mostrarMensagem("Voltando ao menu principal...");
            break;
        }
        case 1:
        {
            mostrarMensagem(" --- Cadastrar Aluno em Disciplina --- ");
            int codigoDisciplina = lerMatriculaWhile("o codigo da disciplina", 3);

            while (1)
            {
                Matricula novaMatricula = pedirDadosMatricula(codigoDisciplina);

                int resultadoBusca = cadastrarAlunoDisciplina(novaMatricula);

                if (resultadoBusca > 0)
                {
                    mostrarMensagem("Aluno cadastrado na disciplina com sucesso!");
                    exibirMatricula(novaMatricula);
                    pausarConsole();
                    mostrarMensagem("Para sair digite 0\n Para cadastrar outro aluno");
                }

                else if (resultadoBusca == -1)
                {
                    mostrarMensagem("Lista de matriculas cheia!");
                    pausarConsole();
                }

                else if (resultadoBusca == -2)
                {
                    mostrarMensagem("Matricula cancelada. ");
                    pausarConsole();
                    break;
                }

                else if (resultadoBusca == -3)
                {
                    mostrarMensagem("Aluno já cadastrado nessa disciplina! ");
                    pausarConsole();
                }else if(resultadoBusca == -4){
                    mostrarMensagem("Matricula não existe");
                    pausarConsole();
                }
            }

            break;
        }
        case 2:
        {
            mostrarMensagem(" --- Excluir Aluno de Disciplina --- ");
            int quantidade = obterQtdMatricula();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Matriculas Vazia!\nPrimeiro cadastre um aluno em disciplina.\n");
                pausarConsole();
                break;
            }

            int matriculaExcluir = lerMatricula("a matricula do aluno", 1);
            int codigoExcluir = lerMatricula("o codigo da disciplina", 3);

            int resultadoExclusao = excluirAlunoDisciplina(matriculaExcluir, codigoExcluir);

            if (resultadoExclusao == 1)
            {
                mostrarMensagem("Aluno excluido da disciplina com sucesso!");
            }

            else if (resultadoExclusao == -2)
            {
                mostrarMensagem("Matrícula ou Codigo inválido. ");
            }

            else if (resultadoExclusao == -1)
            {
                mostrarMensagem("Matrícula ou Codigo não encontrado. ");
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
