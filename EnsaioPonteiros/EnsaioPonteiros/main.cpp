#include "header.h"

// Funcao que lista um vetor de inteiras com ponteiro direto
void ListarVetorInteiras(int *ptrInt, int nQt, char *ptrCabec)
{
	int i, j;

	LIMPAR_TELA;

	cout << "\n\t" << ptrCabec << endl;
	
	for (i = 0; i < nQt; )
	{
		for (j = 0; j < 9; j++, i++, ptrInt++)
		{
			if (i == nQt)
			{
				break;
			}

			cout << *ptrInt << "\t";
		}// for j

		cout << endl;
	} // for i

	cout << "\n\tFim da listagem" << endl;

	PAUSA;
}

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
	double vetDouble[QTDE_DOUBLES],
		*ptrDouble = vetDouble,
		dValor = 100.56;
	CLIENTE stCliente,		// struct do cliente
		vetClientes[QTDE_CLIENTES],
		*ptrStruct = vetClientes;
	char cWork[150];
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

	*ptrC = 0;		// zerar nSoma.
	*ptrC = nValor + *ptrB;

	cout << "nSoma = " << nSoma << endl;

	PAUSA;

	// tratamento do vetor
	ptrC = vetInteiras;			// apontando para primeira inteira do vetor

	cout << "ptrC=" << ptrC << "Ender. de vetInteira=" << vetInteiras << endl;

	PAUSA;

	// inicializa vetor
	for (i = 0; i < QTDE_INTEIRAS; i++)
	{
		*ptrC++ = i + 1;
	}

	cout << "ptrC=" << ptrC << "Ender. de vetInteira=" << vetInteiras << endl;

	PAUSA;

	ListarVetorInteiras(vetInteiras, QTDE_INTEIRAS, "Listagem do vetor de inteiras 1,2, ......");

	// inicializar vetor de inteiras com valores random
	// aritmetica de ponteiros
	cout << "ptrC=" << ptrC << "Ender. de vetInteira=" << vetInteiras << endl;

	PAUSA;

	ptrC = vetInteiras;

	for (i = 0, srand(100); i < QTDE_INTEIRAS; i++)
	{
		*(ptrC + i) = rand();
		if (rand() % 2 == 1) // tornar negativo
		{
			*(ptrC + i) *= -1;
		}
	}
	ptrC = vetInteiras;

	cout << "ptrC=" << ptrC << "Ender. de vetInteira=" << vetInteiras << endl;
	PAUSA;

	ListarVetorInteiras(ptrC, QTDE_INTEIRAS, "Listagem de inteiras random");


	// iniciar o vetor de doubles com valores random
	LIMPAR_TELA;

	cout << "ptrDouble=" << ptrDouble << " Endereco vetDouble" << vetDouble << endl;
	for (i = 0; i < QTDE_DOUBLES; i++)
	{
		*ptrDouble++ = rand() * 0.567;
	}

	cout << "ptrDouble=" << ptrDouble << " Endereco vetDouble" << vetDouble << endl;
	PAUSA;

	// tratamento de struct
	ptrStruct = &stCliente;
	cout << "Codigo cliente: ";
	cin >> ptrStruct->nCodigo;
	cin.ignore(1, EOF);
	cout << "Nome: ";
	cin.getline(ptrStruct->cNomeCliente, 30, '\n');
	cout << "Saldo: ";
	cin >> ptrStruct->dSaldoCliente;

	// inicializar vetor
	for (i = 0, ptrStruct = vetClientes; i < QTDE_CLIENTES; i++)
	{
		(ptrStruct + i)->nCodigo = rand();
		sprintf_s(cWork, sizeof(cWork), "Nome do cliente de codigo=%d",(ptrStruct+i)->nCodigo);
		strcpy_s((ptrStruct + i)->cNomeCliente, 30, cWork);
		(ptrStruct + i)->dSaldoCliente = rand() * 0.456;
	}

	// listar vetor
} // main