/*
Faça um programa que receba do usuário uma string. O programa imprime a string sem
suas vogais.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void tira_vogal (char string[]) {
    char stringvogal[50], c;
    int j = 0;
    
    for (unsigned int i = 0; i < strlen(string); i++) {

        c = toupper(string[i]);

        if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            stringvogal[j] = string[i];
            j++;
        }
    }
    stringvogal[j] = '\0';

    puts(stringvogal);
}


int main () {

    char string[50];

    printf("Digite uma frase: ");
    fgets(string, sizeof(string), stdin);

    printf("Frase alterada: ");
    tira_vogal(string);
}