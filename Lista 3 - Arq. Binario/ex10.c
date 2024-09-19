#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

int main() {

    Aluno alunos;
    FILE *arq;
    int tam;

    arq = fopen("alunos.bin", "w+b");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        printf("\nALUNO %d\n", i+1);

        printf("Nome: ");
        fgets(alunos.nome, sizeof(alunos.nome), stdin);

        tam = strlen(alunos.nome) - 1;
        if (alunos.nome[tam] == '\n') {
            alunos.nome[tam] = '\0';
        }

        printf("Idade: ");
        scanf("%d", &alunos.idade);

        printf("Nota: ");
        scanf("%f", &alunos.nota);

        while(getchar() != '\n');

        fwrite(&alunos, sizeof(Aluno), 1, arq);
    }

    fclose(arq);

    printf("Dados gravados com sucesso!\n");
}