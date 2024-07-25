# game-em-linguagem-C
Um game em linguagem C. O game pode ser básico, como por exemplo, um jogo da velha, jogo de dama, jogo de xadrez ou até mesmo algo mais completo, como um jogo de cartas.


//JOGO DA VELHA
passo a passo do código:

Inclua a biblioteca stdio.h, que contém funções para entrada e saída de dados, necessária para este programa.
Crie uma função imprimirTabuleiro para imprimir o tabuleiro na tela. Esta função recebe um array bidimensional tabuleiro de caracteres como argumento e imprime o tabuleiro na tela usando um loop for.
Crie uma função verificarVencedor para verificar se há um vencedor no jogo da velha. Esta função recebe um array bidimensional tabuleiro de caracteres como argumento e verifica todas as possibilidades de vitória usando loops for. A função retorna 1 se houver um vencedor e 0 caso contrário.
Na função principal main, crie um array bidimensional tabuleiro de caracteres para representar o tabuleiro e inicialize todas as posições com espaço em branco.
Declare as variáveis necessárias para a função principal, incluindo linha, coluna, jogador, jogadas.
Inicie um loop while para continuar o jogo até que haja um vencedor ou empate.
Dentro do loop while, chame a função imprimirTabuleiro para exibir o tabuleiro atual.
Peça ao jogador atual para digitar a linha e a coluna onde deseja fazer a jogada.
Verifique se a posição escolhida pelo jogador é válida. 
Se não for, exiba uma mensagem de erro e continue para a próxima iteração do loop.
Atualize o tabuleiro na posição escolhida pelo jogador com o caractere do jogador atual e incremente o número de jogadas.
Verifique se há um vencedor chamando a função verificarVencedor. 
Se houver um vencedor, exiba o tabuleiro final, o jogador vencedor e encerre o loop while.
Verifique se é um empate. 
Se todas as 9 jogadas foram feitas e não há um vencedor, exiba o tabuleiro final e uma mensagem de empate. 
Em seguida, encerre o loop while.Retorne 0 para indicar que o programa foi executado com sucesso.

// Esse é um exemplo básico do jogo da velha em C. Ele permite que dois jogadores façam suas jogadas alternadamente até que haja um vencedor ou empate.

//JOGO DE CASRTAS SEMELHANTEDAOUNO

Definições e Declarações Iniciais:
Nessa parte, estão incluídas as bibliotecas necessárias e são definidas constantes e tipos enumerados utilizados no jogo. As constantes representam o número total de cartas, o número de cores, o número de números, o número de cartas especiais e o número total de ações. Os tipos enumerados representam as cores e os valores das cartas.
Declaração das Variáveis Globais:
Nessa parte, são declaradas as variáveis globais do jogo. O array baralho representa o conjunto completo de cartas do jogo. O array monte representa as cartas jogadas e o array maoJogador e maoComputador representam as cartas na mão do jogador e do computador, respectivamente. As variáveis numCartasMonte, numCartasJogador e numCartasComputador armazenam o número atual de cartas no monte, na mão do jogador e na mão do computador, respectivamente.
Inicialização do Baralho:
Essa função inicializarBaralho() preenche o array baralho com todas as cartas do jogo. Primeiro, são adicionadas as cartas numeradas (de 0 a 9) para cada cor. Em seguida, são adicionadas as cartas especiais (Mais Dois, Pular e Inverter) para cada cor.
Embaralhamento do Baralho:
Essa função embaralharCartas() utiliza a função srand() para inicializar a semente do gerador de números aleatórios. Em seguida, ela realiza um loop para percorrer todas as cartas do baralho e trocar cada uma delas com outra carta aleatória.
Distribuição das Cartas:
A função distribuirCartas() distribui as cartas para o jogador e para o computador a partir do baralho. Ela percorre o número de cartas definido para cada jogador (numCartasJogador e numCartasComputador, respectivamente) e atribui a carta correspondente do baralho para a mão de cada jogador, atualizando também o número de cartas no monte.
Exibição de Cartas:
Essa função exibirCarta() recebe uma carta como parâmetro e exibe sua cor e valor na tela. Ela utiliza instruções switch para determinar o texto correspondente à cor e ao valor da carta.
Exibição da Mão do Jogador:
Essa função exibirMaoJogador() é responsável por exibir as cartas presentes na mão do jogador. Ela utiliza um loop para percorrer todas as cartas na mão (numCartasJogador) e utiliza a função exibirCarta() para imprimir a representação de cada carta na tela.
Verificação de Jogada Válida:
Essa função verificarJogada() verifica se uma jogada é válida, comparando a cor ou o valor da cartaJogada com a cartaMonte. Se a cor ou o valor forem iguais, a função retorna 1, indicando uma jogada válida. Caso contrário, retorna 0, indicando uma jogada inválida.
Jogada do Computador:
Essa função jogadaComputador() é responsável por determinar a jogada do computador. Ela percorre as cartas na mão do computador e verifica se alguma delas pode ser jogada com base na carta atualmente no topo do monte. Se encontrar uma carta válida, ela chama a função realizarJogada() para realizar a jogada. Caso contrário, o computador compra uma carta do baralho, adiciona à sua mão e atualiza o número de cartas.

