#include <stdio.h>

#define N 9

void lerPiramide(int piramide[N][N]) {
    int i, j;

    for (i = 0; i < N; i += 2) {
        for (j = 0; j <= i; j += 2) {
            scanf("%d", &piramide[i][j]);
        }
    }
}

void calcularPiramide(int piramide[N][N]) {
    int i, j;

    for (i = N - 1; i > 0; i -= 2) {
        for (j = 0; j < i; j += 2) {
            piramide[i][j + 1] = (piramide[i - 2][j] - piramide[i][j] - piramide[i][j + 2]) >> 1;
            piramide[i - 1][j] = piramide[i][j] + piramide[i][j + 1];
            piramide[i - 1][j + 1] = piramide[i][j + 1] + piramide[i][j + 2];
        }
    }
}

int main() {
    int casos, i, j, k;
    int piramide[N][N];

    scanf("%d", &casos);

    for (k = 0; k < casos; k++) {
        lerPiramide(piramide);
        calcularPiramide(piramide);

        for (i = 0; i < N; ++i) {
            for (j = 0; j <= i; ++j) {
                printf("%d", piramide[i][j]);
                if (j < i) {
                    printf(" ");
                }
            }
            printf("\n");
        }

        if (k < casos - 1) {
            printf("\n");
        }
    }
    return 0;
}
