/*
Faça um programa que receba duas frases distintas e imprima de maneira invertida,
trocando as vogais por *.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void muda_letra (char string[]) {
    char c;
    
    for (unsigned int i = 0; i < strlen(string); i++) {

        c = toupper(string[i]);

        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            string[i] = '*';
        }
    }

    for (int i = strlen(string) - 1; i >= 0; i--) {
        printf("%c", string[i]);
    }
}


int main () {

    char string1[50], string2[50];

    printf("Digite uma frase: ");
    fgets(string1, sizeof(string1), stdin);

    printf("Digite outra frase: ");
    fgets(string2, sizeof(string2), stdin);

    printf("Frases alterada: ");
    muda_letra(string1);
    muda_letra(string2);
}