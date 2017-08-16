#include "meu.h"

void main(void)
{
	int nPrimeira,
		nSegunda,
		nTerceira;
	BRASIL;

	cout << "Digite a primeira inteira ";
	cin >> nPrimeira;
	cout << "Digite a segunda inteira ";
	cin >> nSegunda;
	cout << "Digite a terceira inteira ";
	cin >> nTerceira;

	if (nPrimeira >= nSegunda && nPrimeira >= nTerceira)
	{
		cout << "Primeira inteira é maior : " << nPrimeira << endl;
	}
	else if (nSegunda >= nPrimeira && nSegunda >= nTerceira)
	{
		cout << "Segunda inteira é maior : " << nSegunda << endl;
	}
	else if (nTerceira >= nPrimeira && nTerceira >= nSegunda)
	{
		cout << "Terceira inteira é maior : " << nTerceira << endl;
	}

	PAUSA;
} // main