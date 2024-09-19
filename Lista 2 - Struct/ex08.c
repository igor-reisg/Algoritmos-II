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

int main() {
    TipoCadastro cadastro;
    IniciaCadastro(&cadastro);

    printf("Quantidade de funcionarios: %d\n", cadastro.Quant);
}
