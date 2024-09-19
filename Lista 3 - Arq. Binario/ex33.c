#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tipo[20];
    float valor;
    float quilometragem;
    float litros;
} Registro;

void adicionar_registro() {
    FILE *arq;
    Registro reg;

    arq = fopen("carro.bin", "ab");
    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o tipo de evento (Manutencao, Combustivel, Lavagem, etc.): ");
    scanf("%s", reg.tipo);
    printf("Digite o valor gasto: ");
    scanf("%f", &reg.valor);
    printf("Digite a quilometragem: ");
    scanf("%f", &reg.quilometragem);

    if (strcmp(reg.tipo, "Combustivel") == 0) {
        printf("Digite a quantidade de litros abastecida: ");
        scanf("%f", &reg.litros);
    } 
    else
        reg.litros = 0;

    fwrite(&reg, sizeof(Registro), 1, arq);
    fclose(arq);
    printf("Registro adicionado com sucesso!\n");
}

void listar_registros() {
    FILE *arq;
    Registro reg;
    
    arq = fopen("carro.bin", "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Relatorio de Eventos:\n");
    printf("------------------------------------------------------------\n");
    while (fread(&reg, sizeof(Registro), 1, arq)) {
        printf("Tipo: %s | Valor: %.2f | Quilometragem: %.2f", reg.tipo, reg.valor, reg.quilometragem);
        if (strcmp(reg.tipo, "Combustivel") == 0) {
            printf(" | Litros: %.2f", reg.litros);
        }
        printf("\n");
    }
    fclose(arq);
}

void custoPorKm() {
    FILE *arq;
    float km_inicial = 0, km_final = 0, custo_total = 0;
    int primeiro_registro = 1;
    Registro reg;
    
    arq = fopen("carro.bin", "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fread(&reg, sizeof(Registro), 1, arq)) {
        custo_total += reg.valor;
        if (primeiro_registro) {
            km_inicial = reg.quilometragem;
            primeiro_registro = 0;
        }
        km_final = reg.quilometragem;
    }

    if (km_final > km_inicial) {
        printf("Custo total por quilometro: %.2f\n", custo_total / (km_final - km_inicial));
    } else {
        printf("Dados insuficientes para calcular custo por quilometro.\n");
    }

    fclose(arq);
}

void consumo_medio() {
    FILE *arq;
    float km_inicial = 0, km_final = 0, litros_total = 0;
    int primeiro_registro = 1;
    Registro reg;
    
    arq = fopen("carro.bin", "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fread(&reg, sizeof(Registro), 1, arq)) {
        if (strcmp(reg.tipo, "Combustivel") == 0) {
            litros_total += reg.litros;
            if (primeiro_registro) {
                km_inicial = reg.quilometragem;
                primeiro_registro = 0;
            }
            km_final = reg.quilometragem;
        }
    }

    if (km_final > km_inicial && litros_total > 0) {
        printf("Consumo medio: %.2f km/l\n", (km_final - km_inicial) / litros_total);
    } 
    else
        printf("Dados insuficientes para calcular consumo medio.\n");

    fclose(arq);
}

int main() {
    int opcao;

    do {
        printf("\nControle de Carro:\n");
        printf("1. Adicionar registro\n");
        printf("2. Listar registros\n");
        printf("3. Calcular custo por quilometro\n");
        printf("4. Calcular consumo medio\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_registro();
                break;
            case 2:
                listar_registros();
                break;
            case 3:
                custoPorKm();
                break;
            case 4:
                consumo_medio();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } 
    while (opcao != 5);

    return 0;
}
