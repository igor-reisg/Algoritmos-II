#include <stdio.h>

struct vetor {
    float x;
    float y;
    float z;
};

typedef struct vetor vet;

vet soma(vet vetor1, vet vetor2) {
    vet resultado;

    resultado.x = vetor1.x + vetor2.x;
    resultado.y = vetor1.y + vetor2.y;
    resultado.z = vetor1.z + vetor2.z;

    return resultado;
}

int main () {
    
    vet vetor1, vetor2, resultado;

    printf("Digite o vetor 1 (x y z): ");
    scanf("%f %f %f", &vetor1.x, &vetor1.y, &vetor1.z);

    printf("Digite o vetor 2 (x y z): ");
    scanf("%f %f %f", &vetor2.x, &vetor2.y, &vetor2.z);

    resultado = soma(vetor1, vetor2);

    printf("Soma de vetor 1 e vetor 2: %.2f %.2f %.2f\n", resultado.x, resultado.y, resultado.z);
}