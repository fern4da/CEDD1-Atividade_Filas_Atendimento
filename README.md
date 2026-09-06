# Sistema de Gerenciamento de Atendimento (Projeto Filas e Atendimento)

Este projeto consiste em um sistema de simulação de atendimento em linha de comando desenvolvido em C++ para a disciplina de Estrutura de Dados 1, no curso de Tecnologia em Análise e Desenvolvimento de Sistemas do IFSP - Campus Cubatão.

O objetivo do programa é gerenciar o fluxo de senhas de clientes utilizando o conceito de Filas (FIFO - First-In, First-Out), onde o primeiro cliente a chegar é o primeiro a ser atendido. A solução foi desenhada utilizando uma abordagem de Fila Circular baseada em vetor estático para otimização de memória.

## Tecnologias Utilizadas

* Linguagem: C++
* Paradigma: Programação Estruturada e Orientada a Objetos (POO)
* Estruturas de Dados: Fila Sequencial Circular (Vetor com aritmética modular)
* Ambiente: Console Application

## Lógica e Regras de Negócio Implementadas

O sistema reproduz com fidelidade as regras de um painel de atendimento real:
* Gerenciamento de Estado: Exibe dinamicamente o total de senhas na fila de espera antes de cada ação do usuário.
* Fila Circular Otimizada: Utiliza o operador de resto da divisão (`% TAM`) para reaproveitar os índices iniciais do vetor quando elementos são removidos, evitando o deslocamento massivo de dados na memória e estouro de índice de forma desnecessária.
* Ciclo de Vida do Atendimento: Move as entidades de forma sequencial entre duas estruturas controladas: a fila de triagem inicial (`senhasGeradas`) e a fila de histórico de conclusão (`senhasAtendidas`).
* Trava de Segurança de Desligamento: Impede o encerramento do sistema caso ainda existam usuários aguardando atendimento na fila, garantindo a integridade do processo de negócios estabelecido.

## Estrutura do Código

* Fila: Classe responsável por encapsular toda a lógica estrutural da fila circular. Controla as variáveis de posicionamento (`inicio` e `fim`), o contador de elementos internos e expõe os métodos de controle padrão como `enfileirar`, `desenfileirar`, `vazia` e `cheia`.
* main: Gerencia a interface de texto, captura os comandos inseridos via console e coordena a interação contínua entre as filas de geração e recepção de chamadas.

## Como Executar o Projeto

1. Clone o repositório:
   ```bash
   git clone https://github.com
   ```
2. Certifique-se de ter um compilador C++ instalado (como GCC/G++).
3. Compile o arquivo principal:
   ```bash
   g++ main.cpp -o atendimento
   ```
4. Execute o binário gerado:
   ```bash
   ./atendimento
   ```
