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

void IniciaCadastro(TipoCadastro *cadastro) {
    cadastro->Quant = 0;
}

void LeFuncionarios(TipoCadastro *cadastro) {
    TipoReg novoFuncionario;
    char opcao;

    while (cadastro->Quant < 100) {
        printf("Deseja cadastrar um novo funcionario? (S/N): ");
        scanf(" %c", &opcao);
        if (opcao == 'N' || opcao == 'n') {
            break;
        }

        printf("Nome: ");
        scanf(" %s", novoFuncionario.Nome);
        printf("RG: ");
        scanf(" %s", novoFuncionario.RG);
        printf("Salário: ");
        scanf("%f", &novoFuncionario.Salario);
        printf("Idade: ");
        scanf("%d", &novoFuncionario.Idade);
        printf("Sexo (M/F): ");
        scanf(" %c", &novoFuncionario.Sexo);
        printf("Data de Nascimento (dia mes ano): ");
        scanf("%d %d %d", &novoFuncionario.DataNascimento.dia, &novoFuncionario.DataNascimento.mes, &novoFuncionario.DataNascimento.ano);

        cadastro->funcionario[cadastro->Quant] = novoFuncionario;
        cadastro->Quant++;

        if (cadastro->Quant == 100) {
            printf("Cadastro completo. Nao eh possivel adicionar mais funcionarios.\n");
        }
    }
}

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

TipoReg BuscaNome(TipoCadastro *cadastro, char *nome) {
    TipoReg funcionarioVazio = { "", "", 0.0, 0, '\0', {0, 0, 0} };

    for (int i = 0; i < cadastro->Quant; i++) {
        if (strcmp(cadastro->funcionario[i].Nome, nome) == 0) {
            return cadastro->funcionario[i];
        }
    }

    return funcionarioVazio;
}

TipoReg ListaMaraja(TipoCadastro *cadastro) {
    TipoReg *maraja = &cadastro->funcionario[0];

    for (int i = 1; i < cadastro->Quant; i++) {
        if (cadastro->funcionario[i].Salario > maraja->Salario) {
            maraja = &cadastro->funcionario[i];
        }
    }
    return *maraja;
}

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

void menu(int *opcao) {
    printf("Escolha uma das seguintes opcoes:\n");
    printf("1. Inserir novo funcionario\n");
    printf("2. Listar todos os funcionarios\n");
    printf("3. Buscar funcionario por nome\n");
    printf("4. Exibir funcionario com maior salario\n");
    printf("5. Listar funcionarios que fazem aniversario em um mes\n");
    printf("6. Sair\n");

    scanf("%d", opcao);
}

int main() {
    TipoCadastro cadastro;
    int opcao;

    IniciaCadastro(&cadastro);

    do {
        menu(&opcao);

        switch (opcao) {
            case 1:
                LeFuncionarios(&cadastro);
                break;
            case 2:
                ListaFuncionarios(&cadastro);
                break;
            case 3: {
                char nome[100];
                printf("Digite o nome do funcionario: ");
                scanf(" %s", nome);
                TipoReg func = BuscaNome(&cadastro, nome);
                if (strlen(func.Nome) > 0) {
                    printf("Funcionario encontrado:\n");
                    printf("Nome: %s\n", func.Nome);
                    printf("RG: %s\n", func.RG);
                    printf("Salario: %.2f\n", func.Salario);
                    printf("Idade: %d\n", func.Idade);
                    printf("Sexo: %c\n", func.Sexo);
                    printf("Data de Nascimento: %02d/%02d/%04d\n", func.DataNascimento.dia, func.DataNascimento.mes, func.DataNascimento.ano);
                } else {
                    printf("Funcionario nao encontrado.\n");
                }
                break;
            }
            case 4: {
                TipoReg maraja = ListaMaraja(&cadastro);
                printf("Funcionario com maior salario:\n");
                printf("Nome: %s\n", maraja.Nome);
                printf("RG: %s\n", maraja.RG);
                printf("Salario: %.2f\n", maraja.Salario);
                printf("Idade: %d\n", maraja.Idade);
                printf("Sexo: %c\n", maraja.Sexo);
                printf("Data de Nascimento: %02d/%02d/%04d\n", maraja.DataNascimento.dia, maraja.DataNascimento.mes, maraja.DataNascimento.ano);
                break;
            }
            case 5: {
                int mes;
                printf("Digite o mes de aniversario (1-12): ");
                scanf("%d", &mes);
                TipoCadastro aniversariantes = ListaAniversarioMes(&cadastro, mes);
                ListaFuncionarios(&aniversariantes);
                break;
            }
            case 6:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } 
    while (opcao != 6);

}
