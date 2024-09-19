#include <stdio.h>

int prod_iterativo(int x, int y) {
    int prod = 0;

    for (int i = 0; i < y; i++) {
        prod += x;
    }
    return prod;
}

int prod_recursivo(int x, int y) {
    if (y == 1) {
        return x;
    }
    return x + prod_recursivo(x, y - 1);
}

int main() {
    int a, b;

    printf("Digite 2 numeros inteiros nao negativos: ");
    scanf("%d %d", &a, &b);

    printf("(Iterativo) %d*%d = %d\n", a, b, prod_iterativo(a, b));
    printf("(Recursivo) %d*%d = %d\n", a, b, prod_recursivo(a, b));

}