/*
Faça uma função que compare duas strings (não utilize a função strcmp()). Escreva um
programa que utilize a função desenvolvida.
*/

#include <stdio.h>
#include <string.h>

#define TAM 50

int compara(const char string1[], const char string2[]) {
    unsigned int i = 0;

    while (string1[i] != '\0' && string2[i] != '\0') {
        if (string1[i] != string2[i]) {
            return 1; 
        }
        i++;
    }

    if (string1[i] != string2[i]) {
        return 1; 
    }

    return 0;
}

int main() {

    char string1[TAM], string2[TAM];
    int val;

    printf("Digite duas frases:\n");
    fgets(string1, sizeof(string1), stdin);
    fgets(string2, sizeof(string2), stdin);

    val = compara(string1, string2);

    if (val == 0) {
        printf("As duas frases sao iguais\n");
    } 
    else
        printf("As frases sao diferentes\n");

}
