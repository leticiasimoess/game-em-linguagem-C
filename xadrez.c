#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 8

// Peças de xadrez
#define VAZIO 0
#define PEAO_BRANCO 1
#define PEAO_PRETO 2
#define TORRE_BRANCA 3
#define TORRE_PRETA 4
#define CAVALO_BRANCO 5
#define CAVALO_PRETO 6
#define BISPO_BRANCO 7
#define BISPO_PRETO 8
#define RAINHA_BRANCA 9
#define RAINHA_PRETA 10
#define REI_BRANCO 11
#define REI_PRETO 12

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int i, j;

    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {
        {TORRE_PRETA, CAVALO_PRETO, BISPO_PRETO, RAINHA_PRETA, REI_PRETO, BISPO_PRETO, CAVALO_PRETO, TORRE_PRETA},
        {PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO},
        {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
        {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
        {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
        {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO},
        {PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO},
        {TORRE_BRANCA, CAVALO_BRANCO, BISPO_BRANCO, RAINHA_BRANCA, REI_BRANCO, BISPO_BRANCO, CAVALO_BRANCO, TORRE_BRANCA}
    };

    exibirTabuleiro(tabuleiro);

    return 0;
}
