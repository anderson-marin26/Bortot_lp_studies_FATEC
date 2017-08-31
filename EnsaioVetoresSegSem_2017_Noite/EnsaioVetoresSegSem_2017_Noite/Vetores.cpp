// Programa de ensaio de vetores
// FATEC-MC -JCB - 16/08/2017 - Versão 0.0
#include "Maior.h"
// 
// entry point do programa
//
void main(void)
{
	int i, j, k,							// indexadores e contadores genéricos
		vtInt[] = { 23, 456, 567, 10067, 800, -300, 5678, 56 },
		nPrimeira,
		nSegunda,
		vetInteiras[QTDE_INTEIRAS],
		vtInteiras[QTDE_OUTRA],				// outro vetor de inteiras
		vetResultado[QTDE_INTEIRAS + QTDE_OUTRA];
	char szNome[] = "Jose Carlos Bortot",
		vetChar[] = { 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd' },
		vtChar[QTDE_INTEIRAS - 500];
	BRASIL;									// acentuação brasileira
	cout << "\n\tListagem das inteiras vtInt" << endl;
	for (i = 0; i < sizeof(vtInt) / sizeof(int); i++)		// loop de listagem
		cout << vtInt[i] << endl;
	PAUSA;
	LIMPAR_TELA;
	cout << "\n\tListagem de 3 por linha" << endl;
	ListarVetorInteiras(vtInt, sizeof(vtInt) / sizeof(int), 3);
	// inicializar o vetor  vetInteiras com 2, 4, 6, 8, 10 .....
	for (i = 0, j = 2; i < QTDE_INTEIRAS; i++, j += 2)
		vetInteiras[i] = j;
	LIMPAR_TELA;
	cout << "\n\tListagem de vetInteiras 9 por linha" << endl;
	ListarVetorInteiras(vetInteiras, QTDE_INTEIRAS, 9);
	// inicializar com valores randômicos
	srand(200);									// semente random
	for (i = 0; i < QTDE_INTEIRAS; i++)
	{
		vetInteiras[i] = rand();				// a inteira recebe um random 0 a 32k
		if (rand() % 2 == 1)						// vai tornar negativo?
			vetInteiras[i] *= -1;				// torna negativo
	}
	LIMPAR_TELA;
	cout << "\n\tListagem de vetInteiras com valores random 7 por linha" << endl;
	ListarVetorInteiras(vetInteiras, QTDE_INTEIRAS, 7);
	// inicializar o vetor vtInteiras com números randômicos menores que 10000 e n
	// quero números repetidos
	srand(200);									// re-inicia a mesma
	for (i = 0; i < QTDE_OUTRA; i++)				// loop de todas as inteiras
	{
		vtInteiras[i] = rand() % 10000;			// random menor que 10000
		// loop para verificar se tem uma inteira repetida desta inteira i
		for (j = 0; j < i; j++)					// loop para procurar repetida
		{
			if (vtInteiras[j] == vtInteiras[i])	// é uma inteira repetida
			{
				i--;								// repetir o random
				break;							// cai fora do for j
			}
		} // for j
	} // for i
	BubleSort(vtInteiras, QTDE_OUTRA, true);   // classifica em ordem crescente
	LIMPAR_TELA;
	cout << "\n\tListagem de vtInteiras sem valores repetidos crescente" << endl;
	ListarVetorInteiras(vtInteiras, QTDE_OUTRA, 9);
	BubleSort(vtInteiras, QTDE_OUTRA, false);   // classifica em ordem decrescente
	LIMPAR_TELA;
	cout << "\n\tListagem de vtInteiras sem valores repetidos decrescente" << endl;
	ListarVetorInteiras(vtInteiras, QTDE_OUTRA, 9);
	LIMPAR_TELA;
	cout << "\n\tListagem do vetor de char vetChar" << endl;
	ListarVetorChar(vetChar, sizeof(vetChar) / sizeof(char), 3);
	// inicializar o vetor vtChar com letras maiúscula de A.....Z de forma random
	srand(150);
	for (i = 0; i < QTDE_INTEIRAS - 500; i++)
	{
		vtChar[i] = (char) (rand() % 26) + 65;
	}
	LIMPAR_TELA;
	cout << "\n\tListagem do vetor de char vtChar" << endl;
	ListarVetorChar(vtChar, sizeof(vtChar) / sizeof(char), 40);

	// inicializar com valores randômicos
	srand(300);									// semente random
	for (i = 0; i < QTDE_INTEIRAS; i++)
	{
		vetInteiras[i] = rand();				// a inteira recebe um random 0 a 32k
		if (rand() % 2 == 1)						// vai tornar negativo?
			vetInteiras[i] *= -1;				// torna negativo
	}
	BubleSort(vetInteiras, QTDE_INTEIRAS, true);
	LIMPAR_TELA;
	cout << "\n\tListagem do primeiro vetor" << endl;
	ListarVetorInteiras(vetInteiras, QTDE_INTEIRAS, 9);

	for (i = 0; i < QTDE_OUTRA; i++)
	{
		vtInteiras[i] = rand();				// a inteira recebe um random 0 a 32k
		if (rand() % 2 == 1)						// vai tornar negativo?
			vtInteiras[i] *= -1;				// torna negativo
	}
	BubleSort(vtInteiras, QTDE_OUTRA, true);
	LIMPAR_TELA;
	cout << "\n\tListagem do segundo Vetor" << endl;
	ListarVetorInteiras(vtInteiras, QTDE_OUTRA, 9);

	//
	// Merge de dois vetores
	// i --> vetInteiras, j --> vtInteiras, k --> vetResultado
	for (i = j = k = 0; k < QTDE_INTEIRAS +  QTDE_OUTRA; )
	{
		if (i == QTDE_INTEIRAS)
		{
			nPrimeira = INT_MAX;
		}
		else
		{
			nPrimeira = vetInteiras[i];
		}

		if (j == QTDE_OUTRA)
		{
			nSegunda = INT_MAX;
		}
		else
		{
			nSegunda = vtInteiras[j];
		}

		//Analisar a nPrimeira em relação a nSegunda
		//
		if (nPrimeira == nSegunda)
		{
			vetResultado[k++] = nPrimeira;
			i++;
			vetResultado[k++] = nSegunda;
			j++;
		}
		else if (nPrimeira > nSegunda)
		{
			vetResultado[k++] = nSegunda;
			j++;
		}
		else
		{
			vetResultado[k++] = nPrimeira;
			i++;
		}
	}// for k

	LIMPAR_TELA;
	cout << "\n\tListagem do resultado do merge de vetores:" << endl;
	ListarVetorInteiras(vetResultado, QTDE_INTEIRAS + QTDE_OUTRA, 9);
} // main
// Função que lista vetor de inteiras 
// Parâmetros:
//	Entrada: int vetorInteiras[] - endereço do primeiro byte da primeira 
//									inteira do vetor (por referência)
//			 int nQtde - quantidade de inteiras do vetor
//			 int nQtdePorLinha - quantidade de listagem por linha
//
void ListarVetorInteiras(int vetorInteiras[], int nQtde, int nQtdePorLinha)
{
	int i, j;						// indexadores e contadores
	for (i = 0; i < nQtde; )		// loop de todas
	{
		for (j = 0; j < nQtdePorLinha; j++, i++)						// loop por linha
		{
			if (i == nQtde)	// todas foram listadas?
				break;
			cout << vetorInteiras[i] << "\t";
		} // for j
		cout << endl;								// pula de linha
	} // for i
	PAUSA;
} // ListarVetorInteiras
// Função que classifica em ordem crescente um vetor de inteiras
//  segundo o algoritmo de D. Flores
//	Parâmetros:
//		Entrada: int vtInt[] - endereço do primeiro byte da primeira inteira do vetor
//				 int nQtde - quantidade de inteiras do vetor
//				 bool flgOrdem - ordem de classificação: true - ordem crescente
//														 false - ordem decrescente
void BubleSort(int vtInt[], int nQtde, bool flgOrdem)
{
	int i,								// indexador e contador genérico
		nAuxiliar;						// para fazer a troca de posição
	bool flgHouveTroca;					// true - indica que houve troca
	do
	{
		for (i = 0, flgHouveTroca = false; i < nQtde - 1; i++) // inicia não havendo troca
		{ // fazer a comparação duas a duas inteiras para verificar se estão em ordem
			if ((flgOrdem && vtInt[i] > vtInt[i + 1]) ||	// fora de ordem crescente?
				(!flgOrdem && vtInt[i] < vtInt[i + 1]))   // fora de ordem decrescente
			{  // estão fora de ordem - fazer a troca
				nAuxiliar = vtInt[i];	// salva o elem[i]
				vtInt[i] = vtInt[i + 1]; // troca de posição o elem[i+1]
				vtInt[i + 1] = nAuxiliar; // troca de posição o elem[i]
				flgHouveTroca = true;	  // indica que houve troca
			}
		} // for i
	} while (flgHouveTroca);			// enquanto houver troca faça
}








