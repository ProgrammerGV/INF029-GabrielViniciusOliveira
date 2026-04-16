#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "professor_model.h"
#include "aluno_model.h"
#include "disciplina_model.h"

void mostrarMensagem(const char *mensagem)
{
    printf("%s\n", mensagem);
}

int verificarCPF(const char *cpf)
{
    if (strlen(cpf) != 11)
    {
        return 0; 
    }

    for (int i = 0; i < 11; i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9')
        {
            return 0;
        }
    }

    int qtdAluno = obterQtdAlunos();
    int qtdProfessor = obterQtdProfessor();
    Professor *listaProfessor = listarProfessor();
    Aluno *listaAluno = listarAlunos();

    for (int i = 0; i < qtdAluno; i++)
    {
        if (strcmp(listaAluno[i].cpf, cpf) == 0 && listaAluno[i].ativo == 1)
        {
            return -1;
        }
    }
    for (int i = 0; i < qtdProfessor; i++)
    {
        if (strcmp(listaProfessor[i].cpf, cpf) == 0 && listaProfessor[i].ativo == 1)
        {
            return -2;
        }
    }

    int somaCPF1 = 0;
    for (int j = 0; j < 9; j++)
    {
        somaCPF1 += (cpf[j] - '0') * (10 - j);
    }

    int moduloCPF1 = somaCPF1 % 11;
    int primeiroVerificador = (moduloCPF1 < 2) ? 0 : 11 - moduloCPF1;

    int somaCPF2 = 0;
    for (int j = 0; j < 10; j++)
    {
        somaCPF2 += (cpf[j] - '0') * (11 - j);
    }

    int moduloCPF2 = somaCPF2 % 11;
    int segundoVerificador = (moduloCPF2 < 2) ? 0 : 11 - moduloCPF2;

    if (primeiroVerificador == (cpf[9] - '0') && segundoVerificador == (cpf[10] - '0'))
    {
        return 1;  
    }
    return 0;
}

void lerCPF(char *destino)
{
    while (1)
    {
        printf("Digite 0 para sair.\nDigite o CPF (apenas numeros):");
        scanf("%16s", destino);
        getchar();
        if (!strcmp(destino, "0"))
        {
            break;
        }
        int resultado = verificarCPF(destino);
        if (resultado == 1)
        {
            break;
        }
        else if (resultado == -1)
        {
            printf("CPF existente em Aluno\n");
        }
        else if (resultado == -2)
        {
            printf("CPF existente em Professor\n");
        }
        else
        {
            printf("CPF invalido.\n");
        }
    }
}

void lerNome(char *destino)
{
    printf("Digite o nome: ");
    scanf(" %100[^\n]", destino);
    getchar();
}

int verificarSexo(const char sexo)
{

    if (sexo == 'M' || sexo == 'F' || sexo == 'm' || sexo == 'f')
    {
        return 1;
    }
    return 0;
}

char lerSexo(char destino)
{
    while (1)
    {
        printf("Digite 0 para sair.\nDigite seu sexo (M/F): ");
        scanf(" %c", &destino);
        if (destino == '0')
        {
            break;
        }

        if (verificarSexo(destino))
        {
            return destino;
            break;
        }
        else
        {
            printf("Sexo invalido!\n");
        }
    }
    return '0';
}

int verificarData(int d, int m, int a)
{
    if (a < 1900 || a > 2026)
        return 0; 
    if (m < 1 || m > 12)
        return 0;
    if (d < 1 || d > 31)
        return 0;

    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return 0;

    if (m == 2)
    {
        int bissexto = (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
        if (bissexto)
        {
            if (d > 29)
                return 0;
        }
        else
        {
            if (d > 28)
                return 0;
        }
    }

    return 1;
}

void lerDataNascimento(Data *dataNascimento)
{
    while (1)
    {
        printf("Digite 0 para sair.\nDigite o dia de nascimento: ");
        scanf("%d", &dataNascimento->dia);

        printf("Digite 0 para sair.\nDigite o mêS de nascimento: ");
        scanf("%d", &dataNascimento->mes);

        printf("Digite 0 para sair.\nDigite o ano de nascimento: ");
        scanf("%d", &dataNascimento->ano);
        if (dataNascimento->dia == 0 || dataNascimento->mes == 0 || dataNascimento->ano == 0)
        {
            break;
        }
        if (verificarData(dataNascimento->dia, dataNascimento->mes, dataNascimento->ano))
        {
            break; 
        }
        else
        {
            printf("Data invalida! Tente novamente.\n");
        }
    }
}

void limparConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausarConsole()
{
    system("pause");
}

int menuPessoa(const char *tipoPessoa)
{
    limparConsole();
    printf("---- Modulo %s ----\n", tipoPessoa);
    printf("\n0 - Voltar ao menu Principal \n");
    printf("1 - Cadastrar %s\n", tipoPessoa);
    printf("2 - Listar %s\n", tipoPessoa);
    printf("3 - Atualizar %s\n", tipoPessoa);
    printf("4 - Excluir %s\n", tipoPessoa);
    printf("5 - Relatorios %s\n", tipoPessoa);

    return lerOpcao(5);
}

int lerMatricula(const char *mensagem, int tipo)
{
    limparConsole();
    int matricula;
    printf("\nDigite %s: ", mensagem);
    scanf("%d", &matricula);
    return matricula;
}

int lerMatriculaWhile(const char *mensagem, int tipo)
{
    while (1)
    {
        int matricula;
        printf("Digite 0 para sair.\nDigite %s: ", mensagem);
        scanf("%d", &matricula);
        if (matricula == 0)
        {
            break;
        }
        if (verificarMatricula(matricula, tipo) == 1)
        {
            return matricula;
        }
        else
        {
            printf("%s não existe! Tente novamente.\n", mensagem);
            pausarConsole();
            limparConsole();
        }
    }
    return 0;
}

int verificarMatricula(const int matricula, const int tipo)
{
    int qtd;

    if (tipo == 1)
    {
        Aluno *lista = listarAlunos();
        qtd = obterQtdAlunos();
        for (int i = 0; i < qtd; i++)
        {
            if (matricula == lista[i].matricula && lista[i].ativo == 1)
            {
                return 1; 
            }
        }
    }
    else if (tipo == 2)
    {
        Professor *lista = listarProfessor();
        qtd = obterQtdProfessor();
        for (int i = 0; i < qtd; i++)
        {
            if (matricula == lista[i].matricula && lista[i].ativo == 1)
            {
                return 1; 
            }
        }
    }
    else if (tipo == 3) 
    {
        Disciplina *lista = listarDisciplina();
        qtd = obterQtdDisciplina();
        for (int i = 0; i < qtd; i++)
        {
            if (matricula == lista[i].codigo && lista[i].ativo == 1)
            {
                return 1; 
            }
        }
    }
    return 0;
}

int lerOpcao(int limite)
{
    int opcao;
    while (1)
    {
        scanf("%d", &opcao);
        getchar();

        if (verificarOpcao(opcao, limite) == 1)
        {
            return opcao;
        }
        else
        {
            mostrarMensagem("Opção invalida! Digite novamente: ");
        }
    }
}

int verificarOpcao(int opcao, int limite)
{
    if (opcao >= 0 && opcao <= limite)
    {
        return 1;
    }
    return 0;
}

void converterParaMaiusculo(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}