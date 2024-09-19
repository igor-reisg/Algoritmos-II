#include <stdio.h>
#include <string.h>

int main() {
    char nome[50];
    FILE *arq;
    int tam;
    char ch;

    printf("Digite o nome do arquivo que deseja criar: ");
    fgets(nome, sizeof(nome), stdin);

    tam = strlen(nome) - 1;
    if (nome[tam] == '\n') {
        nome[tam] = '\0';
    }

    arq = fopen(nome, "r");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo.\n");
    }

    while((ch = getc(arq)) != EOF) {
        printf("%c", ch);
    }

    fclose(arq);
}