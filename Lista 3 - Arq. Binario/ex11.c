#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

int main() {

    FILE *arq;
    Aluno alunos;
    int i = 1;

    arq = fopen("alunos.bin", "rb");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fread(&alunos, sizeof(Aluno), 1, arq) == 1) {
        printf("\nAluno %d\n", i++);
        printf("Nome: %s\n", alunos.nome);
        printf("Idade: %d\n", alunos.idade);
        printf("Nota: %.2f\n", alunos.nota);
    }

    fclose(arq);

    return 0;

}