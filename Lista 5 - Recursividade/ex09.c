#include <stdio.h>

float exponencial(int x, int y) {
    if (y == 1) {
        return x;
    }
    return x * exponencial(x, y - 1);
}

int main() {
    int continuar = 1, a, b;

    do {
        printf("Digite a base e o expoente: ");
        scanf("%d %d", &a, &b);

        printf("%d^%d = %.0f\n", a, b, exponencial(a, b));

        printf("Digite 1 para executar o programa novamente...\n");
        scanf("%d", &continuar);
    }
    while (continuar == 1);
}