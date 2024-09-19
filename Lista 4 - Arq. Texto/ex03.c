#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *arq, *saida;
    char texto[500], nome[50];
    int tam;

    printf("Digite o nome do arquivo que deseja manipular: ");
    fgets(nome, sizeof(nome), stdin);

    tam = strlen(nome) - 1;
    if (nome[tam] == '\n') {
        nome[tam] = '\0';
    }

    saida = fopen("saida.txt", "w");
    arq = fopen(nome, "r");
    if(!arq || !saida) {
        printf("Houve um erro ao abrir o arquivo.\n");
    }

    while (fgets(texto, sizeof(texto), arq) != NULL) {
        for (int i = 0; texto[i] != '\0'; i++) {
            texto[i] =  tolower(texto[i]);
        }

        if (texto[0] != '\0' && isalpha(texto[0])) {
            texto[0] = toupper(texto[0]);
        }

        for(int i = 0; texto[i] != '\0'; i++) {
            if ((texto[i] == '.' || texto[i] == '!' || texto[i] == '?') && texto[i + 1] != '\0') {
                int j = i + 1;
                while (texto[j] == ' ') {
                    j++;
                }

                if (isalpha(texto[j])) {
                    texto[j] = toupper(texto[j]);
                }

            }
        }

        fputs(texto, saida);
    }

    fclose(arq);
    fclose(saida);

    printf("O programa foi executado com sucesso, verifique o arquivo de saida!\n");
    
}