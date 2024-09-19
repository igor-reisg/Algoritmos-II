#include <stdio.h>
#include <string.h>

int main() {
    FILE *arq1, *arq2, *arq3;
    char nome1[50], nome2[50], texto[500];
    int tam;

    printf("Digite o nome do arquivo 1: ");
    fgets(nome1, sizeof(nome1), stdin);

    tam = strlen(nome1) - 1;
    if (nome1[tam] == '\n') {
        nome1[tam] = '\0';
    }

    printf("Digite o nome do arquivo 2: ");
    fgets(nome2, sizeof(nome2), stdin);

    tam = strlen(nome2) - 1;
    if (nome2[tam] == '\n') {
        nome2[tam] = '\0';
    }

    arq1 = fopen(nome1, "r");
    arq2 = fopen(nome2, "r");
    arq3 = fopen("junto.txt", "w");

    if (!arq1 || !arq2) {
        printf("Houve um erro ao abrir os arquivos.\n");
    }

    while(fgets(texto, sizeof(texto), arq1) != NULL) {
        fputs(texto, arq3);
    }
    fputs("\n", arq3);

    while(fgets(texto, sizeof(texto), arq2) != NULL) {
        fputs(texto, arq3);
    }

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);

    printf("Os arquivos '%s' e '%s' foram juntados em 'junto.txt' com sucesso!\n", nome1, nome2);
}