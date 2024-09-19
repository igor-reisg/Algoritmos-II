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

void ListaFuncionarios(TipoCadastro *cadastro) {
    if (cadastro->Quant == 0) {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }

    for (int i = 0; i < cadastro->Quant; i++) {
        TipoReg *func = &cadastro->funcionario[i];
        printf("Funcionario %d:\n", i + 1);
        printf("Nome: %s\n", func->Nome);
        printf("RG: %s\n", func->RG);
        printf("Salario: %.2f\n", func->Salario);
        printf("Idade: %d\n", func->Idade);
        printf("Sexo: %c\n", func->Sexo);
        printf("Data de Nascimento: %02d/%02d/%04d\n", func->DataNascimento.dia, func->DataNascimento.mes, func->DataNascimento.ano);
        printf("-----------------------------\n");
    }
}

//EXERCICIO COMPLETO EM ex9a19.c
