// Funções adicionais do programa
#include "Maior.h"
// Função que lista um vetor de char uma quantidade por linha
// Parâmetros:
//	Entrada: char vtChar[] - endereço do primeiro byte do vetor de char
//			 int nQtde - quantidade de bytes do vetor
//			 int nQtdePorLinha - quantidade de char a ser listado por linha
void ListarVetorChar(char vtChar[], int nQtde, int nQtdePorLinha)
{
	int i,										// indexador e contador genérico
		nQtLinha,								// contador por linha
		nLinha;									// linha da listagem
	for (i = 0, nLinha = 0; i < nQtde; )					// listagem de todos char
	{
		// loop por linha
		for (nQtLinha = 0; nQtLinha < nQtdePorLinha; nQtLinha++, i++)
		{
			if (i == nQtde)						// listou todas?
				break;							// cai fora do for nQtLinha
			cout << vtChar[i];					// lista cada char
		} // for nQtLinha
		cout << "  Linha: " << ++nLinha << endl;
	} // for i
	cout << "\n\tFim da listagem " << endl;
	PAUSA;
}