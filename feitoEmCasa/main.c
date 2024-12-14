#include <stdio.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Definindo o tamanho do retorno
    *returnSize = numRows;

    // Aloca memória para armazenar o número de colunas de cada linha
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    // Aloca memória para numRows ponteiros, cada ponteiro aponta para uma linha do triangulo
    int** triangle = (int**)malloc(numRows * sizeof(int*));

    int i, j;
    for (i = 0; i < numRows; i++) {
        // Gera o tamanho da linha atual com base no index da linha
        *returnColumnSizes[i] = i + 1;

        //Aloca memória para a linha atual do triangulo
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));

        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                // O primeiro e ultimo numero de cada linha sao 1
                triangle[i][j] = 1;
            } else {
                // Gera o numero da linha a partir da soma dos numeros da linha anterior
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }

    return triangle;
}

int main() {
    int numRows;

    printf("Digite o número de linhas para o Triângulo de Pascal: ");
    scanf("%d", &numRows);

    int returnSize;
    int* returnColumnSizes;
    generate(numRows, &returnSize, &returnColumnSizes);

    return 0;
}