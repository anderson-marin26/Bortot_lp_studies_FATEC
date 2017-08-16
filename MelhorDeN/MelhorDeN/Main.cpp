// Programa que exibe a maior digitada entre N
// FATEC - MC - Anderson Marin de Ramos - 16/08/2017 

#include "Header.h"

// entry point
void main(void)
{
	int i,
		nTrono = INT_MIN,
		nTronoMenor = INT_MAX,
		nDigitada;
	BRASIL;

	for (i = 0; i < QTDE_INTEIRAS; i++)
	{
		cout << "Digite a inteira de ordem " << i + 1 << " de " << QTDE_INTEIRAS << ": ";
		cin >> nDigitada;

		if (nDigitada > nTrono)
		{
			nTrono = nDigitada;
		}

		if (nDigitada < nTronoMenor)
		{
			nTronoMenor = nDigitada;
		}
	}// for i

	cout << "A maior inteira �: " << nTrono << endl 
		 << "A menor inteira � : " << nTronoMenor << endl;
	PAUSA;
}// main