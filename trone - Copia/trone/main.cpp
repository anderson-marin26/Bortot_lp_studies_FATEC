#include "header.h"

void main(void)
{
	int nTrono,
		nDigitada;
	char cQuem = PRIMEIRA;

	cout << "Digite a primeira inteira: ";
	cin >> nTrono;
	cout << "Digite a segunda inteira: ";
	cin >> nDigitada;

	if (nDigitada > nTrono)
	{
		nTrono = nDigitada;
		cQuem = SEGUNDA;
	}

	cout << "Digite a terceira inteira: ";
	cin >> nDigitada;

	if (nDigitada > nTrono)
	{
		nTrono = nDigitada;
		cQuem = TERCEIRA;
	}

	switch (cQuem)
	{
		case PRIMEIRA:
			cout << "A maior � a primeira = " << nTrono << endl;
			break;
		case SEGUNDA:
			cout << "A maior � a segunda = " << nTrono << endl;
			break;
		case TERCEIRA:
			cout << "A maior � a terceira = " << nTrono << endl;
			break;
	}


	/*
		if (cQuem == PRIMEIRA)
		{
			cout << "A maior � a primeira = " << nTrono << endl;
		}
		else if (cQuem == SEGUNDA)
		{
			cout << "A maior � a segunda = " << nTrono << endl;
		}
		else
		{
			cout << "A maior � a terceira = " << nTrono << endl;
		}
	*/
	
	PAUSA;
}