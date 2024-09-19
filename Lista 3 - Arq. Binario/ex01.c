#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num1, num2, num3, num4, num5;
} numeros;

int main() {

    numeros num;
    FILE *arq;

    arq = fopen("dados.bin", "w+b");
    if (!arq) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    printf("Digite 5 numeros: \n");
    scanf("%d %d %d %d %d", &num.num1, &num.num2, &num.num3, &num.num4, &num.num5);

    fwrite(&num, sizeof(num), 1, arq);

    fclose(arq);
    printf("Numeros gravados com sucesso!\n");

}