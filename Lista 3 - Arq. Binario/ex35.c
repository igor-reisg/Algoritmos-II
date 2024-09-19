#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int dia;
    int mes;
} data;

typedef struct {
    char nome[50];
    char telefone[15];
    data aniversario;
} contatos;

void inserir() {
    FILE *arq;
    contatos cont;
    int tam;

    arq = fopen("contatos.bin", "ab");
    if(!arq) {
        printf("Houve um erro ao abrir o arquivo\n");
        return;
    }

    printf("Nome: ");
    fgets(cont.nome, sizeof(cont.nome), stdin);

    tam = strlen(cont.nome) - 1;
    if (cont.nome[tam] == '\n') {
        cont.nome[tam] = '\0';
    }

    printf("Telefone: ");
    fgets(cont.telefone, sizeof(cont.telefone), stdin);

    tam = strlen(cont.telefone) - 1;
    if (cont.telefone[tam] == '\n') {
        cont.telefone[tam] = '\0';
    }

    printf("Aniversario (dia e mes): ");
    scanf("%d %d", &cont.aniversario.dia, &cont.aniversario.mes);

    fwrite(&cont, sizeof(contatos), 1, arq);

    printf("Contato inserido com sucesso!\n");

    fclose(arq);
}

void listar() {
    FILE *arq;
    contatos cont;

    arq = fopen("contatos.bin", "rb");
    if(!arq) {
        printf("Houve um erro ao abrir o arquivo\n");
        return;
    }
    printf("\nLISTA DE CONTATOS:\n\n");
    
    while(fread(&cont, sizeof(contatos), 1, arq) == 1) {
        printf("Nome: %s\n", cont.nome);
        printf("Telefone: %s\n", cont.telefone);
        printf("Aniversario: %d/%d\n\n", cont.aniversario.dia, cont.aniversario.mes);
    }

    fclose(arq);
}

void listar_inicial() {
    FILE *arq;
    contatos cont;
    char inicial;

    printf("Inicial que deseja buscar: ");
    scanf("%c", &inicial);

    arq = fopen("contatos.bin", "rb");
    if(!arq) {
        printf("Houve um erro ao abrir o arquivo\n");
        return;
    }
    
    printf("\nLISTA DE CONTATOS:\n\n");
    
    while(fread(&cont, sizeof(contatos), 1, arq) == 1) {
        if (toupper(cont.nome[0]) == toupper(inicial)) {
            printf("Nome: %s\n", cont.nome);
            printf("Telefone: %s\n", cont.telefone);
            printf("Aniversario: %d/%d\n\n", cont.aniversario.dia, cont.aniversario.mes);
        }
    }
    fclose(arq);
}

void listar_aniversariante() {
    FILE *arq;
    contatos cont;
    int mes_atual;

    printf("Mes atual: ");
    scanf("%d", &mes_atual);

    arq = fopen("contatos.bin", "rb");
    if(!arq) {
        printf("Houve um erro ao abrir o arquivo\n");
        return;
    }
    
    printf("\nLISTA DE ANIVERSARIANTES DO MES:\n\n");
    
    int encontrou = 0;
    while(fread(&cont, sizeof(contatos), 1, arq) == 1) {
        if (cont.aniversario.mes == mes_atual) {
            printf("Nome: %s\n", cont.nome);
            printf("Telefone: %s\n", cont.telefone);
            printf("Aniversario: %d/%d\n\n", cont.aniversario.dia, cont.aniversario.mes);
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("Nao existem aniversariantes nesse mes!\n");
    }
    
    fclose(arq);
}

void listar_nome() {
    FILE *arq;
    contatos cont;
    char nome[50];
    int tam;

    printf("Insira o nome que deseja buscar: ");
    fgets(nome, sizeof(nome), stdin);

    tam = strlen(nome) - 1;
    if (nome[tam] == '\n') {
        nome[tam] = '\0';
    }

    arq = fopen("contatos.bin", "rb");
    if(!arq) {
        printf("Houve um erro ao abrir o arquivo\n");
        return;
    }
    
    printf("\nLISTA DE CONTATOS:\n\n");
    
    int encontrou = 0;
    while(fread(&cont, sizeof(contatos), 1, arq) == 1) {
        if (strcmp(nome, cont.nome) == 0) {
            printf("Nome: %s\n", cont.nome);
            printf("Telefone: %s\n", cont.telefone);
            printf("Aniversario: %d/%d\n\n", cont.aniversario.dia, cont.aniversario.mes);
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("Nao existem contatos com o nome '%s'\n", nome);
    }
    
    fclose(arq);
}

void remover() {
    FILE *arq, *arq_temp;
    contatos cont;
    char nome_remover[50];
    int encontrado = 0;
    int tam;

    arq = fopen("contatos.bin", "rb");
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

    printf("Digite o nome do contato a ser removido: ");
    fgets(nome_remover, sizeof(nome_remover), stdin);

    tam = strlen(nome_remover) - 1;
    if (nome_remover[tam] == '\n') {
        nome_remover[tam] = '\0';
    }

    while (fread(&cont, sizeof(contatos), 1, arq)) {
        if (strcmp(nome_remover, cont.nome) == 0) {
            encontrado = 1;
            printf("Registro removido com sucesso.\n");
        } 
        else {
            fwrite(&cont, sizeof(contatos), 1, arq_temp);
        }
    }

    fclose(arq);
    fclose(arq_temp);

    remove("contatos.bin");
    rename("temp.bin", "contatos.bin");

    if (!encontrado) {
        printf("Registro nao encontrado.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\nCONTROLE DE CONTATOS:\n\n");
        printf("1. Inserir contato\n");
        printf("2. Remover contato\n");
        printf("3. Pesquisar contato pelo nome\n");
        printf("4. Listar todos os contatos\n");
        printf("5. Listar contato pela inicial\n");
        printf("6. Aniversariantes do mes\n");
        printf("7. Sair\n");
        printf("--> ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserir();
                break;
            case 2:
                remover();
                break;
            case 3:
                listar_nome();
                break;
            case 4:
                listar();
                break;
            case 5:
                listar_inicial();
                break;
            case 6:
                listar_aniversariante();
                break;
            case 7:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } 
    while (opcao != 7);

    return 0;
}
