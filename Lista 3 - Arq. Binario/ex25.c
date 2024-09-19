#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero_cliente;
    char codigo_operacao; 
    char descricao[50];
    int quantidade;
    float valor_unitario;
} Registro;

typedef struct {
    int numero_cliente;
    float saldo_apurado;
    char tipo_saldo; 
} Resultado;

void gerar_resultado(char *entrada, char *saida) {
    FILE *arq1, *arq2;
    Registro registro;
    Resultado resultado;
    int numero_cliente_atual = -1;
    float saldo = 0.0;

    arq1 = fopen(entrada, "rb");
    arq2 = fopen(saida, "wb");

    if (!(arq1) || !(arq2)) {
        printf("Houve um erro ao abrir o arquivo\n");
        return;
    }

    while (fread(&registro, sizeof(Registro), 1, arq1)) {
        if (registro.numero_cliente != numero_cliente_atual) {
            if (numero_cliente_atual != -1) {
                resultado.numero_cliente = numero_cliente_atual;
                resultado.saldo_apurado = saldo;
                resultado.tipo_saldo = saldo > 0 ? 'C' : 'D';
                fwrite(&resultado, sizeof(Resultado), 1, arq2);
            }

            numero_cliente_atual = registro.numero_cliente;
            saldo = 0.0;
        }
        
        if (registro.codigo_operacao == 'C') {
            saldo += registro.quantidade * registro.valor_unitario;
        } else if (registro.codigo_operacao == 'V') {
            saldo -= registro.quantidade * registro.valor_unitario;
        }
    }

    if (numero_cliente_atual != -1) {
        resultado.numero_cliente = numero_cliente_atual;
        resultado.saldo_apurado = saldo;
        resultado.tipo_saldo = saldo > 0 ? 'C' : 'D';
        fwrite(&resultado, sizeof(Resultado), 1, arq2);
    }

    fclose(arq1);
    fclose(arq2);
}

int main() {
    gerar_resultado("bolsa.dat", "resultado.dat");
    printf("Arquivo RESULTADO gerado com sucesso!\n");
    return 0;
}
