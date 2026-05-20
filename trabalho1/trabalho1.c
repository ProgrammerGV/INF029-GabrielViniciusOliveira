// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Gabriel Vinicius Santos de Oliveira
//  email: 20251160042@ifba.edu.br
//  Matrícula: 20251160042
//  Semestre: 2026.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################


#include <stdio.h>
#include "trabalho1.h"
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char string_data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int valor1, int valor2)
{
    int resultado_soma;
    resultado_soma = valor1 + valor2;
    return resultado_soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int numero)
{ // função utilizada para testes
    int iterador, resultado_fat = 1;

    for (iterador = numero; iterador > 1; iterador--)
        resultado_fat = resultado_fat * iterador;

    return resultado_fat;
}

int teste(int parametro)
{
    int retorno_teste;
    if (parametro == 2)
        retorno_teste = 3;
    else
        retorno_teste = 4;

    return retorno_teste;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char string_data[])
{
    int status_data = 1;

    // quebrar a string data em strings sDia, sMes, sAno
    int dias_no_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    DataQuebrada data_estruturada;

    data_estruturada = quebraData(string_data);

    if (data_estruturada.valido == 1)
    {
        if (data_estruturada.iMes < 1 || data_estruturada.iMes > 12)
        {
            return 0;
        }
        if (data_estruturada.iMes == 2)
        {
            int e_bissexto = (data_estruturada.iAno % 4 == 0 && (data_estruturada.iAno % 100 != 0 || data_estruturada.iAno % 400 == 0));
            if (e_bissexto)
            {
                dias_no_mes[1] = 29;
                if (data_estruturada.iDia > 29)
                {
                    return 0;
                }
            }
            else
            {
                if (data_estruturada.iDia > 28)
                {
                    return 0;
                }
            }
        }
        if (data_estruturada.iDia < 1 || data_estruturada.iDia > dias_no_mes[data_estruturada.iMes - 1])
        {
            return 0;
        }
        return 1;
    }
    return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
int inverterData(DataQuebrada obj_data)
{
    int formato_int = 0;
    formato_int = (obj_data.iAno * 10000) + (obj_data.iMes * 100) + obj_data.iDia;

    return formato_int;
}

DiasMesesAnos q2(char dt_inicio[], char dt_fim[])
{

    // calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos resultado_dma;
    resultado_dma.qtdAnos = 0;
    resultado_dma.qtdMeses = 0;
    resultado_dma.qtdMeses = 0;

    if (q1(dt_inicio) == 0)
    {
        resultado_dma.retorno = 2;
        return resultado_dma;
    }
    else if (q1(dt_fim) == 0)
    {
        resultado_dma.retorno = 3;
        return resultado_dma;
    }
    else
    {
        // verifique se a data final não é menor que a data inicial
        DataQuebrada fim_quebrada = quebraData(dt_fim);
        int fim_inteiro = inverterData(fim_quebrada);
        DataQuebrada inicio_quebrada = quebraData(dt_inicio);
        int inicio_inteiro = inverterData(inicio_quebrada);

        if (inicio_inteiro > fim_inteiro)
        {
            resultado_dma.retorno = 4;
            return resultado_dma;
        }
        // calcule a distancia entre as datas
        int limites_meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (inicio_quebrada.iDia <= fim_quebrada.iDia)
        {
            resultado_dma.qtdDias = fim_quebrada.iDia - inicio_quebrada.iDia;
        }
        else
        {
            int mes_passado = fim_quebrada.iMes - 1;

            if (mes_passado == 0)
            {
                mes_passado = 12;
                fim_quebrada.iAno = fim_quebrada.iAno - 1;
            }

            int adicao_dias = limites_meses[mes_passado - 1];
            if (mes_passado == 2)
            {

                int check_bissexto = (fim_quebrada.iAno % 4 == 0 && (fim_quebrada.iAno % 100 != 0 || fim_quebrada.iAno % 400 == 0));
                if (check_bissexto)
                {
                    adicao_dias = 29;
                }
            }

            fim_quebrada.iDia = fim_quebrada.iDia + adicao_dias;
            fim_quebrada.iMes = mes_passado;

            resultado_dma.qtdDias = fim_quebrada.iDia - inicio_quebrada.iDia;
        }

        if (inicio_quebrada.iMes <= fim_quebrada.iMes)
        {
            resultado_dma.qtdMeses = fim_quebrada.iMes - inicio_quebrada.iMes;
        }
        else
        {
            fim_quebrada.iAno = fim_quebrada.iAno - 1;
            fim_quebrada.iMes = fim_quebrada.iMes + 12;

            resultado_dma.qtdMeses = fim_quebrada.iMes - inicio_quebrada.iMes;
        }

        resultado_dma.qtdAnos = fim_quebrada.iAno - inicio_quebrada.iAno;

        // se tudo der certo
        resultado_dma.retorno = 1;
        return resultado_dma;
    }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

int q3(char *texto_alvo, char letra, int sensivel_caixa)
{
    int total_achado = 0;

    while (*texto_alvo != '\0')
    {
        if (sensivel_caixa == 1)
        {
            if (*texto_alvo == letra)
            {
                total_achado++;
            }
        }
        else
        {
            if (*texto_alvo == letra || *texto_alvo == letra + 32 || *texto_alvo == letra - 32)
            {
                total_achado++;
            }
        }
        texto_alvo++;
    }
    return total_achado;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *frase_base, char *termo_pesquisa, int indices_resultado[30])
{
    int total_ocorrencias = 0;
    int indice_array = 0;
    int comp_busca = strlen(termo_pesquisa);
    int comp_char_busca = 0;

    for (int idx_b = 0; termo_pesquisa[idx_b] != '\0'; idx_b++)
    {
        if ((termo_pesquisa[idx_b] & 0xC0) != 0x80)
        {
            comp_char_busca++;
        }
    }

    int posicao_atual_char = 0;

    for (int idx_t = 0; frase_base[idx_t] != '\0'; idx_t++)
    {
        if ((frase_base[idx_t] & 0xC0) != 0x80)
            posicao_atual_char++;

        int contagem_match = 0;
        for (int idx_match = 0; termo_pesquisa[idx_match] != '\0'; idx_match++)
        {
            if (frase_base[idx_t + idx_match] == termo_pesquisa[idx_match])
            {
                contagem_match++;
            }
            else
                break;
        }

        if (contagem_match == comp_busca)
        {
            indices_resultado[indice_array] = posicao_atual_char;
            indice_array++;
            indices_resultado[indice_array] = posicao_atual_char + comp_char_busca - 1;
            indice_array++;
            total_ocorrencias++;
        }
    }

    return total_ocorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int valor_original)
{
    int valor_espelhado = 0;
    int digito_temporario = 0;
    for (int iter = 0; valor_original != 0; iter++)
    {
        digito_temporario = valor_original % 10;
        valor_original = valor_original / 10;
        valor_espelhado = (valor_espelhado * 10) + digito_temporario;
    }
    return valor_espelhado;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int num_principal, int num_alvo)
{
    int repeticoes_encontradas = 0;
    int resto_comparacao = 0;

    int fator_base = 1;
    int temp_alvo = num_alvo;

    while (temp_alvo != 0)
    {
        fator_base = fator_base * 10;
        temp_alvo = temp_alvo / 10;
    }

    while (num_principal != 0)
    {
        resto_comparacao = num_principal % fator_base;
        if (resto_comparacao == num_alvo)
        {
            repeticoes_encontradas++;
        }
        num_principal = num_principal / 10;
    }

    return repeticoes_encontradas;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char grade_letras[8][10], char string_alvo[5])
{
    int status_encontrado = 0; 
    int tamanho_alvo = strlen(string_alvo);

    for (int lin = 0; lin < 8; lin++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (grade_letras[lin][col] == string_alvo[0])
            {
               
                int dir_direita = 1; 
                for (int passo = 0; passo < tamanho_alvo; passo++) {
                    if ((col + passo) >= 10 || grade_letras[lin][col + passo] != string_alvo[passo]) {
                        dir_direita = 0; 
                        break;
                    }
                }
                if (dir_direita == 1) status_encontrado = 1;


                int dir_esquerda = 1;
                for (int passo = 0; passo < tamanho_alvo; passo++) {
                    if ((col - passo) < 0 || grade_letras[lin][col - passo] != string_alvo[passo]) {
                        dir_esquerda = 0;
                        break;
                    }
                }
                if (dir_esquerda == 1) status_encontrado = 1;


                int dir_baixo = 1;
                for (int passo = 0; passo < tamanho_alvo; passo++) {
                    if ((lin + passo) >= 8 || grade_letras[lin + passo][col] != string_alvo[passo]) {
                        dir_baixo = 0;
                        break;
                    }
                }
                if (dir_baixo == 1) status_encontrado = 1;


                int dir_cima = 1;
                for (int passo = 0; passo < tamanho_alvo; passo++) {
                    if ((lin - passo) < 0 || grade_letras[lin - passo][col] != string_alvo[passo]) {
                        dir_cima = 0;
                        break;
                    }
                }
                if (dir_cima == 1) status_encontrado = 1;

                int diagonal_inf_dir = 1;
                for (int passo = 0; passo < tamanho_alvo; passo++) {
                    if ((lin + passo) >= 8 || (col + passo) >= 10 || grade_letras[lin + passo][col + passo] != string_alvo[passo]) {
                        diagonal_inf_dir = 0;
                        break;
                    }
                }
                if (diagonal_inf_dir == 1) status_encontrado = 1;

                int diagonal_inf_esq = 1;
                for (int passo = 0; passo < tamanho_alvo; passo++) {
                    if ((lin + passo) >= 8 || (col - passo) < 0 || grade_letras[lin + passo][col - passo] != string_alvo[passo]) {
                        diagonal_inf_esq = 0;
                        break;
                    }
                }
                if (diagonal_inf_esq == 1) status_encontrado = 1;


      
                int diagonal_sup_dir = 1;
                for (int passo = 0; passo < tamanho_alvo; passo++) {
                    if ((lin - passo) < 0 || (col + passo) >= 10 || grade_letras[lin - passo][col + passo] != string_alvo[passo]) {
                        diagonal_sup_dir = 0;
                        break;
                    }
                }
                if (diagonal_sup_dir == 1) status_encontrado = 1;


          
                int diagonal_sup_esq = 1;
                for (int passo = 0; passo < tamanho_alvo; passo++) {
                    if ((lin - passo) < 0 || (col - passo) < 0 || grade_letras[lin - passo][col - passo] != string_alvo[passo]) {
                        diagonal_sup_esq = 0;
                        break;
                    }
                }
                if (diagonal_sup_esq == 1) status_encontrado = 1;

            }
        }
    }

    return status_encontrado;
}


DataQuebrada quebraData(char str_data_entrada[])
{
    DataQuebrada obj_quebrado;
    char texto_dia[3];
    char texto_mes[3];
    char texto_ano[5];
    int idx_percurso;

    for (idx_percurso = 0; str_data_entrada[idx_percurso] != '/'; idx_percurso++)
    {
        texto_dia[idx_percurso] = str_data_entrada[idx_percurso];
    }
    if (idx_percurso == 1 || idx_percurso == 2)
    {                   // testa se tem 1 ou dois digitos
        texto_dia[idx_percurso] = '\0'; // coloca o barra zero no final
    }
    else
    {
        obj_quebrado.valido = 0;
        return obj_quebrado;
    }

    int idx_aux = idx_percurso + 1; // anda 1 cada para pular a barra
    idx_percurso = 0;

    for (; str_data_entrada[idx_aux] != '/'; idx_aux++)
    {
        texto_mes[idx_percurso] = str_data_entrada[idx_aux];
        idx_percurso++;
    }

    if (idx_percurso == 1 || idx_percurso == 2)
    {                   // testa se tem 1 ou dois digitos
        texto_mes[idx_percurso] = '\0'; // coloca o barra zero no final
    }
    else
    {
        obj_quebrado.valido = 0;
        return obj_quebrado;
    }

    idx_aux = idx_aux + 1; // anda 1 cada para pular a barra
    idx_percurso = 0;

    for (; str_data_entrada[idx_aux] != '\0'; idx_aux++)
    {
        texto_ano[idx_percurso] = str_data_entrada[idx_aux];
        idx_percurso++;
    }

    if (idx_percurso == 2 || idx_percurso == 4)
    {                   // testa se tem 2 ou 4 digitos
        texto_ano[idx_percurso] = '\0'; // coloca o barra zero no final
    }
    else
    {
        obj_quebrado.valido = 0;
        return obj_quebrado;
    }

    obj_quebrado.iDia = atoi(texto_dia);
    obj_quebrado.iMes = atoi(texto_mes);
    obj_quebrado.iAno = atoi(texto_ano);

    obj_quebrado.valido = 1;

    return obj_quebrado;
}


