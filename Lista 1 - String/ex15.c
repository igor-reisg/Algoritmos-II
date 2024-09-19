/*
Escreva uma função que retorne a maior palavra de uma frase. Faça um programa, com
reprocessamento, que utilize esta função.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void maior_palavra(char string[], char maior[]) {
    char *c = strtok(string, " ");
    strcpy(maior, "");

    while (c != NULL) {
        if (strlen(c) > strlen(maior)) {
            strcpy(maior, c);
        }
        c = strtok(NULL, " ");
    }
}

int main() {
    char string[500];
    char maior[500];
    char resposta;

    do {
        printf("Digite uma frase: ");
        fgets(string, sizeof(string), stdin);

        maior_palavra(string, maior);
        
        printf("A maior palavra da frase eh: %s\n", maior);
        
        printf("Deseja inserir outra frase? (s/n): ");
        resposta = tolower(getchar());
        while (getchar() != '\n');

    } 
    while (resposta == 's');

}
