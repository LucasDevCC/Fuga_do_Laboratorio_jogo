# Fuga_do_Laboratorio_jogo
Criação de um jogo para a faculdade, jogo simples com facil jogabilidade executado pelo terminal.

# Jogo de aventura e sobrevivência desenvolvido em linguagem C

O jogador está preso em um laboratório e precisa encontrar o caminho correto para escapar.

O jogo é executado diretamente pelo terminal e possui uma interface textual simples e interativa.

---

# Objetivo do Jogo

O objetivo é atravessar **5 salas** e encontrar a saída do laboratório sem perder todos os pontos.

Em cada sala, o jogador precisa escolher uma porta. Apenas uma delas permite avançar, enquanto as demais podem conter armadilhas.

# Como Jogar

Ao executar o programa, será apresentado um menu com três opções:

1. **Iniciar Jogo**  Começa uma nova partida.
2. **Como Jogar**  Exibe as regras e instruções.
3. **Sair** Encerra o programa.

Durante a partida, o jogador deverá digitar o número correspondente à porta que deseja abrir.

# Quantidade de Portas

| Sala | Quantidade de Portas |
|---|---|
| Sala 1 | 4 portas |
| Sala 2 | 4 portas |
| Sala 3 | 5 portas |
| Sala 4 | 5 portas |
| Sala 5 | 6 portas |

As portas corretas são sorteadas aleatoriamente, tornando cada partida diferente.

#  Regras e Mecânicas

O jogador inicia com 15 pontos.

Cada porta correta concede +5 pontos.

Cada porta errada retira 5 pontos.

Ao escolher uma porta errada, uma armadilha aleatória é apresentada.

Portas já testadas são identificadas e não descontam pontos novamente.

O jogador pode digitar 0 para receber uma dica gratuita por sala.

A dica elimina uma porta que contém uma armadilha comum.

Nas salas 4 e 5 existem portas fatais, que encerram a partida imediatamente.

Caso a pontuação chegue a zero, o jogador perde.

O jogador vence ao atravessar todas as cinco salas com pontos restantes.

# Tecnologias Utilizadas

O projeto foi desenvolvido utilizando:

Linguagem C / Desenvolvimento da lógica do jogo.

Visual Studio Code / Editor de código.

GCC / Compilação do programa.

Git e GitHub / Versionamento e armazenamento do projeto.

# Conceitos de Programação Aplicados

Durante o desenvolvimento, foram utilizados conceitos da linguagem C:

Estruturas condicionais: if, else e switch/case para controlar as decisões.

Laços de repetição: for, while e do while para controlar salas, tentativas e menu.

Vetores: armazenamento das armadilhas e controle das portas testadas.

Variáveis: gerenciamento da pontuação e do progresso.

Números aleatórios: utilização de rand() e srand() para sortear portas e armadilhas.

Validação de entradas: tratamento de opções inválidas digitadas pelo jogador.

# Como Executar o Projeto

Pré-requisitos

Windows

Compilador GCC instalado

Terminal ou Visual Studio Code

1. Clonar o repositório

git clone https://github.com/LucasDevCC/Fuga_do_Laboratorio_jogo.git

2. Acessar a pasta

cd Fuga_do_Laboratorio_jogo

3. Compilar o código

gcc main.c -o jogo.exe

4. Executar o jogo

No PowerShell:

.\jogo.exe

Após executar, basta seguir as instruções exibidas no terminal.

# Possíveis Melhorias Futuras

O jogo poderá receber novas funcionalidades, como:

Sistema de dificuldade (fácil, médio e difícil).

Ranking de jogadores e pontuações.

Novos tipos de armadilhas.

Itens especiais para recuperar pontos.

Histórias e desafios diferentes para cada sala.

Organização do código em funções.

Diferentes finais de acordo com o desempenho.

# Objetivo Acadêmico

O projeto foi criado para praticar os conhecimentos adquiridos durante os estudos da linguagem C, principalmente estruturas de controle, laços de repetição, vetores, manipulação de variáveis e lógica de programação.

Além disso, o desenvolvimento proporcionou experiência na identificação e correção de erros, testes de funcionalidades e organização do código-fonte.

