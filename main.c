
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8"); // serve pra corrigir e conseguir colocar pontuação sem dar erro no texto

    // variaveis do jogo como pontos,opção do menu, escolha de portas, salas, portas corretas e fatais, armadilhas, dicas e derrota fatal
    int opcao = 0;
    int pontos = 15;
    int escolha;
    int passou = 0;
    int portaCorreta;
    int sala;
    int quantidadePortas;
    int portaFatal;
    // aqui é um vetor para armazenar as portas testadas, onde 0 significa não testada, 1 significa testada e 2 significa eliminada pela dica
    int portasTestadas[7] = {0};
    int dicaUsada;
    int portaDica;
    int armadilhaSorteada;
    int caractere;
    int derrotaFatal;

    // aqui um vetor de 10 strings que armazenam as armadilhas que podem acontecer ao escolher uma porta errada
    char *armadilhas[10] = {
        "Um gás de origem duvidosa comecou a sair das paredes, é melhor não acender um fósforo.",
        "Você recebeu um choque eletrico na maçaneta, você ficou chocado.",
        "Ao girar a macaneta a porta solta uma cola em sua mao, por sorte sua mao nao grudou na porta.",
        "A porta esquentou a 200 graus e queimou sua mao! Eu diria que Merthiolate nao vai resolver isso. ",
        "A porta se soltou e caiu no seu pe, seu pe fica parecendo um tapete.",
        "Um extintor caiu do teto e caiu na sua cabeça. Pelo menos agora voce esta preparado para um incendio.",
        "Voce abriu a porta e recebeu um balde de agua gelada. Parabens, seu banho do dia esta garantido.",
        "Voce abriu a porta e recebeu uma chuva de farinha. Agora so falta o ovo para virar um bolo.",
        "Ao abrir a porta uma maquina despejou chantily em voce. Parabens, voce virou um cappuccino ambulante.",
        "Ao abrir a porta uma descarga eletrica atravessou seu corpo. Parabens, voce acaba de virar um carregador portatil."
    };

    // aqui é a função srand que gera numeros aleatorios ao iniciar o programa.
    srand(time(NULL));

    // aqui é o do while que faz o menu do jogo funcionar, onde o usuario pode escolher entre iniciar o jogo, ver as regras ou sair do jogo.
    do {
        printf("\n////////////////////////////////\n");
        printf("       FUGA DO LABORATORIO\n");
        printf("////////////////////////////////\n");

        printf("\n1 / Iniciar jogo");
        printf("\n2 / Como jogar");
        printf("\n3 / Sair");

        printf("\n\nEscolha uma opção: ");

     // aqui é a função scanf que lê a opção escolhida pelo usuario, e caso o usuario digite algo que não seja um numero, ele recebe uma mensagem de erro e o programa continua.   
        if (scanf("%d", &opcao) != 1) {
            if (feof(stdin)) {
                break;
            }

            printf("\nDigite apenas números!\n");

        // aqui é a função getchar que limpa o buffer do teclado, para que o usuario possa digitar novamente.    
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }

            opcao = 0;
            continue;
        }
        // escolhe qual bloco executar de acordo com a opção desejada
        switch (opcao) {
            // aqui é o case 1 que inicia o jogo, onde o usuario começa com 15 pontos e deve passar pelas 5 salas do laboratório, escolhendo portas e evitando armadilhas.
            case 1:
                pontos = 15;
                derrotaFatal = 0;

                printf("\nVocê está preso no laboratório!\n");
                printf("Passe pelas 5 salas para escapar.\n");
                printf("Pontuação inicial: %d\n", pontos);
            // aqui é o for que percorre as 5 salas do laboratório, onde cada sala possui uma quantidade diferente de portas, e a partir da sala 4 existe uma porta fatal que encerra o jogo imediatamente.
                for (sala = 1; sala <= 5; sala++) {
                    if (sala <= 2) {
                        quantidadePortas = 4;
                    }
                    else if (sala <= 4) {
                        quantidadePortas = 5;
                    }
                    else {
                        quantidadePortas = 6;
                    }

                    passou = 0;
                    dicaUsada = 0;
                // o for percorre todo o vetor e zera as marcações da sala anterior, para que o jogador possa testar as portas novamente na nova sala.
                    for (int i = 0; i < 7; i++) {
                        portasTestadas[i] = 0;
                    }
                // aqui sorteia a porta correta entre 1 e quantidade de portas.
                    portaCorreta = rand() % quantidadePortas + 1;

                    portaFatal = 0;
                // aqui ativa a porta fatal a partir da sala 4, sorteando uma porta aleatoria que não seja a porta correta.    
                    if (sala >= 4) {
                        do {
                            portaFatal = rand() % quantidadePortas + 1;
                        } while (portaFatal == portaCorreta);
                    }

                    while (pontos > 0 && passou == 0) {
                        printf("\n/// SALA %d ///\n", sala);
                        printf("Pontuação: %d\n", pontos);

                        for (int i = 1; i <= quantidadePortas; i++) {
                            if (portasTestadas[i] == 1) {
                                printf("%d - Porta %d (JÁ TESTADA)\n", i, i);
                            }
                            else if (portasTestadas[i] == 2) {
                                printf("%d - Porta %d (ELIMINADA PELA DICA)\n", i, i);
                            }
                            else {
                                printf("%d - Porta %d\n", i, i);
                            }
                        }
                    // a dica só aparece enquanto não foi usada, e o jogador pode escolher a porta 0 para receber a dica gratuita.        
                        if (dicaUsada == 0) {
                            printf("\nDigite 0 para receber uma dica gratuita.\n");
                        }

                        printf("\nEscolha uma porta: ");
                    // só para impedir que letras seja digitadas, se digitar letras é avisado para digitar apenas numeros e o programa continua.
                        if (scanf("%d", &escolha) != 1) {
                            if (feof(stdin)) {
                                printf("\nEntrada encerrada.\n");
                                pontos = 0;
                                break;
                            }

                            printf("Digite apenas numeros!\n");

                            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                            }

                            continue;
                        }
                    // Escolher 0 solicita uma dica ao inves de escolher uma porta. Só pode solicitar uma vez a dica
                        if (escolha == 0) {
                            if (dicaUsada == 1) {
                                printf("\nVocê já usou sua dica nesta sala!\n");
                            }
                            else {
                        // o for percorre todas as portas e verifica se existe portas comuns para eliminar.
                                int portasDisponiveis = 0;
                            // aqui as condições precisam ser verdadeiras para que a porta seja considerada comum e não tenha sido testada ainda.
                                for (int i = 1; i <= quantidadePortas; i++) {
                                    if (i != portaCorreta &&
                                        i != portaFatal &&
                                        portasTestadas[i] == 0) {
                                        portasDisponiveis++;
                                    }
                                }
                                // se não tiver portas para eliminar o jogador é avisado.
                                if (portasDisponiveis == 0) {
                                    printf("\nNão existem mais portas comuns para eliminar!\n");
                                }
                                else {
                                    // serve para sortear uma porta para a dica, o while rejeita portas proibidas como a porta correta, a porta fatal e portas já testadas.
                                    do {
                                        portaDica = rand() % quantidadePortas + 1;
                                    } while (portaDica == portaCorreta ||
                                             portaDica == portaFatal ||
                                             portasTestadas[portaDica] != 0);
                                    // marca a porta sorteada como eliminada e registra a dica como ja usada.
                                    portasTestadas[portaDica] = 2;
                                    dicaUsada = 1;

                                    printf("\nDICA: A porta %d possui uma armadilha periglitante!\n", portaDica);
                                    printf("Evite escolher essa porta para evitar a fadiga.\n");
                                }
                            }

                            continue;
                        }
                        // serve para evitar que o jogador escolha uma porta inexistente.
                        if (escolha < 1 || escolha > quantidadePortas) {
                            printf("\nEssa porta não existe!\n");
                        }
                        // serve para evitar que o jogador escolha uma porta já testada.
                        else if (portasTestadas[escolha] != 0) {
                            printf("\nTo querendo te ajudar, para de teimosia!\n");
                            printf("Escolha outra porta e evite a fadiga.\n");
                        }
                        // se acertar ganha os pontos e segue pra proxima sala
                        else if (escolha == portaCorreta) {
                            printf("\nAcertou em cheio! Você ganhou 5 pontos e seguiu adiante!\n");
                            pontos += 5;
                            passou = 1;
                        }
                        // a porta fatal serve para encerrar o jogo imediatamente, e o jogador perde todos os pontos.
                        else if (escolha == portaFatal) {
                            printf("\n////////////////////////////////\n");
                            printf("          PORTA FATAL!\n");
                            printf("////////////////////////////////\n");

                            printf("\nOH NAO! assim que entrou na sala você ouve a porta trancar, as portas do outro lado da sala nao tem maçanetas.\n");
                            printf("Você ouve passos e um alarme ensurdecedor e percebe que...\n");
                            printf("Estão vindo te pegar.\n");

                            printf("\nFIM DE JOGO!\n");

                            derrotaFatal = 1;
                            pontos = 0;
                        }
                        else {
                            // se errar perde os pontos e recebe uma armadilha aleatoria, que é sorteada no vetor de armadilhas.
                            portasTestadas[escolha] = 1;
                            // essa função serve para sortear uma armadilha aleatoria.
                            armadilhaSorteada = rand() % 10;

                            printf("\nARMADILHA!\n");
                            printf("%s\n", armadilhas[armadilhaSorteada]);

                            pontos -= 5;

                            printf("Voce perdeu 5 pontos!\n");
                        }

                        printf("Pontuação atual: %d\n", pontos);
                    }
                    // aqui é quando o jogador chega a 0 pontos e encerra o jogo.
                    if (pontos <= 0) {
                        if (derrotaFatal == 0) {
                            printf("\nFIM DO JOGO! Seus pontos acabaram.\n");
                        }
                        break;
                    }

                    printf("\nVocê passou pela sala %d!\n", sala);
                }
                // aqui é quando o jogador consegue passar por todas as salas e vence o jogo, mostrando a pontuação final.
                if (pontos > 0) {
                    printf("\n////////////////////////////////\n");
                    printf("       VOCE CONSEGUIU ESCAPAR!\n");
                    printf("////////////////////////////////\n");
                    printf("Pontuação final: %d\n", pontos);
                }

                break;
            // aqui o case 2 que serve para mostrar as regras do jogo.
            case 2:
                printf("\n////////////////////////////////\n");
                printf("           COMO JOGAR\n");
                printf("////////////////////////////////\n");

                printf("\nObjetivo do jogo: escapar do laboratório!\n");

                printf("\nREGRAS DO JOGO:\n");
                printf("1 - Você começa com 15 pontos.\n");
                printf("2 - O laboratório possui 5 salas.\n");
                printf("3 - As salas possuem 4,5 e 6 portas.\n");
                printf("4 - Apenas uma porta é a correta em cada sala.\n");
                printf("5 - A porta correta é aleatória e muda a cada partida.\n");
                printf("6 - Cada erro faz perder 5 pontos.\n");
                printf("7 - Cada acerto concede 5 pontos.\n");
                printf("8 - Digite 0 para receber uma dica por sala.\n");
                printf("9 - Portas já selecionadas não retiram pontos novamente.\n");
                printf("10 - A partir da sala 4 existe uma porta fatal.\n");
                printf("11 - A porta fatal encerra a partida imediatamente.\n");
                printf("12 - Se chegar a 0 pontos acaba o jogo.\n");
                printf("13 - Passe pelas 5 salas para vencer.\n");

                printf("\nBoa sorte!\n");
                break;
            // aqui o case 3 que serve para encerrar o jogo.
            case 3:
                printf("\nSaindo do jogo...\n");
                break;
            // serve para avisar quando a opção não é valida, voltando para o menu principal.
            default:
                printf("\nOpção inválida!\n");
                break;
        }

    } while (opcao != 3);

    printf("\nJogo fechado.\n");

    return 0;
}
