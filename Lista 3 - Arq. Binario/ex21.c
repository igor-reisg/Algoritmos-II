#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    long int conta;
    char nome[50];
    float saldo;
} dados;

void incluir_conta() {
    FILE *arq;
    dados dado;
    int tam;

    arq = fopen("clientes.bin", "ab");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    }

    printf("Numero da conta: ");
    scanf("%ld", &dado.conta);
    getchar(); 

    printf("Nome do cliente: ");
    fgets(dado.nome, sizeof(dado.nome), stdin);

    tam = strlen(dado.nome) - 1;
    if (dado.nome[tam] == '\n') {
        dado.nome[tam] = '\0';
    }
    
    printf("Saldo do cliente: R$");
    scanf("%f", &dado.saldo);

    fwrite(&dado, sizeof(dados), 1, arq);
    printf("Dados do cliente adicionados com sucesso!\n");

    fclose(arq);
}

void consultar_conta() {
    FILE *arq;
    long int num;
    int encontrado = 0;
    dados dado;

    arq = fopen("clientes.bin", "rb");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo ou arquivo inexistente.\n");
        return;
    }

    printf("Informe o numero da conta: ");
    scanf("%ld", &num);

    while (fread(&dado, sizeof(dados), 1, arq)) {
        if (num == dado.conta) {
            printf("Numero da conta: %ld\nNome: %s\nSaldo: R$%.2f\n", dado.conta, dado.nome, dado.saldo);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Conta nao encontrada.\n");
    }

    fclose(arq);
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir contas\n");
        printf("2. Consultar conta\n");
        printf("3. Sair\n");
        printf("--> ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluir_conta();
                break;
            case 2: 
                consultar_conta();
                break;
            case 3:
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
