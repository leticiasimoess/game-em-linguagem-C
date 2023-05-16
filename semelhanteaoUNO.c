#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h> // Incluindo a biblioteca para a definição de NULL

#define NUM_CARTAS 108
#define NUM_CORES 4
#define NUM_NUMEROS 9
#define NUM_ESPECIAIS 4
#define NUM_ACOES 8

typedef enum { AMARELO, VERMELHO, VERDE, AZUL } Cor;
typedef enum { ZERO, UM, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, MAIS_DOIS, PULAR, INVERTER } Valor;

typedef struct {
    Cor cor;
    Valor valor;
} Carta;

Carta baralho[NUM_CARTAS];
Carta monte[NUM_CARTAS];
Carta maoJogador[7];
Carta maoComputador[7];

int numCartasMonte = 0;
int numCartasJogador = 7;
int numCartasComputador = 7;

void inicializarBaralho() {
    int i, j;
    int index = 0;

    // Cartas numeradas
    for (i = 0; i < NUM_CORES; i++) {
        for (j = 0; j <= NUM_NUMEROS; j++) {
            baralho[index].cor = i;
            baralho[index].valor = j;
            index++;
        }
    }

    // Cartas especiais
    for (i = 0; i < NUM_CORES; i++) {
        for (j = 0; j < NUM_ESPECIAIS; j++) {
            baralho[index].cor = i;
            baralho[index].valor = MAIS_DOIS;
            index++;
            baralho[index].cor = i;
            baralho[index].valor = PULAR;
            index++;
            baralho[index].cor = i;
            baralho[index].valor = INVERTER;
            index++;
        }
    }
}

void embaralharCartas() {
    srand(time(NULL));

    int i, j;
    for (i = 0; i < NUM_CARTAS; i++) {
        j = rand() % NUM_CARTAS;
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuirCartas() {
    int i;
    for (i = 0; i < numCartasJogador; i++) {
        maoJogador[i] = baralho[numCartasMonte];
        numCartasMonte++;
    }

    for (i = 0; i < numCartasComputador; i++) {
        maoComputador[i] = baralho[numCartasMonte];
        numCartasMonte++;
    }
}

void exibirCarta(Carta carta) {
    switch (carta.cor) {
        case AMARELO:
            printf("Amarelo ");
            break;
        case VERMELHO:
            printf("Vermelho ");
            break;
        case VERDE:
            printf("Verde ");
            break;
        case AZUL:
            printf("Azul ");
            break;
    }

    switch (carta.valor) {
        case ZERO:
            printf("0");
            break;
        case UM:
            printf("1");
            break;
        case DOIS:
            printf("2");
            break;
        case TRES:
        printf("3");
break;
case QUATRO:
printf("4");
break;
case CINCO:
printf("5");
break;
case SEIS:
printf("6");
break;
case SETE:
printf("7");
break;
case OITO:
printf("8");
break;
case NOVE:
printf("9");
break;
case MAIS_DOIS:
printf("+2");
break;
case PULAR:
printf("Pular");
break;
case INVERTER:
printf("Inverter");
break;
}
}

void exibirMaoJogador() {
int i;
printf("Sua mao:\n");
for (i = 0; i < numCartasJogador; i++) {
printf("%d - ", i + 1);
exibirCarta(maoJogador[i]);
printf("\n");
}
}

void exibirMonte() {
printf("Carta no topo do monte:\n");
exibirCarta(monte[numCartasMonte - 1]);
printf("\n");
}

int verificarJogada(Carta cartaJogada, Carta cartaMonte) {
return (cartaJogada.cor == cartaMonte.cor || cartaJogada.valor == cartaMonte.valor);
}

void realizarJogada(int indexCartaJogada, int jogador) {
Carta cartaJogada;

if (jogador == 1) {
    cartaJogada = maoJogador[indexCartaJogada];
    maoJogador[indexCartaJogada] = monte[numCartasMonte - 1];
    numCartasJogador--;
} else {
    cartaJogada = maoComputador[indexCartaJogada];
    maoComputador[indexCartaJogada] = monte[numCartasMonte - 1];
    numCartasComputador--;
}

monte[numCartasMonte] = cartaJogada;
numCartasMonte++;
}

void jogadaComputador() {
int i;
for (i = 0; i < numCartasComputador; i++) {
if (verificarJogada(maoComputador[i], monte[numCartasMonte - 1])) {
realizarJogada(i, 2);
printf("O computador jogou a carta:\n");
exibirCarta(monte[numCartasMonte - 1]);
printf("\n");
return;
}
}
printf("O computador comprou uma carta.\n");
maoComputador[numCartasComputador] = baralho[numCartasMonte];
numCartasComputador++;
numCartasMonte++;
}

void iniciarJogo() {
int indexCartaJogada;
int vezJogador = 1;
int fimJogo = 0;
inicializarBaralho();
embaralharCartas();
distribuirCartas();

monte[numCartasMonte] = baralho[numCartasMonte];
numCartasMonte++;

while (!fimJogo) {
    printf("\n----------------------------------\n");
    exibirMonte();
    printf("\n");

    if (vezJogador) {
        exibirMaoJogador();
        printf("Escolha uma carta para jogar: ");
        scanf("%d", &indexCartaJogada);
indexCartaJogada--;
        if (verificarJogada(maoJogador[indexCartaJogada], monte[numCartasMonte - 1])) {
            realizarJogada(indexCartaJogada, 1);
        } else {
            printf("Jogada invalida! Tente novamente.\n");
            continue;
        }
    } else {
        jogadaComputador();
    }

    vezJogador = !vezJogador;

    if (numCartasJogador == 0 || numCartasComputador == 0) {
        fimJogo = 1;
        printf("\n----------------------------------\n");
        printf("Fim de jogo!\n");

        if (numCartasJogador == 0) {
            printf("Voce venceu!\n");
        } else {
            printf("O computador venceu!\n");
        }
    }
}

return 0;
}