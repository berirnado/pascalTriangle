#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    if(numRows <= 0){
        printf("O número de linhas deve ser maior que 0.\n");
        return NULL;
    }
    // Definindo o tamanho do retorno
    *returnSize = numRows;

    // Aloca memória para armazenar o número de colunas de cada linha
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    // Aloca memória para numRows ponteiros, cada ponteiro aponta para uma linha do triangulo
    int** triangle = (int**)malloc(numRows * sizeof(int*));

    int i, j;
    for (i = 0; i < numRows; i++) {
        // Gera o tamanho da linha atual com base no index da linha
        (*returnColumnSizes)[i] = i + 1;

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

void PrintTriangle(int** triangle, int numRows, int* returnColumnSizes) {
    int i, j;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

void FreeTriangle(int** triangle, int numRows, int* returnColumnSizes){
    int i;
    // Liberar a memória das linhas do triângulo
    for (i = 0; i < numRows; i++) {
        free(triangle[i]);
    }
    // Liberar a memória do ponteiro das linhas
    free(triangle);
    // Liberar a memória dos tamanhos das colunas
    free(returnColumnSizes);
}


int main() {
    int numRows;

    printf("Digite o numero de linhas para o Triangulo de Pascal: ");
    scanf("%d", &numRows);

    int returnSize;
    int* returnColumnSizes;
    int** triangle = generate(numRows, &returnSize, &returnColumnSizes);
    PrintTriangle(triangle, numRows, returnColumnSizes);

    FreeTriangle(triangle, numRows, returnColumnSizes);

    return 0;
}