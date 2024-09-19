/*
Escreva uma função que classifique/ordene um vetor alfanumérico de no máximo de 45
elementos em ordem crescente. Faça um programa, com reprocessamento, que utilize
essa função.
*/

#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 45

void bubble_sort(char vetor[], int tamanho) {
    int i, j;
    char temp;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int main() {
    char vetor[MAX_TAMANHO + 1];
    char opcao;

    do {
        int tamanho;
        
        printf("Digite o tamanho do vetor (max 45): ");
        scanf("%d", &tamanho);
        getchar(); 

        if (tamanho > MAX_TAMANHO || tamanho <= 0) {
            printf("Tamanho invalido! O tamanho deve ser entre 1 e %d.\n", MAX_TAMANHO);
        }

        printf("Digite os caracteres do vetor: ");
        fgets(vetor, sizeof(vetor), stdin);

        bubble_sort(vetor, tamanho);

        printf("Vetor ordenado: %s\n", vetor);

        printf("Deseja ordenar outro vetor? (s/n): ");
        opcao = getchar();
        while (getchar() != '\n'); 
    } 
    while (opcao == 's' || opcao == 'S');
}

