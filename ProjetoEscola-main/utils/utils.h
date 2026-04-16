#ifndef UTILS_H
#define UTILS_H
#include "data_model.h"

void mostrarMensagem(const char *mensagem);
void limparConsole();
int verificarCPF(const char *cpf);
void lerCPF(char *destino);
void lerNome(char *destino);
char lerSexo(char destino);
int verificarSexo(const char sexo);
void lerDataNascimento(Data *dataNascimento);
int verificarData(int d, int m, int a);
void pausarConsole();
int menuPessoa(const char *tipoPessoa);
int lerMatricula(const char *mensagem, int tipo);
int verificarMatricula(const int matricula, const int tipo);
int lerMatriculaWhile(const char *mensagem, int tipo);
int lerOpcao(int limite);
int verificarOpcao(int opcao, int limite);
void converterParaMaiusculo(char *str);

#endif