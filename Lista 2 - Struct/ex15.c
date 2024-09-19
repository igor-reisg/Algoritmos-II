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

TipoReg BuscaNome(TipoCadastro *cadastro, char *nome) {
    TipoReg funcionarioVazio = { "", "", 0.0, 0, '\0', {0, 0, 0} };

    for (int i = 0; i < cadastro->Quant; i++) {
        if (strcmp(cadastro->funcionario[i].Nome, nome) == 0) {
            return cadastro->funcionario[i];
        }
    }

    return funcionarioVazio;
}

//EXERCICIO COMPLETO EM ex9a19.c