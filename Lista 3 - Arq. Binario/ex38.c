#include <stdio.h>

typedef struct {
    char sexo;     
    int idade;    
    char fumante;
} Resposta;

int main() {
    FILE *arq;
    Resposta resposta;
    int totalPessoas = 0, totalFumantes = 0, totalHomens = 0, totalHomensNaoFumantesAbaixo40 = 0, totalMulheres = 0, totalMulheresFumantesAcima40 = 0;
    double percentualFumantes, percentualMulheresFumantesAcima40, percentualHomensNaoFumantesAbaixo40;
    

    arq = fopen("resposta.bin", "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fread(&resposta, sizeof(Resposta), 1, arq)) {
        totalPessoas++;

        if (resposta.fumante == 'S') {
            totalFumantes++;
        }

        if (resposta.sexo == 'M') {
            totalHomens++;
            if (resposta.fumante == 'N' && resposta.idade < 40) {
                totalHomensNaoFumantesAbaixo40++;
            }
        } else if (resposta.sexo == 'F') {
            totalMulheres++;
            if (resposta.fumante == 'S' && resposta.idade > 40) {
                totalMulheresFumantesAcima40++;
            }
        }
    }

    fclose(arq);

    if (totalPessoas > 0) {
        percentualFumantes = (double)totalFumantes / totalPessoas * 100.0;
        printf("Percentual de fumantes: %.2f%%\n", percentualFumantes);

        if (totalHomens > 0) {
            percentualHomensNaoFumantesAbaixo40 = (double)totalHomensNaoFumantesAbaixo40 / totalHomens * 100.0;
        } 
        else 
            percentualHomensNaoFumantesAbaixo40 = 0.0;

        printf("Percentual de homens não fumantes abaixo de 40 anos: %.2f%%\n", percentualHomensNaoFumantesAbaixo40);
        
        if (totalMulheres > 0) {
            percentualMulheresFumantesAcima40 = (double)totalMulheresFumantesAcima40 / totalMulheres * 100.0;
        } 
        else 
            percentualMulheresFumantesAcima40 = 0.0;

        printf("Percentual de mulheres fumantes acima de 40 anos: %.2f%%\n", percentualMulheresFumantesAcima40);
    } 
    else 
        printf("Nenhuma pessoa foi entrevistada.\n");
}
