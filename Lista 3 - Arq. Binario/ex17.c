#include <stdio.h>

typedef struct {
    int numero;
    int pecas;
} registro;

int main() {
    FILE *fonte, *arq1, *arq2, *arq3;
    registro registro;

    fonte = fopen("producao.bin", "rb");
    if (!fonte) {
        printf("Houve um erro ao abrir o arquivo.\n");
        return 1;
    }

    arq1 = fopen("maquina1.bin", "wb");
    arq2 = fopen("maquina2.bin", "wb");
    arq3 = fopen("maquina3.bin", "wb");

    if (!arq1 || !arq2 || !arq3) {
        printf("Erro ao abrir arquivos das maquinas.\n");
        fclose(fonte);
        return 1;
    }

    while (fread(&registro, sizeof(registro), 1, fonte) == 1) {
        switch (registro.numero) {
            case 1:
                fwrite(&registro, sizeof(registro), 1, arq1);
                break;
            case 2:
                fwrite(&registro, sizeof(registro), 1, arq2);
                break;
            case 3:
                fwrite(&registro, sizeof(registro), 1, arq3);
                break;
            default:
                printf("Numero de maquina desconhecido: %d\n", registro.numero);
                break;
        }
    }

    fclose(fonte);
    fclose(arq1);
    fclose(arq2);
    fclose(arq3);

    printf("Registros separados com sucesso!\n");
    
    return 0;
}
