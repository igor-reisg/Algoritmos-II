/*
Faça um programa que leia uma string e um caractere (vogal ou consoante) e, substitua
todas as vogais da string dada por esse caractere.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void muda_letra (char string[], char x) {
    char c;
    
    for (unsigned int i = 0; i < strlen(string); i++) {

        c = toupper(string[i]);

        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            string[i] = x;
        }
    }

    puts(string);
}


int main () {

    char string[50], c;

    printf("Digite uma frase: ");
    fgets(string, sizeof(string), stdin);

    printf("Digite um caractere: ");
    scanf("%c",&c);

    printf("Frase alterada: ");
    muda_letra(string, c);
}