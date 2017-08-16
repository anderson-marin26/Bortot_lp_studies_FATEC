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
}// main