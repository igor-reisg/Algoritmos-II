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

TipoCadastro ListaAniversarioMes(TipoCadastro *cadastro, int mes) {
    TipoCadastro aniversariantes;
    aniversariantes.Quant = 0;

    for (int i = 0; i < cadastro->Quant; i++) {
        if (cadastro->funcionario[i].DataNascimento.mes == mes) {
            aniversariantes.funcionario[aniversariantes.Quant] = cadastro->funcionario[i];
            aniversariantes.Quant++;
        }
    }
    return aniversariantes;
}

//EXERCICIO COMPLETO EM ex9a19.c