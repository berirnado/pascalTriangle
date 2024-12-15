# Triângulo de Pascal

### Bernardo Simões Pires Robaina - M1

## Descrição
Este repositório contém um código em C para resolver o 118º problema do LeetCode, o Triângulo de Pascal. O programa é adaptado para rodar fora do LeetCode, por isso contém também uma seção main, que simula a execução do site, permitindo que o usuário escolha o número de linhas do triângulo e exibe o resultado de forma estruturada a partir de uma função de printf. Este projeto compõe o plano de ensino da disciplina de Algoritmos e Estruturas de Dados I.

## Características do programa

 - Gera o Triângulo de Pascal até o número de linhas especificado pelo usuário.

 - Utiliza alocação dinâmica para construir o triângulo.

 - Libera a memória alocada para evitar vazamentos.

 - Segue a estrutura de função exigida pelo LeetCode para problemas similares.

## Casos teste

### Caso 1
```c
Digite o numero de linhas para o Triangulo de Pascal: 1
1
```

### Caso 2
```c
Digite o numero de linhas para o Triangulo de Pascal: 7
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
```

### Caso 3
```c
Digite o numero de linhas para o Triangulo de Pascal: 0
O número de linhas deve ser maior que 0.
```
