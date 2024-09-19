/*
Escreva um programa para converter uma cadeia de caracteres de letras maiúsculas
em letras minúsculas. Não é possível utilizar a função tolower(). Dica: some 32 dos
caracteres cujo código ASCII está entre 65 e 90.
*/

#include <stdio.h>
#include <string.h>

void minuscula(char string[]);

int main() {

    char string[50];

    printf("Digite uma frase em maiusculo (max 50 caracteres): ");
    gets(string);

    minuscula(string);

    printf("Frase em minusculo: %s\n", string);
}

void minuscula(char string[]) {
    int i;
    int tam = strlen(string);

    for (i = 0; i < tam; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 32;
        }
    }
}