#include <stdio.h>
#include <string.h>

struct banda {
    char nome[100];
    char tipo[100];
    int integrantes;
    int ranking;
};

typedef struct banda banda;

void cadastroBanda(banda bandas[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("BANDA %d\n", i + 1);
        printf("Nome da banda: ");
        fflush(stdin);
        fgets(bandas[i].nome, sizeof(bandas[i].nome), stdin);

        printf("Tipo musical: ");
        fflush(stdin); 
        fgets(bandas[i].tipo, sizeof(bandas[i].tipo), stdin);

        printf("Quantidade de integrantes: ");
        scanf("%d", &bandas[i].integrantes);

        printf("Ranking da banda (0 se nao estiver no ranking): ");
        scanf("%d", &bandas[i].ranking);
    }
}

void rankingBanda(banda bandas[], int ranking, int qtd) {
    for (int i = 0; i < qtd; i++) {
        if (bandas[i].ranking == ranking) {
            printf("\nBANDA %d\n", i + 1);
            printf("Nome da Banda: %s", bandas[i].nome);
            printf("Tipo musical: %s", bandas[i].tipo);
            printf("Quantidade de integrantes: %d\n", bandas[i].integrantes);
            printf("Ranking da banda: %d\n\n", bandas[i].ranking);
        }
    }
}

void tipoBanda(banda bandas[], char tipo[], int qtd) {
    printf("Bandas com tipo musical: %s\n", tipo);
    for (int i = 0; i < qtd; i++) {
        if (strcmp(tipo, bandas[i].tipo) == 0) {
            printf("\nBANDA %d\n", i + 1);
            printf("Nome da Banda: %s", bandas[i].nome);
            printf("Tipo musical: %s", bandas[i].tipo);
            printf("Quantidade de integrantes: %d\n", bandas[i].integrantes);
            printf("Ranking da banda: %d\n", bandas[i].ranking);
        }
    }
}

void buscaBandaPorNome(banda bandas[], char nome[], int qtd) {
    int encontrada = 0;
    for (int i = 0; i < qtd; i++) {
        if (strcmp(nome, bandas[i].nome) == 0) {
            encontrada = 1;
            if (bandas[i].ranking > 0 && bandas[i].ranking <= 5) {
                printf("A banda %s esta entre as suas favoritas no ranking %d.\n", bandas[i].nome, bandas[i].ranking);
            } else {
                printf("A banda %s nao esta entre as suas favoritas.\n", bandas[i].nome);
            }
            break;
        }
    }
    if (!encontrada) {
        printf("\nBanda nao encontrada.\n\n");
    }
}

void menu() {
    printf("Menu de Opcoes:\n");
    printf("1. Cadastrar Bandas\n");
    printf("2. Buscar Banda por Ranking\n");
    printf("3. Buscar Bandas por Tipo Musical\n");
    printf("4. Verificar se Banda eh Favorita\n");
    printf("5. Sair\n");
}

int main() {
    int qtd, opcao, ranking;
    banda bandas[20];
    char tipo[100], nome[100];

    while (1) {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantas bandas deseja cadastrar? (max 20): ");
                scanf("%d", &qtd);
                if (qtd > 20) {
                    printf("Quantidade maior que 20. Digite novamente: ");
                    scanf("%d", &qtd);
                }
                cadastroBanda(bandas, qtd);
                break;
            case 2:
                printf("Informe o ranking da banda que deseja buscar: ");
                scanf("%d", &ranking);
                rankingBanda(bandas, ranking, qtd);
                break;
            case 3:
                printf("Informe o tipo musical: ");
                fflush(stdin); 
                fgets(tipo, sizeof(tipo), stdin);
                tipoBanda(bandas, tipo, qtd);
                break;
            case 4:
                printf("Informe o nome da banda: ");
                fflush(stdin); 
                fgets(nome, sizeof(nome), stdin); 
                buscaBandaPorNome(bandas, nome, qtd);
                break;
            case 5:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
}
