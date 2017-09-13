// Programa de calouros Raul Gil com struct
// FATEC - MC - ???? - 06/09/2017 - Versão 0.0
#include "RaulGil.h"
//
// entry point do programa
//
void main(void)
{
	int i, j,						// indices e contadores
		nQtde;						// qtde de calouros que irá cantar hoje
	CALOURO stCalouro,				// struct para conter os dados de um calouro
		vetCalouros[QTDE_MAXIMA];	// vetor de calouros

	for (i = 0; i < 30; i++)
	{
		cin.getline(vetCalouros[i].cNomeCalouro, TAMANHO_NOME, '\n');
	}
	// exemplos de memcpy_s
	memcpy_s(&stCalouro, sizeof(CALOURO), &vetCalouros[i], sizeof(CALOURO));
	memcpy_s(&vetCalouros[i], sizeof(CALOURO), &vetCalouros[i + 1], sizeof(CALOURO));
	// para copiar apenas o primeiro calouro
	memcpy_s(&stCalouro, sizeof(CALOURO), vetCalouros, sizeof(CALOURO));
	memcpy_s(&stCalouro, sizeof(CALOURO), &vetCalouros[0], sizeof(CALOURO));
} // main