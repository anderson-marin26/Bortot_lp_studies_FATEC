#pragma once
// declara��es do programa de calouros Raul Gil
#include <iostream>
#include <Windows.h>
using namespace std;
// defines
#define PAUSA							system("pause")
#define LIMPAR_TELA						system("cls")
#define BRASIL							setlocale(LC_ALL, "portuguese_brazil")
#define QTDE_MINIMA						3		// qtde m�nima de calouros
#define QTDE_MAXIMA						30		// idem m�xima
#define MASCULINO						'M'
#define FEMININO						'F'
#define TAMANHO_NOME					30
//
// struct de um calouro
//
typedef struct tagCALOURO
{
	int nNotaCalouro;					// nota do calouro
	char cSexoCalouro,					// sexo do calouro
		cNomeCalouro[TAMANHO_NOME + 1];
}CALOURO;

// prot�tipos das fun��es
