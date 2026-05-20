// Gabriel Vinicius Santos de Oliveira | Matricula - 20251160042
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int quantidade_embarcacoes = 5;
int comprimento_embarcacoes[] = {4, 3, 1, 1, 1};

char grade1[10][10];
char grade2[10][10];
char disparos1[10][10];
char disparos2[10][10];

void prepararGrades() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            grade1[i][j] = ' ';
            grade2[i][j] = ' ';
            disparos1[i][j] = ' ';
            disparos2[i][j] = ' ';
        }
    }
}

void mostrarGrade(char grade[10][10], int ocultarEmbarcacoes) {
    printf("\n    0  1  2  3  4  5  6  7  8  9\n");
    for(int i = 0; i < 10; i++) {
        printf(" %c ", 'A' + i);
        for(int j = 0; j < 10; j++) {
            char quadrado = grade[i][j];
            if(ocultarEmbarcacoes && quadrado == 'N') {
                printf("[ ]");
            } else {
                printf("[%c]", quadrado);
            }
        }
        printf("\n");
    }
}

int inserirEmbarcacao(char grade[10][10], int comprimento, int participante) {
    char fileiraChr;
    int fileira, posicao;
    char sentido;

    printf("\nParticipante %d, posicione uma embarcacao de comprimento %d.\n", participante, comprimento);

    while(1) {
        printf("Digite a fileira (A-J), posicao (0-9) e sentido (H/V) ex: A 5 H: ");
        scanf(" %c %d %c", &fileiraChr, &posicao, &sentido);

        fileira = toupper(fileiraChr) - 'A';
        sentido = toupper(sentido);

        if(fileira < 0 || fileira > 9 || posicao < 0 || posicao > 9 || (sentido != 'H' && sentido != 'V')) {
            printf("Entrada invalida! Tente novamente.\n");
            continue;
        }

        if(sentido == 'H' && posicao + comprimento > 10) {
            printf("A embarcacao ultrapassa o limite horizontal da grade.\n");
            continue;
        }
        if(sentido == 'V' && fileira + comprimento > 10) {
            printf("A embarcacao ultrapassa o limite vertical da grade.\n");
            continue;
        }

        int sobreposicao = 0;
        for(int i = 0; i < comprimento; i++) {
            if(sentido == 'H' && grade[fileira][posicao + i] == 'N') sobreposicao = 1;
            if(sentido == 'V' && grade[fileira + i][posicao] == 'N') sobreposicao = 1;
        }

        if(sobreposicao) {
            printf("Posicao ja ocupada por outra embarcacao!\n");
            continue;
        }

        for(int i = 0; i < comprimento; i++) {
            if(sentido == 'H') grade[fileira][posicao + i] = 'N';
            if(sentido == 'V') grade[fileira + i][posicao] = 'N';
        }
        break;
    }
    return 1;
}

void configurarParticipante(char grade[10][10], int participante) {
    printf("\n=== CONFIGURACAO DO PARTICIPANTE %d ===\n", participante);
    for(int i = 0; i < quantidade_embarcacoes; i++) {
        mostrarGrade(grade, 0);
        inserirEmbarcacao(grade, comprimento_embarcacoes[i], participante);
    }
    mostrarGrade(grade, 0);
    printf("\nConfiguracao concluida. Pressione Enter para limpar a tela...");
    getchar(); getchar();
    for(int i = 0; i < 50; i++) printf("\n");
}

int checarVitoria(char grade[10][10]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(grade[i][j] == 'N') return 0;
        }
    }
    return 1;
}

int main() {
    prepararGrades();

    configurarParticipante(grade1, 1);
    configurarParticipante(grade2, 2);

    int vez = 1;
    int encerrado = 0;

    while(!encerrado) {
        printf("\n===================================\n");
        printf("Vez do Participante %d\n", vez);

        char (*minhaGrade)[10] = (vez == 1) ? grade1 : grade2;
        char (*gradeAdversario)[10] = (vez == 1) ? grade2 : grade1;
        char (*meusDisparos)[10] = (vez == 1) ? disparos1 : disparos2;

        printf("\n--- MINHA GRADE ---\n");
        mostrarGrade(minhaGrade, 0);

        printf("\n--- GRADE DO ADVERSARIO (MEUS DISPAROS) ---\n");
        mostrarGrade(meusDisparos, 1);

        int disparoValido = 0;
        while(!disparoValido) {
            char fileiraChr;
            int posicao;
            printf("\nInforme a coordenada para disparar (ex: C 4): ");
            scanf(" %c %d", &fileiraChr, &posicao);

            int fileira = toupper(fileiraChr) - 'A';

            if(fileira < 0 || fileira > 9 || posicao < 0 || posicao > 9) {
                printf("Coordenada fora do mapa!\n");
                continue;
            }

            if(meusDisparos[fileira][posicao] != ' ') {
                printf("Voce ja disparou nessa posicao!\n");
                continue;
            }

            if(gradeAdversario[fileira][posicao] == 'N') {
                printf("=> DISPARO CERTEIRO! Voce acertou uma embarcacao!\n");
                gradeAdversario[fileira][posicao] = '0';
                meusDisparos[fileira][posicao] = '0';
            } else {
                printf("=> AGUA! Disparo na posicao errada.\n");
                gradeAdversario[fileira][posicao] = 'X';
                meusDisparos[fileira][posicao] = 'X';
            }
            disparoValido = 1;
        }

        if(checarVitoria(gradeAdversario)) {
            printf("\nPARABENS! O Participante %d afundou toda a frota adversaria e VENCEU!\n", vez);
            encerrado = 1;
        } else {
            vez = (vez == 1) ? 2 : 1;
        }
    }

    return 0;
}