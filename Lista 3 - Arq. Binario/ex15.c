#include <stdio.h>

typedef struct {
    char nome[50];
    float salario;
} reg;

int main() {
    reg registro;
    FILE *arq1, *arq2;

    arq1 = fopen("fonte.bin", "rb");
    if (!arq1) {
        printf("Houve um erro ao abrir o arquivo de origem.\n");
        return 1;
    }

    arq2 = fopen("novo.bin", "wb");
    if (!arq2) {
        printf("Houve um erro ao abrir o arquivo de destino.\n");
        fclose(arq1);
        return 1;
    }

    while (fread(&registro, sizeof(reg), 1, arq1) == 1) {
        fwrite(&registro, sizeof(reg), 1, arq2);
    }

    fclose(arq1);
    fclose(arq2);

    printf("Copia concluida com sucesso.\n");
    
    return 0;
}
