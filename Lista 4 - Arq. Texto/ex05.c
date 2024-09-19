#include <stdio.h>
#include <string.h>

int main() {
    FILE *arq;
    char palavra[30], nome[30], texto[500];
    int tam, qtd = 0;
    char *pos;

    printf("Digite o nome do arquivo: ");
    fgets(nome, sizeof(nome), stdin);

    tam = strlen(nome) - 1;
    if (nome[tam] == '\n') {
        nome[tam] = '\0';
    }

    printf("Digite a palavra buscada no arquivo: ");
    fgets(palavra, sizeof(palavra), stdin);

    tam = strlen(palavra) - 1;
    if (palavra[tam] == '\n') {
        palavra[tam] = '\0';
    }

    arq = fopen(nome, "r");
    if (!arq) {
        printf("Houve um erro ao abrir o arquivo!\n");
    }

    while (fgets(texto, sizeof(texto), arq) != NULL) {

        pos = texto;
        if ((pos = strstr(pos, palavra)) != NULL) {
            qtd++;
            pos += strlen(palavra);
        }
    }

    fclose(arq);

    printf("Quantidade de vezes que '%s' aparece no arquivo: %d", palavra, qtd);

}