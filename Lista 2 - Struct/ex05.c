#include <stdio.h>
#include <string.h>

struct nascimento {
    int dia;
    int mes;
    int ano;
};

struct endereco {
    char rua[50];
    char cidade[20];
    char estado[20];
    long int cep;
};

typedef struct nascimento nascimento;
typedef struct endereco endereco;

struct cadastro {
    char nome[50];
    nascimento data;
    long int rg;
    char sexo;
    endereco local;
    long int ra;
    float cr;
};

typedef struct cadastro cadastro;

void menu(int *opcao) {
    printf("Escolha uma das seguintes opcoes:\n");
    printf("1. Inserir novo aluno\n");
    printf("2. Ordenar o cadastro por nome em ordem alfabetica\n");
    printf("3. Ordenar o cadastro por CR, maiores primeiro\n");
    printf("4. Ler o valor de um RA e imprimir os dados do aluno no cadastro com mesmo RA\n");
    printf("5. Imprimir o cadastro na ordem atual\n");

    scanf("%d", opcao);
}

void inserir(cadastro cd[], int *count) {
    if (*count >= 100) {
        printf("Cadastro cheio. Nao eh possivel adicionar mais alunos.\n");
        return;
    }
    printf("Insira o nome: ");
    scanf(" %s", cd[*count].nome);
    printf("Insira a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &cd[*count].data.dia, &cd[*count].data.mes, &cd[*count].data.ano);
    printf("Insira o RG: ");
    scanf("%ld", &cd[*count].rg);
    printf("Insira o sexo (M/F): ");
    scanf(" %c", &cd[*count].sexo);
    printf("Insira o endereco (rua, cidade, estado, CEP): ");
    scanf(" %s", cd[*count].local.rua);
    scanf(" %s", cd[*count].local.cidade);
    scanf(" %s", cd[*count].local.estado);
    scanf("%ld", &cd[*count].local.cep);
    printf("Insira o RA: ");
    scanf("%ld", &cd[*count].ra);
    printf("Insira o CR: ");
    scanf("%f", &cd[*count].cr);
    (*count)++;
}

void ordenar_por_nome(cadastro cd[], int count) {
    cadastro temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(cd[i].nome, cd[j].nome) > 0) {
                temp = cd[i];
                cd[i] = cd[j];
                cd[j] = temp;
            }
        }
    }
}

void ordenar_por_cr(cadastro cd[], int count) {
    cadastro temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (cd[i].cr < cd[j].cr) {
                temp = cd[i];
                cd[i] = cd[j];
                cd[j] = temp;
            }
        }
    }
}

void imprimir_por_ra(cadastro cd[], int count, long int ra) {
    for (int i = 0; i < count; i++) {
        if (cd[i].ra == ra) {
            printf("Nome: %s\n", cd[i].nome);
            printf("Data de Nascimento: %02d/%02d/%04d\n", cd[i].data.dia, cd[i].data.mes, cd[i].data.ano);
            printf("RG: %ld\n", cd[i].rg);
            printf("Sexo: %c\n", cd[i].sexo);
            printf("Endereco: %s, %s, %s, CEP: %ld\n", cd[i].local.rua, cd[i].local.cidade, cd[i].local.estado, cd[i].local.cep);
            printf("RA: %ld\n", cd[i].ra);
            printf("CR: %.2f\n", cd[i].cr);
            return;
        }
    }
    printf("RA nao encontrado!\n");
}

void imprimir_todos(cadastro cd[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Nome: %s\n", cd[i].nome);
        printf("Data de Nascimento: %02d/%02d/%04d\n", cd[i].data.dia, cd[i].data.mes, cd[i].data.ano);
        printf("RG: %ld\n", cd[i].rg);
        printf("Sexo: %c\n", cd[i].sexo);
        printf("Endereco: %s, %s, %s, CEP: %ld\n", cd[i].local.rua, cd[i].local.cidade, cd[i].local.estado, cd[i].local.cep);
        printf("RA: %ld\n", cd[i].ra);
        printf("CR: %.2f\n", cd[i].cr);
        printf("----------------------------\n");
    }
}

int main () {
    cadastro cd[100];
    int sair = 0, opcao, count = 0;

    do {
        menu(&opcao);
        switch(opcao) {
            case 1:
                inserir(cd, &count);
                break;
            case 2:
                ordenar_por_nome(cd, count);
                break;
            case 3:
                ordenar_por_cr(cd, count);
                break;
            case 4: {
                long int ra;
                printf("Digite o RA: ");
                scanf("%ld", &ra);
                imprimir_por_ra(cd, count, ra);
                break;
            }
            case 5:
                imprimir_todos(cd, count);
                break;
            default:
                printf("Opcao invalida!\n");
        }

        printf("Digite 1 para sair ou outro valor para continuar...\n");
        scanf("%d", &sair);
    } while (sair != 1);

    return 0;
}
