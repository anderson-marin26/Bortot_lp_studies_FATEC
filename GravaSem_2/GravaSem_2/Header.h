#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
// Defini��es do programa
#define LIMPAR_TELA			system("cls")
#define PAUSA				system("pause")
#define CAMINHO_ARQUIVO		"..\\Cadastro.cad"
#define BRASIL				setlocale(LC_ALL, "portuguese_brazil")
#define QTDE_PRODUTOS		100
// struct de produto
typedef struct tagPRODUTO
{
	int nCodigo;					// 1, 2, 3, ...... QTDE_PRODUTOS
	char cDescricao[41];			// Descri��o do produto
	double dPrecoUnit;				// pre�o unit�rio do produto
}PRODUTO;

