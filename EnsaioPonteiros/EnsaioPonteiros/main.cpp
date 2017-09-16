#include "header.h"

// entry point
void main(void)
{
	int nValor = 50,
		nValorA = 100,
		nSoma,
		i,
		*ptrA = &nValor,
		*ptrB = &nValorA,
		*ptrC,
		**ptrX = &ptrA,
		vetInteiras[QTDE_INTEIRAS];
	BRASIL;

	cout << "Endereço de nValor = " << &nValor << " Conteudo de ptrA " << ptrA << "\nConteudo apontado por ptrA " << *ptrA << endl;

	cout << "Conteudo de ptrX " << ptrX << "  Conteudo apontado por ptrX " << **ptrX << endl << "Endereco de ptrA " << &ptrA << endl;

	ptrC = &nSoma;
	*ptrC = *ptrA + *ptrB;

	cout << "nSoma = " << nSoma << " Ou *ptrC = " << *ptrC << endl;
	nSoma = 0;

	*ptrC = **ptrX + *ptrB;
	cout << "nSoma = " << nSoma << endl;

	PAUSA;
} // main