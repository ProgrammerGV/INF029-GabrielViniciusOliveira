// Gabriel Vinicius Santos de Oliveira | Matricula - 20251160042
#include <stdio.h>
#include <ctype.h>

char grade[3][3];

void inicializar() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            grade[i][j] = ' ';
        }
    }
}

void exibir() {
    printf("\n    1   2   3\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c  ", 'A' + i);
        for(int j = 0; j < 3; j++) {
            printf(" %c ", grade[i][j]);
            if(j < 2) printf("|");
        }
        if(i < 2) printf("\n   ---|---|---\n");
    }
    printf("\n\n");
}

int checarVitoria() {
    for(int i = 0; i < 3; i++) {
        if(grade[i][0] != ' ' && grade[i][0] == grade[i][1] && grade[i][1] == grade[i][2]) return 1;
        if(grade[0][i] != ' ' && grade[0][i] == grade[1][i] && grade[1][i] == grade[2][i]) return 1;
    }
    if(grade[0][0] != ' ' && grade[0][0] == grade[1][1] && grade[1][1] == grade[2][2]) return 1;
    if(grade[0][2] != ' ' && grade[0][2] == grade[1][1] && grade[1][1] == grade[2][0]) return 1;

    return 0;
}

int checarEmpate() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grade[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    int jogadorVez = 1;
    char simbolo;
    char movimento[5];
    int fileira, coluna;
    int jogoEncerrado = 0;

    inicializar();
    printf("=== JOGO DA VELHA ===\n");

    while(!jogoEncerrado) {
        exibir();
        simbolo = (jogadorVez == 1) ? 'X' : '0';

        int movimentoValido = 0;
        while(!movimentoValido) {
            printf("Jogador %d, informe sua jogada (ex: B3): ", jogadorVez);
            scanf("%s", movimento);

            char f = toupper(movimento[0]);
            char c = movimento[1];

            if(f >= 'A' && f <= 'C' && c >= '1' && c <= '3') {
                fileira = f - 'A';
                coluna = c - '1';
                if(grade[fileira][coluna] == ' ') {
                    grade[fileira][coluna] = simbolo;
                    movimentoValido = 1;
                } else {
                    printf("Posicao ja ocupada! Tente novamente.\n");
                }
            } else {
                printf("Coordenada invalida! Use letras de A-C e numeros de 1-3.\n");
            }
        }

        if(checarVitoria()) {
            exibir();
            printf("PARABENS! O Jogador %d venceu!\n", jogadorVez);
            jogoEncerrado = 1;
        } else if(checarEmpate()) {
            exibir();
            printf("O jogo terminou empatado (VELHA)!\n");
            jogoEncerrado = 1;
        } else {
            jogadorVez = (jogadorVez == 1) ? 2 : 1;
        }
    }

    return 0;
}