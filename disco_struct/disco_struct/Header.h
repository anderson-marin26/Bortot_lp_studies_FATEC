#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

#define LIMPAR_TELA				system("cls")
#define PAUSA					system("pause")
#define BRASIL					setlocale(LC_ALL, "portuguese_brazil")

// path to the file
#define CAMINHO_ARQUIVO			"..\\cadastro.cad"
#define QTDE_PRODUTOS			1000

typedef struct tagPRODUTO
{
	int nCodigo;
	char cDescricao[31];
	double dPrecoUnit;
}PRODUTO;
