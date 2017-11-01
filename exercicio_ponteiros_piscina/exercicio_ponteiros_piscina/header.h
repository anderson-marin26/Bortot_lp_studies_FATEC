#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

// defines
#define LIMPAR_TELA				system("cls")
#define PAUSA					system("pause")
#define BRASIL					setlocale(LC_ALL, "portuguese_brazil")
#define QTDE_PERIODOS			3
#define QTDE_RAIAS_DA_PISCINA	10
#define	QTDE_TOTAL_RAIAS		QTDE_PERIODOS * QTDE_RAIAS_DA_PISCINA
#define MANHA					1
#define TARDE					2
#define NOITE					3
#define MENSALIDADE				250.00
// Opções do menu do operador
#define MATRICULAR_ALUNO		'M'
#define CANCELAR_MATRICULA		'C'
#define LISTAR_PERIODO			'L'
#define SAIR_DO_PROGRAMA		'S'

//
// struct de uma raia da piscina
//
typedef struct tagRAIA
{
	bool flgLivreOcupada;				// true - indica que tem aluno matriculado
	int	 nPeriodo,						// 1, 2, 3 (manhã, tarde e noite
		nRaia;							// 1, 2, 3 .......QTDE_RAIAS_DA_PISCINA
	char cNome[21],						// primeiro nome do aluno
		cSobrenome[21];					// sobrenome do aluno
	double dValorMensalidade;			// mensalidade do aluno que está matriculado
} RAIA;

// protótipos das funções do programa
bool PedirRaiaNoPeriodo(RAIA *ptrVetRaia, int nPeriodo, int *ptrRaiaLivre, char *ptrAcao);

bool PedirPeriodoRaiaValidos(RAIA *ptrVetRaia, int *ptrPeriodo, bool *ptrCancel, int *ptrRaia, int *ptrIndice, char *ptrAcao);