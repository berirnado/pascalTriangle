#include <stdio.h>

void generate(int linhas) {
    int triangulo[linhas][linhas];

    int i, j;
    for ( i = 0; i < linhas; i++ ) {
        for ( j = 0; j <= i; j++ ) {
            if ( j == 0 || j == i ) {
                triangulo[i][j] = 1;
            } else {
                triangulo[i][j] = triangulo[i - 1][j - 1] + triangulo[i - 1][j];
            }
            printf("%d ", triangulo[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas;

    printf("Digite o número de linhas para o Triângulo de Pascal: ");
    scanf("%d", &linhas);

    generate(linhas);

    return 0;
}