/*
FATORIAL
a) Escreva uma função iterativa para calcular N! (fatorial de N).
b) Refaça o item anterior de maneira recursiva.
c) Execute a versão recursiva e não-recursiva da função fatorial e, examine quanto tempo ca-
da uma exige conforme se aumenta o valor de N.
*/

#include <stdio.h>

float fat_iterativo(int x) {
    float fat = 1;

    for (int i = 1; i <= x; i++) {
        fat *= i;
    }
    return fat;
}

float fat_recursivo(int x) {
    if (x == 1 || x == 0) {
        return 1;
    }
    return x * fat_recursivo(x - 1);
}

int main() {
    int n;

    printf("Digite um numero para saber seu fatorial: ");
    scanf("%d", &n);

    printf("(Iterativo) %d! = %.0f\n", n, fat_iterativo(n));
    printf("(Recursivo) %d! = %.0f\n", n, fat_recursivo(n));
}