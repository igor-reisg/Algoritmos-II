#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float custo;
} Produto;

void incluirProduto(FILE *arquivo) {
    Produto p;
    printf("ID do produto: ");
    scanf("%d", &p.id);
    printf("Nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Quantidade: ");
    scanf("%d", &p.quantidade);
    printf("Custo unitario: ");
    scanf("%f", &p.custo);

    fseek(arquivo, 0, SEEK_END);
    fwrite(&p, sizeof(Produto), 1, arquivo);
    printf("Produto adicionado com sucesso!\n");
}

void consultarProduto(FILE *arquivo) {
    char nome[50];
    Produto p;
    int encontrado = 0;

    printf("Nome do produto: ");
    scanf(" %[^\n]", nome);

    rewind(arquivo);
    while (fread(&p, sizeof(Produto), 1, arquivo)) {
        if (strcmp(p.nome, nome) == 0) {
            printf("ID: %d, Nome: %s, Quantidade: %d, Custo: %.2f\n", p.id, p.nome, p.quantidade, p.custo);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

void alterarProduto(FILE *arquivo) {
    int id, encontrado = 0;
    Produto p;
    printf("ID do produto a ser alterado: ");
    scanf("%d", &id);

    rewind(arquivo);
    while (fread(&p, sizeof(Produto), 1, arquivo)) {
        if (p.id == id) {
            printf("Produto encontrado!\n");
            printf("Novo nome: ");
            scanf(" %[^\n]", p.nome);
            printf("Nova quantidade: ");
            scanf("%d", &p.quantidade);
            printf("Novo custo: ");
            scanf("%f", &p.custo);

            fseek(arquivo, -sizeof(Produto), SEEK_CUR);
            fwrite(&p, sizeof(Produto), 1, arquivo);
            printf("Produto alterado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

void removerProduto(FILE *arquivo) {
    int id, encontrado = 0;
    Produto p;
    FILE *temp = fopen("temp.bin", "wb");

    printf("ID do produto a ser removido: ");
    scanf("%d", &id);

    rewind(arquivo);
    while (fread(&p, sizeof(Produto), 1, arquivo)) {
        if (p.id == id) {
            printf("Produto removido com sucesso!\n");
            encontrado = 1;
        } else {
            fwrite(&p, sizeof(Produto), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);
    remove("produtos.bin");
    rename("temp.bin", "produtos.bin");

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

void relatorioEstoque(FILE *arquivo) {
    Produto p;
    int opcao, quantidade;
    rewind(arquivo);

    printf("1 - Produto com maior estoque\n");
    printf("2 - Produtos com estoque abaixo de X unidades\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        Produto maior;
        int maiorEstoque = 0;

        while (fread(&p, sizeof(Produto), 1, arquivo)) {
            if (p.quantidade > maiorEstoque) {
                maiorEstoque = p.quantidade;
                maior = p;
            }
        }

        if (maiorEstoque > 0) {
            printf("Produto com maior estoque: %s, Quantidade: %d\n", maior.nome, maiorEstoque);
        } else {
            printf("Nenhum produto encontrado.\n");
        }
    } else if (opcao == 2) {
        printf("Digite a quantidade minima: ");
        scanf("%d", &quantidade);

        while (fread(&p, sizeof(Produto), 1, arquivo)) {
            if (p.quantidade < quantidade) {
                printf("ID: %d, Nome: %s, Quantidade: %d, Custo: %.2f\n", p.id, p.nome, p.quantidade, p.custo);
            }
        }
    }
}

int main() {
    FILE *arquivo;
    int opcao;

    arquivo = fopen("produtos.bin", "rb+");
    if (arquivo == NULL) {
        arquivo = fopen("produtos.bin", "wb+");
        if (arquivo == NULL) {
            printf("Erro ao abrir arquivo!\n");
            return 1;
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1 - Incluir Produto\n");
        printf("2 - Consultar Produto\n");
        printf("3 - Alterar Produto\n");
        printf("4 - Remover Produto\n");
        printf("5 - Gerar Relatorio\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirProduto(arquivo);
                break;
            case 2:
                consultarProduto(arquivo);
                break;
            case 3:
                alterarProduto(arquivo);
                break;
            case 4:
                removerProduto(arquivo);
                arquivo = fopen("produtos.bin", "rb+");  // Reabrir o arquivo após remoção
                break;
            case 5:
                relatorioEstoque(arquivo);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    fclose(arquivo);
    return 0;
}
