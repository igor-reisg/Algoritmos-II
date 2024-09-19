#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *arq1, *arq2;
    int num;

    arq1 = fopen("teste.bin", "r+b");
    if (!arq1) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    arq2 = fopen("novo.bin", "w+b");
    if (!arq2) {
        printf("Houve um erro ao abrir o arquivo");
        exit(1);
    }

    while (fread(&num, sizeof(int), 1, arq1) == 1) {
        if (num != 0) {
            fwrite(&num, sizeof(int), 1, arq2);
        }
    }

    fclose(arq1);
    fclose(arq2);

    printf("Operacao feita com sucesso!\n");
}