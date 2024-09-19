#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} TipoData;

typedef struct {
    char Nome[100];
    char RG[20];
    float Salario;
    int Idade;
    char Sexo;
    TipoData DataNascimento;
} TipoReg;

typedef struct {
    TipoReg funcionario[100];
    int Quant;
} TipoCadastro;

void SalarioIntervalo(TipoCadastro *cadastro, float v1, float v2) {
    int count = 0;
    float somaSal = 0.0, medSal;

    printf("Funcionarios com salario entre %.2f e %.2f:\n", v1, v2);
    printf("-----------------------------\n");

    for (int i = 0; i < cadastro->Quant; i++) {
        TipoReg *func = &cadastro->funcionario[i];
        if (func->Salario >= v1 && func->Salario <= v2) {
            printf("Nome: %s\n", func->Nome);
            printf("RG: %s\n", func->RG);
            printf("Salario: %.2f\n", func->Salario);
            printf("Idade: %d\n", func->Idade);
            printf("Sexo: %c\n", func->Sexo);
            printf("Data de Nascimento: %02d/%02d/%04d\n", func->DataNascimento.dia, func->DataNascimento.mes, func->DataNascimento.ano);
            printf("-----------------------------\n");

            somaSal += func->Salario;
            count++;
        }
    }

    if (count > 0) {
        medSal = somaSal / count;
        printf("Media dos salarios dos funcionarios listados: %.2f\n", medSal);
    } else {
        printf("Nenhum funcionario encontrado nesse intervalo de salarios.\n");
    }
}

//EXERCICIO COMPLETO EM ex9a19.c