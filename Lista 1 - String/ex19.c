/*
Faça um programa que, dada uma string, diga se ela e um palíndromo ou não.
Lembrando que um palíndromo é uma palavra que tenha a propriedade de poder ser
lida tanto da direita para a esquerda como da esquerda para a direita.

Exemplo:
ovo
arara
Socorram-me, subi no onibus em Marrocos
Anotaram a data da maratona
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ePalindromo(char string[]) {
    int inicio = 0;
    int fim = strlen(string) - 1;

    while (inicio < fim) {
        while (inicio < fim && !isalpha(string[inicio])) {
            inicio++;
        }
        while (inicio < fim && !isalpha(string[fim])) {
            fim--;
        }

        if (tolower(string[inicio]) != tolower(string[fim])) {
            return 0; 
        }

        inicio++;
        fim--;
    }

    return 1; 
}

int main() {
    char string[500];

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    if (ePalindromo(string) == 1) {
        printf("A string eh um palindromo.\n");
    } 
    else 
        printf("A string nao eh um palindromo.\n");
}
