#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char endereco[50];
    char cep[50];
    char telefone[50];
} dados;

void incluir_dados() {
    FILE *arq;
    dados dado;
    int tam;

    arq = fopen("dados.bin", "ab");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    }

    getchar();
    printf("Nome: ");
    fgets(dado.nome, sizeof(dado.nome), stdin);

    tam = strlen(dado.nome) - 1;
    if (dado.nome[tam] == '\n') {
        dado.nome[tam] = '\0';
    }

    printf("Endereco: ");
    fgets(dado.endereco, sizeof(dado.endereco), stdin);

    tam = strlen(dado.endereco) - 1;
    if (dado.nome[tam] == '\n') {
        dado.nome[tam] = '\0';
    }
    
    printf("CEP: ");
    fgets(dado.cep, sizeof(dado.cep), stdin);

    tam = strlen(dado.cep) - 1;
    if (dado.cep[tam] == '\n') {
        dado.cep[tam] = '\0';
    }

    printf("Telefone: ");
    fgets(dado.telefone, sizeof(dado.telefone), stdin);

    tam = strlen(dado.telefone) - 1;
    if (dado.telefone[tam] == '\n') {
        dado.telefone[tam] = '\0';
    }

    fwrite(&dado, sizeof(dados), 1, arq);
    printf("Dados adicionados com sucesso!\n");

    fclose(arq);
}

void listar_arquivo() {
    FILE *arq;
    dados dado;

    arq = fopen("dados.bin", "rb");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo\n");
    }

    printf("Listagem dos registros do arquivo 'dados.bin':\n\n");

    while(fread(&dado, sizeof(dados), 1, arq) == 1) {
        printf("Nome: %s\n", dado.nome);
        printf("Endereco: %s", dado.endereco);
        printf("CEP: %s\n", dado.cep);
        printf("Telefone: %s\n\n", dado.telefone);
    }

    fclose(arq);
}

int main() {
        int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir dados\n");
        printf("2. Listar dados\n");
        printf("3. Sair\n");
        printf("--> ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluir_dados();
                break;
            case 2: 
                listar_arquivo();
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
