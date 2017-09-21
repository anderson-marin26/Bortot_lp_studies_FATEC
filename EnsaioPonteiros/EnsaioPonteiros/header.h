#pragma once
// declarações do programa de calouros Raul Gil
#include <iostream>
#include <Windows.h>
using namespace std;
// defines
#define PAUSA							system("pause")
#define LIMPAR_TELA						system("cls")
#define BRASIL							setlocale(LC_ALL, "portuguese_brazil")
#define QTDE_INTEIRAS					1000
#define QTDE_DOUBLES					200
#define QTDE_CLIENTES					200

// Cabecalhos
void ListarVetorInteiras(int *ptrInt, int nQt, char *ptrCabec);

// struct de cliente
typedef struct tagCLIENTE
{
	int nCodigo;
	char cNomeCliente[31];
	double dSaldoCliente;
}CLIENTE;