#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int dia, mes, ano;
} dt;

typedef struct {
    long int conta;
    char nome[50];
    float saldo;
    dt data;
} dados;

void cadastro() {
    FILE *arq;
    dados dados1;
    char cadastro;
    int tam;

    arq = fopen("dadosbancarios.bin", "ab");  
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    }

    printf("CADASTRO DE CLIENTES\n");

    do {
        printf("Numero da conta: ");
        scanf("%ld", &dados1.conta);
        getchar(); 

        printf("Nome do cliente: ");
        fgets(dados1.nome, sizeof(dados1.nome), stdin);

        tam = strlen(dados1.nome) - 1;
        if (dados1.nome[tam] == '\n') {
            dados1.nome[tam] = '\0';
        }

        printf("Saldo: R$");
        scanf("%f", &dados1.saldo);

        printf("Data da ultima operacao (XX/XX/XXXX): ");
        scanf("%d/%d/%d", &dados1.data.dia, &dados1.data.mes, &dados1.data.ano);

        fwrite(&dados1, sizeof(dados), 1, arq);

        printf("Deseja cadastrar outro cliente? (S/N) ");
        getchar(); 
        cadastro = getchar();
        getchar();  

    } while(toupper(cadastro) == 'S');

    fclose(arq);
    
    printf("Clientes cadastrados com sucesso!\n");
}

void consulta() {
    FILE *arq;
    dados dados1;
    int i = 1;

    arq = fopen("dadosbancarios.bin", "rb");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    }

    while(fread(&dados1, sizeof(dados), 1, arq) == 1) {
        printf("\nCLIENTE %d\n", i++);
        printf("Numero da conta: %ld\n", dados1.conta);
        printf("Nome do cliente: %s\n", dados1.nome);
        printf("Saldo: R$%.2f\n", dados1.saldo);
        printf("Data da ultima operacao: %2d/%2d/%4d\n", dados1.data.dia, dados1.data.mes, dados1.data.ano);
    }

    fclose(arq);
}

int main() {
    int opcao;

    do {
        printf("\nCADASTRAMENTO DE CLIENTES\n");
        printf("1. Realizar cadastro\n");
        printf("2. Consultar cadastros existentes\n");
        printf("3. Sair\n");
        printf("--> ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastro();
                break;
            case 2: 
                consulta();
                break;
            case 3:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
