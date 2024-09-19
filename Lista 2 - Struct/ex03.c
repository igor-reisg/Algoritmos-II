#include <stdio.h>

typedef struct {
    float real;
    float imag;
} complexo;

complexo lerComplexo() {
    complexo c;
    printf("Digite a parte real: ");
    scanf("%f", &c.real);
    printf("Digite a parte imaginaria: ");
    scanf("%f", &c.imag);
    return c;
}

complexo somarComplexo(complexo c1, complexo c2) {
    complexo resultado;
    resultado.real = c1.real + c2.real;
    resultado.imag = c1.imag + c2.imag;
    return resultado;
}

complexo subtrairComplexo(complexo c1, complexo c2) {
    complexo resultado;
    resultado.real = c1.real - c2.real;
    resultado.imag = c1.imag - c2.imag;
    return resultado;
}

complexo multiplicarComplexo(complexo c1, complexo c2) {
    complexo resultado;
    resultado.real = c1.real * c2.real - c1.imag * c2.imag;
    resultado.imag = c1.real * c2.imag + c1.imag * c2.real;
    return resultado;
}

void imprimirComplexo(complexo c) {
    if (c.imag >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    }
}

int main() {
    complexo c1, c2, resultado;
    int opcao;

    printf("Numero complexo 1:\n");
    c1 = lerComplexo();
    printf("Numero complexo 2:\n");
    c2 = lerComplexo();

    printf("\nEscolha uma operacao:\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            resultado = somarComplexo(c1, c2);
            printf("\nResultado da soma: ");
            imprimirComplexo(resultado);
            break;
        case 2:
            resultado = subtrairComplexo(c1, c2);
            printf("\nResultado da subtracao: ");
            imprimirComplexo(resultado);
            break;
        case 3:
            resultado = multiplicarComplexo(c1, c2);
            printf("\nResultado da multiplicacao: ");
            imprimirComplexo(resultado);
            break;
        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}
