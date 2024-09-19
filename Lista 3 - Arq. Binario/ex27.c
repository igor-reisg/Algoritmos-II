#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIENTES_FILE "clientes.dat"
#define CONSULTAS_FILE "consultas.dat"

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    char endereco[100];
    char telefone[15];
    char patologia[100];
} Cliente;

typedef struct {
    int codigo_cliente;
    int dia;
    int mes;
    int ano;
} Consulta;

void marcar_consulta();
void desmarcar_consulta();
void escrever_mapa_horarios();
void escrever_nome_datas_paciente();
void escrever_nome_telefone_pacientes();

int main() {
    int opcao;

    do {
        printf("Menu de Opcoes:\n");
        printf("1 - Marcar a consulta\n");
        printf("2 - Desmarcar a consulta\n");
        printf("3 - Escrever mapa de horarios para um determinado dia\n");
        printf("4 - Escrever o nome e as datas em que um paciente foi consultado\n");
        printf("5 - Escrever o nome e o telefone de todos os pacientes cuja ultima consulta ocorreu ha mais de 6 meses e que tem idade superior a 50 anos\n");
        printf("6 - Fim\n");
        printf("--> ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                marcar_consulta();
                break;
            case 2:
                desmarcar_consulta();
                break;
            case 3:
                escrever_mapa_horarios();
                break;
            case 4:
                escrever_nome_datas_paciente();
                break;
            case 5:
                escrever_nome_telefone_pacientes();
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

void marcar_consulta() {
    FILE *arq_consultas = fopen(CONSULTAS_FILE, "ab");
    if (!arq_consultas) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return;
    }

    int codigo_cliente;
    Consulta consulta;

    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigo_cliente);
    getchar();

    printf("Digite a data da consulta (dd mm aaaa): ");
    scanf("%d %d %d", &consulta.dia, &consulta.mes, &consulta.ano);
    consulta.codigo_cliente = codigo_cliente;

    fwrite(&consulta, sizeof(Consulta), 1, arq_consultas);
    fclose(arq_consultas);
    printf("Consulta marcada com sucesso!\n");
}

void desmarcar_consulta() {
    FILE *arq_consultas = fopen(CONSULTAS_FILE, "rb");
    FILE *arq_temp = fopen("temp.dat", "wb");

    if (!arq_consultas || !arq_temp) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return;
    }

    int codigo_cliente;
    Consulta consulta;

    printf("Digite o codigo do cliente para desmarcar a consulta: ");
    scanf("%d", &codigo_cliente);
    getchar();

    while (fread(&consulta, sizeof(Consulta), 1, arq_consultas)) {
        if (consulta.codigo_cliente != codigo_cliente) {
            fwrite(&consulta, sizeof(Consulta), 1, arq_temp);
        }
    }

    fclose(arq_consultas);
    fclose(arq_temp);
    remove(CONSULTAS_FILE);
    rename("temp.dat", CONSULTAS_FILE);
    printf("Consulta desmarcada com sucesso!\n");
}

void escrever_mapa_horarios() {
    FILE *arq_consultas = fopen(CONSULTAS_FILE, "rb");
    if (!arq_consultas) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return;
    }

    int dia, mes, ano;
    Consulta consulta;

    printf("Digite a data para o mapa de horarios (dd mm aaaa): ");
    scanf("%d %d %d", &dia, &mes, &ano);

    printf("Consultas para a data %02d/%02d/%04d:\n", dia, mes, ano);

    while (fread(&consulta, sizeof(Consulta), 1, arq_consultas)) {
        if (consulta.dia == dia && consulta.mes == mes && consulta.ano == ano) {
            printf("Codigo do cliente: %d\n", consulta.codigo_cliente);
        }
    }

    fclose(arq_consultas);
}

void escrever_nome_datas_paciente() {
    FILE *arq_clientes = fopen(CLIENTES_FILE, "rb");
    FILE *arq_consultas = fopen(CONSULTAS_FILE, "rb");

    if (!arq_clientes || !arq_consultas) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    int codigo_cliente;
    Cliente cliente;
    Consulta consulta;

    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigo_cliente);
    getchar();

    while (fread(&cliente, sizeof(Cliente), 1, arq_clientes)) {
        if (cliente.codigo == codigo_cliente) {
            printf("Nome do cliente: %s\n", cliente.nome);
            break;
        }
    }

    printf("Consultas realizadas:\n");
    while (fread(&consulta, sizeof(Consulta), 1, arq_consultas)) {
        if (consulta.codigo_cliente == codigo_cliente) {
            printf("Data: %02d/%02d/%04d\n", consulta.dia, consulta.mes, consulta.ano);
        }
    }

    fclose(arq_clientes);
    fclose(arq_consultas);
}

void escrever_nome_telefone_pacientes() {
    FILE *arq_clientes = fopen(CLIENTES_FILE, "rb");
    FILE *arq_consultas = fopen(CONSULTAS_FILE, "rb");

    if (!arq_clientes || !arq_consultas) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    Cliente cliente;
    Consulta consulta;
    int ano_atual = 2024, mes_atual = 9, dia_atual = 8, seis_meses = 6*30;
    int ultima_consulta_dia = 0, ultima_consulta_mes = 0, ultima_consulta_ano = 0;
    int dias_ultima_consulta;

    while (fread(&cliente, sizeof(Cliente), 1, arq_clientes)) {
        if (cliente.idade > 50) {
            ultima_consulta_dia = 0, ultima_consulta_mes = 0, ultima_consulta_ano = 0;
            rewind(arq_consultas);
            while (fread(&consulta, sizeof(Consulta), 1, arq_consultas)) {
                if (consulta.codigo_cliente == cliente.codigo) {
                    if (consulta.ano > ultima_consulta_ano ||
                        (consulta.ano == ultima_consulta_ano && consulta.mes > ultima_consulta_mes) ||
                        (consulta.ano == ultima_consulta_ano && consulta.mes == ultima_consulta_mes && consulta.dia > ultima_consulta_dia)) {
                        ultima_consulta_dia = consulta.dia;
                        ultima_consulta_mes = consulta.mes;
                        ultima_consulta_ano = consulta.ano;
                    }
                }
            }

            dias_ultima_consulta = (ano_atual - ultima_consulta_ano) * 365 + (mes_atual - ultima_consulta_mes) * 30 + (dia_atual - ultima_consulta_dia);
            if (dias_ultima_consulta > seis_meses) {
                printf("Nome: %s\n", cliente.nome);
                printf("Telefone: %s\n", cliente.telefone);
            }
        }
    }

    fclose(arq_clientes);
    fclose(arq_consultas);
}
