#include "header.h"

void main(void)
{
	int nTrono,
		nDigitada;
	char cQuem = 'P';

	cout << "Digite a primeira inteira: ";
	cin >> nTrono;
	cout << "Digite a segunda inteira: ";
	cin >> nDigitada;

	if (nDigitada > nTrono)
	{
		nTrono = nDigitada;
		cQuem = 'S';
	}

	cout << "Digite a terceira inteira: ";
	cin >> nDigitada;

	if (nDigitada > nTrono)
	{
		nTrono = nDigitada;
		cQuem = 'T';
	}

	if (cQuem == 'P')
	{
		cout << "A maior é a primeira = " << nTrono << endl;
	}
	else if (cQuem == 'S')
	{
		cout << "A maior é a segunda = " << nTrono << endl;
	}
	else
	{
		cout << "A maior é a terceira = " << nTrono << endl;
	}
	
	PAUSA;
}