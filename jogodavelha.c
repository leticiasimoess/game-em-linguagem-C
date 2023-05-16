#include <stdio.h>

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n--- Tabuleiro ---\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Função para verificar se há um vencedor
int verificarVencedor(char tabuleiro[3][3]) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]) {
            return 1;
        }
    }
    
    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i]) {
            return 1;
        }
    }
    
    // Verificar diagonais
    if ((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]) ||
        (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0])) {
        return 1;
    }
    
    return 0;
}

// Função principal
int main() {
    char tabuleiro[3][3] = { {' ', ' ', ' '},
                             {' ', ' ', ' '},
                             {' ', ' ', ' '} };
    int linha, coluna;
    char jogador = 'X';
    int jogadas = 0;
    
    while (1) {
        imprimirTabuleiro(tabuleiro);
        
        // Alternar jogadores
        if (jogador == 'X') {
            jogador = 'O';
        } else {
            jogador = 'X';
        }
        
        printf("Jogador %c, digite a linha e a coluna: ", jogador);
        scanf("%d %d", &linha, &coluna);
        
        // Verificar se a posição está válida
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Posição inválida! Tente novamente.\n");
            continue;
        }
        
        // Atualizar tabuleiro
        tabuleiro[linha][coluna] = jogador;
        jogadas++;
        
        // Verificar se há um vencedor
        if (verificarVencedor(tabuleiro)) {
            imprimirTabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", jogador);
            break;
        }
        
        // Verificar se é empate
        if (jogadas == 9) {
            imprimirTabuleiro(tabuleiro);
printf("Empate!\n");
break;
}
}
return 0;
}
