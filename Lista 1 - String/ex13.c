/*
Escreva uma função que retorne o número de palavras de uma frase. Faça um
programa, com reprocessamento, que utilize esta função.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contar_palavras(char string[]) {
    int cont = 0;
    int palavra = 0;
    int i = 0;

    while (string[i] != '\0') {
        if (isalnum(string[i])) {
            if (!palavra) {
                palavra = 1;
                cont++;
            }
        } else {
            palavra = 0;
        }
        i++;
    }

    return cont;
}

int main() {
    char string[256];
    char opcao;
    int numpalavras;

    do {
        printf("Digite uma frase: ");
        fgets(string, sizeof(string), stdin);

        numpalavras = contar_palavras(string);
        printf("Numero de palavras: %d\n", numpalavras);

        printf("Deseja digitar outra frase? (s/n): ");
        opcao = getchar();

        while (getchar() != '\n');

    } 
    while (opcao == 's' || opcao == 'S');
}

