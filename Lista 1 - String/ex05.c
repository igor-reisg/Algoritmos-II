/*
Escreva um programa que substitui as ocorrências de um caractere ‘0’ em uma string
por outro caractere ‘1’.
*/

#include <stdio.h>
#include <string.h>

void troca01(char string[]) {

    
    for (unsigned int i = 0; i < strlen(string); i++) {
        if (string[i] == '0') {
            string[i] = '1';
        } 
    }
}

int main() {

    char string[50];

    printf("Digite uma frase que possua 0:\n");
    fgets(string, sizeof(string), stdin);

    troca01(string);

    printf("String alterada:\n");
    puts(string);
}