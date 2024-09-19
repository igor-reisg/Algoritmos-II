#include <stdio.h>

void fib_iterativo(int x, int vet[]) {
    vet[0] = 0;
    vet[1] = 1;

    for (int i = 2; i < x; i++) {
        vet[i] = vet[i - 1] + vet[i - 2];
    }

    for (int i = 0; i < x; i++) {
        printf("%d ", vet[i]);
    }
}

int fib_recursivo(int x) {
    if (x == 0) {
        return 0;
    }
    else if (x == 1) {
        return 1;
    }
    return fib_recursivo(x - 1) + fib_recursivo(x - 2);
}

int main() {
    int n, fib[50];

    printf("Digite a quantidade de elementos da sequencia de Fibonacci (Max: 50): ");
    scanf("%d", &n);

    printf("Iterativo: \n");
    fib_iterativo(n, fib);

    printf("\nRecursivo: \n");
    
    for (int i = 0; i < n; i++) {
        fib[i] = fib_recursivo(i);
        printf("%d ", fib[i]);
    }
}