#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
        int **vetorResultado = (int**)malloc(sizeof(int));
        int *linhaAnterior = (int*)malloc(sizeof(int));
        int *novaLinha;
        int i, j;
        for(i = 0; i < numRows; i++){
            // i+1 é o numero de numeros na linha
            int linhaAtual[i+1];
            linhaAtual[0] = 1;
            linhaAtual[i+1] = 1;
            for(j = 1; j < i+1; j++){
                linhaAtual[j] = linhaAnterior[j-1] + linhaAnterior[j];
            }
            //realoca tamanho da linha anterior para caber a linha atual
            linhaAnterior = realloc(linhaAnterior, sizeof(int)*(i+1));
            linhaAnterior = linhaAtual;
        }
        return vetorResultado;
}

int main(){
    printf("Hello World!");
    int* returnSize;
    int** returnColumnSizes;
    int **retorno = generate(5, returnSize, returnColumnSizes);
    return 0;
}
