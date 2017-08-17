// FATEC MC - Anderson Marin de Ramos - 16/08/2017
#include "Header.h"

// entry point
void main(void)
{
	int i, j, k,
		vtInt[] = { 23, 456, 567, 200, -300, 56, 21, 45 },
		vetInteiras[QTDE_INTEIRAS];
	char szNome[] = "Anderson Marin de Ramos",
		vetChar[] = { 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd' },
		vtChar[QTDE_INTEIRAS - 500];
	BRASIL;

	cout << "\n\tListagem das inteiras vtInt" << endl;

	for (i = 0; i < sizeof(vtInt) / sizeof(int); i++)
	{
			cout << vtInt[i] << endl;	
	}// for i

	PAUSA;
	LIMPAR_TELA;

	cout << "\n\tListagem de 3 por linha" << endl;
	ListarVetorInteiras(vtInt, sizeof(vtInt) / sizeof(int), 3);

	/*
		for (i = 0; i < sizeof(vtInt) / sizeof(int);)
		{
			for (j = 0; j < 3; j++, i++)
			{
				if (i == sizeof(vtInt) / sizeof(int))
				{
					break;
				}

				cout << vtInt[i] << "\t";
			}// for j

			cout << endl;
		}// for i
	*/

	PAUSA;

	// Inicializando vetor
	for(i = 0, j = 2; i < QTDE_INTEIRAS; i++, j += 2)
	{
		vetInteiras[i] = j;
	}

	LIMPAR_TELA;

	cout << "\n\tListagem de vetInteiras 8 por linha" << endl;
	ListarVetorInteiras(vetInteiras, QTDE_INTEIRAS, 8);

	PAUSA;

	// inicializar com random
	srand(200);
	for (i = 0; i < QTDE_INTEIRAS; i++)
	{
		vetInteiras[i] = rand();

		if (rand() % 2 == 1)
		{
			vetInteiras[i] *= -1;
		}
	}

	LIMPAR_TELA;
	cout << "\n\tListagem de vetInteiras com indice random 7 por linha" << endl;

	ListarVetorInteiras(vetInteiras, QTDE_INTEIRAS, 7);

	PAUSA;
}// main

void ListarVetorInteiras(int vetorInteiras[], int nQtde, int nQtdePorLinha)
{
	int i, j;

	for (i = 0; i < nQtde;)
	{
		for (j = 0; j < nQtdePorLinha; j++, i++)
		{
			if (i == nQtde)
			{
				break;
			}

			cout << vetorInteiras[i] << "\t";
		}// for j

		cout << endl;
	}// for i
}