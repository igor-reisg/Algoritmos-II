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

TipoReg ListaMaraja(TipoCadastro *cadastro) {
    
    TipoReg *maraja = &cadastro->funcionario[0];

    for (int i = 1; i < cadastro->Quant; i++) {
        if (cadastro->funcionario[i].Salario > maraja->Salario) {
            maraja = &cadastro->funcionario[i];
        }
    }
    return *maraja;
}

//EXERCICIO COMPLETO EM ex9a19.c