#ifndef MATRICULA_MODEL_H
#define MATRICULA_MODEL_H
#define TAM_MATRICULA 1000

typedef struct matricula
{
    int matriculaAluno;
    int codigoDisciplina;
    int ativo;
}Matricula;


int cadastrarAlunoDisciplina(Matricula novaMatricula);
int excluirAlunoDisciplina(int matriculaAluno, int codigoDisciplina);
int obterQtdMatricula();
Matricula *listarMatricula();
void excluirTodasMatriculasAluno(int matriculaAluno);

#endif