#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int idade;
    float altura;
} Pessoa;

int main() {

    FILE *arq;
    Pessoa pessoas;

    arq = fopen("pessoas.bin", "w+b");
    if (!arq) {
        printf("Houve um erro ao abrir/criar o arquivo\n");
        exit(1);
    }

    for (int i = 0; i < 4; i++) {
        printf("\nPessoa %d\n", i+1);
        printf("Nome: ");
        getchar();
        fgets(pessoas.nome, sizeof(pessoas.nome), stdin);
        printf("Idade: ");
        scanf(" %d", &pessoas.idade);
        printf("Altura: ");
        scanf("%f", &pessoas.altura);

        fwrite(&pessoas, sizeof(pessoas), 1, arq);
    }

    fclose(arq);
    printf("Informacoes salvas com sucesso!\n");

}