#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nome[50];
    long int firma;
    char sexo;
    int idade;
    char cargo[50];
    float salario;
    int dependentes;
    char instrucao[50];
} dadosfunc;

void incluir_registro(char nome_arquivo[]) {
    FILE *arq;
    dadosfunc funcionario;
    int tam;

    arq = fopen(nome_arquivo, "ab");
    if (!arq) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    getchar();
    printf("Nome: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    tam = strlen(funcionario.nome) - 1;
    if (funcionario.nome[tam] == '\n') {
        funcionario.nome[tam] = '\0';
    }

    printf("Numero da firma: ");
    scanf("%ld", &funcionario.firma);

    printf("Sexo (M | F): ");
    getchar();
    scanf("%c", &funcionario.sexo);
    funcionario.sexo = toupper(funcionario.sexo);

    printf("Idade: ");
    scanf("%d", &funcionario.idade);

    getchar();
    printf("Cargo: ");
    fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
    tam = strlen(funcionario.cargo) - 1;
    if (funcionario.cargo[tam] == '\n') {
        funcionario.cargo[tam] = '\0';
    }

    printf("Salario: R$");
    scanf("%f", &funcionario.salario);

    printf("Numero de dependentes: ");
    scanf("%d", &funcionario.dependentes);

    getchar();
    printf("Grau de Instrucao: ");
    fgets(funcionario.instrucao, sizeof(funcionario.instrucao), stdin);
    tam = strlen(funcionario.instrucao) - 1;
    if (funcionario.instrucao[tam] == '\n') {
        funcionario.instrucao[tam] = '\0';
    }

    fwrite(&funcionario, sizeof(dadosfunc), 1, arq);
    printf("Dados salvos com sucesso!\n");
    fclose(arq);
}

void consultar_registro(char nome_arquivo[]) {
    FILE *arq;
    dadosfunc funcionario;
    
    arq = fopen(nome_arquivo, "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Registros no arquivo:\n\n");
    while (fread(&funcionario, sizeof(dadosfunc), 1, arq)) {
        printf("Nome: %s\n", funcionario.nome);
        printf("Numero da firma: %ld\n", funcionario.firma);
        printf("Sexo: %c\n", funcionario.sexo);
        printf("Idade: %d\n", funcionario.idade);
        printf("Cargo: %s\n", funcionario.cargo);
        printf("Salario: R$%.2f\n", funcionario.salario);
        printf("Numero de dependentes: %d\n", funcionario.dependentes);
        printf("Grau de Instrucao: %s\n\n", funcionario.instrucao);
    }
    fclose(arq);
}

void alterar_registro(char nome_arquivo[]) {
    FILE *arq;
    dadosfunc funcionario;
    long int firma_alterar;
    int encontrado = 0, tam;

    arq = fopen(nome_arquivo, "rb+");
    if (!arq) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Digite o numero da firma do registro a ser alterado: ");
    scanf("%ld", &firma_alterar);

    while (fread(&funcionario, sizeof(dadosfunc), 1, arq)) {
        if (funcionario.firma == firma_alterar) {
            encontrado = 1;
            printf("Registro encontrado. Insira os novos dados:\n");

            getchar();
            printf("Nome: ");
            fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
            
            tam = strlen(funcionario.nome) - 1;
            if (funcionario.nome[tam] == '\n') {
                funcionario.nome[tam] = '\0';
            }

            printf("Sexo (M | F): ");
            getchar();
            scanf("%c", &funcionario.sexo);
            funcionario.sexo = toupper(funcionario.sexo);

            printf("Idade: ");
            scanf("%d", &funcionario.idade);

            getchar();
            printf("Cargo: ");
            fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
            
            tam = strlen(funcionario.cargo) - 1;
            if (funcionario.cargo[tam] == '\n') {
                funcionario.cargo[tam] = '\0';
            }

            printf("Salario: R$");
            scanf("%f", &funcionario.salario);

            printf("Numero de dependentes: ");
            scanf("%d", &funcionario.dependentes);

            getchar();
            printf("Grau de Instrucao: ");
            fgets(funcionario.instrucao, sizeof(funcionario.instrucao), stdin);
            
            tam = strlen(funcionario.instrucao) - 1;
            if (funcionario.instrucao[tam] == '\n') {
                funcionario.instrucao[tam] = '\0';
            }

            fseek(arq, -sizeof(dadosfunc), SEEK_CUR);
            fwrite(&funcionario, sizeof(dadosfunc), 1, arq);
            printf("Registro alterado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Registro nao encontrado.\n");
    }

    fclose(arq);
}

void remover_registro(char nome_arquivo[]) {
    FILE *arq, *arq_temp;
    dadosfunc funcionario;
    long int firma_remover;
    int encontrado = 0;

    arq = fopen(nome_arquivo, "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    arq_temp = fopen("temp.bin", "wb");
    if (!arq_temp) {
        printf("Erro ao criar arquivo temporario!\n");
        fclose(arq);
        return;
    }

    printf("Digite o numero da firma do registro a ser removido: ");
    scanf("%ld", &firma_remover);

    while (fread(&funcionario, sizeof(dadosfunc), 1, arq)) {
        if (funcionario.firma == firma_remover) {
            encontrado = 1;
            printf("Registro removido com sucesso.\n");
        } 
        else 
            fwrite(&funcionario, sizeof(dadosfunc), 1, arq_temp);
    }

    fclose(arq);
    fclose(arq_temp);

    remove(nome_arquivo);
    rename("temp.bin", nome_arquivo);

    if (!encontrado) {
        printf("Registro nao encontrado.\n");
    }
}

int main() {
    char nome_arquivo[50];
    int opcao;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

    do {
        printf("\n--- Menu ---\n");
        printf("1. Incluir registro\n");
        printf("2. Consultar registros\n");
        printf("3. Alterar registro\n");
        printf("4. Remover registro\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluir_registro(nome_arquivo);
                break;
            case 2:
                consultar_registro(nome_arquivo);
                break;
            case 3:
                alterar_registro(nome_arquivo);
                break;
            case 4:
                remover_registro(nome_arquivo);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
