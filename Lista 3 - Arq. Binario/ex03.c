#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num1, num2, num3, num4, num5;
} numeros;

int main() {
FILE *arq;
    numeros num;
    int encontrado = 0;
    int num_alterado;

    arq = fopen("dados.bin", "wb");
    if(!arq) {
        printf("Houve um erro ao abrir o arquivo\n");
        return;
    }

    printf("Digite o numero que deseja alterar: ");
    scanf("%d", &num_alterado);

    while (fread(&num, sizeof(numeros), 1, arq)) {
        if (num.num3 == num_alterado) {
            encontrado = 1;
            printf("Registro encontrado. Insira o novo numero:\n");

            printf("Numero 3: ");
            scanf("%d", &num.num3);
            
            
            fseek(arq, -sizeof(numeros), SEEK_CUR);
            fwrite(&num, sizeof(numeros), 1, arq);
            printf("Registro alterado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Registro nao encontrado.\n");
    }

    fclose(arq);
}