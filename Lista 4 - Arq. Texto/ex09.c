#include <stdio.h>
#include <string.h>

int main() {
    FILE *arq;
    char nome[50];
    int tam, m, n, mat[10][10];

    printf("Digite o nome do arquivo: ");
    fgets(nome, sizeof(nome), stdin);

    tam = strlen(nome) - 1;
    if (nome[tam] == '\n') {
        nome[tam] = '\0';
    }

    arq = fopen(nome, "r");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo.\n");
    }

    fscanf(arq, "%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            fscanf(arq, "%d", &mat[i][j]);
        }
    }

    fclose(arq);

    printf("Matriz lida do arquivo:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}