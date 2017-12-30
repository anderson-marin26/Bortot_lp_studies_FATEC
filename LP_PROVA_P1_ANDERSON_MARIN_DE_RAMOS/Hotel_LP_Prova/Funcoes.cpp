// Fun��es do programa de hotel
#include <iostream>
#include <windows.h>
#include "Hotel.h"
using namespace std;

//---[CheckIn]--------------------------------------------------------------------
// Fun��o para fazer o check-in de um h�spede em um quarto do hotel
//		
//	Par�metros:
//		Entrada: 
//			int nAndar - n�mero do andar
//			int nQuarto - n�mero do quarto dentro do andar informado
//			char *ptrHospede - ponteiro para o nome do h�spede
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto foi ocupado corretamente
//				 bool = false - indica que quarto est� ocupado por outro h�spede
//								e n�o foi liberado por um check-out anterior
bool	CheckIn(int nAndar, int nQuarto, char *ptrHospede, QUARTO *ptrVetor)
{
	// <<<< 08 >>>>
	// 1 - Verificar se o quarto est� ocupado e se estiver 
	//		informar o nome do h�spede dar uma pausa e retornar indicando o erro 
	int iIndice;
	iIndice = QTDE_ANDARES * (nAndar - 1) + (nQuarto - 1); // pegando indice

	if ((ptrVetor + iIndice)->flgLivreOuOcupado == true)
	{
		cout << "Quarto ocupado por " << (ptrVetor + iIndice)->cNomeHospede;
		PAUSA;

		return false;
	}

	// 2 - Associar o quarto ao h�spede: ocupando o quarto, movendo o nome do h�spede 
	//	e zerar os valores de totais de di�rias, de servi�os e despesas
	strcpy_s((ptrVetor + iIndice)->cNomeHospede, ptrHospede);
	(ptrVetor + iIndice)->flgLivreOuOcupado = true;
	(ptrVetor + iIndice)->dValorTotalDespesas = 0;
	(ptrVetor + iIndice)->dValorTotalDiarias = 0;
	(ptrVetor + iIndice)->dValorTotalServicos = 0;

	// 3 - Retornar indicando que foi tudo bem
	return true;			// !!!!!!!!!!!! para nao acusar erro de compila��o
} // CheckIn

//---[CheckOut]--------------------------------------------------------------------
// Fun��o para fazer o check-out de um quarto que tem um h�spede
//		
//	Par�metros:
//		Entrada: 
//			int nAndar - n�mero do andar
//			int nQuarto - n�mero do quarto dentro do andar informado
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto foi desocupado corretamente
//				 bool = false - indica que quarto n�o est� ocupado por nenhum h�spede
bool	CheckOut(int nAndar, int nQuarto, QUARTO *ptrVetor)
{
	int iIndice;
	char cWork[200],
		temp;
	// <<<< 08 >>>>
	//	1 - Verificar se o quarto est� ocupado e se n�o estiver, retornar indicando o erro 
	//		Utilizar a fun��o: VerificarSeQuartoLivreOuOcupad
	if (VerificarSeQuartoLivreOuOcupado(nAndar, nQuarto, &iIndice, ptrVetor))
	{
		cout << iIndice;
		PAUSA;
		//	2 - Se estiver ocupado exibir todos os dados do quarto com sprintf_s
		//			e pedir a confirma��o do operador com S ou N.
		sprintf_s(cWork, sizeof(cWork),
			"Quarto ocupado por %d. Total de despesas: %d  Total de Diarias: %d  Total de Servicos: %d",
			(ptrVetor + iIndice)->cNomeHospede, (ptrVetor + iIndice)->dValorTotalDespesas, (ptrVetor + iIndice)->dValorTotalDiarias, (ptrVetor + iIndice)->dValorTotalServicos);
		cout << cWork << endl << "Confirmar checkout?" << endl;
		cin >> temp;

		PAUSA;

		if (temp == 's' || temp == 'S')
		{
			// 2 - Liberar o quarto para um novo h�spede somente se for digitado S ou s
			(ptrVetor + iIndice)->flgLivreOuOcupado = true;
		}
	}

	// 3 - Retornar indicando que foi tudo bem
	return true;									// !!!!!!!!!!!! para nao acusar erro de compila��o
} // CheckOut

//---[ListarDadosDeUmQuarto]-----------------------------------------------------------------------
// Fun��o para listar os dados de um quarto ocupado por um h�spede
//		
//	Par�metros:
//		Entrada: 
//			int nAndar - n�mero do andar
//			int nQuarto - n�mero do quarto dentro do andar informado
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto foi listado corretamente
//				 bool = false - indica que quarto n�o est� ocupado por nenhum h�spede
bool ListarDadosDeUmQuarto(int nAndar, int nQuarto, QUARTO *ptrVetor)
{
	char cWork[150];								// para o sprintf_s
	// <<<< 09 >>>> - Valor 0.5
	// 1 - Verificar se o quarto n�o est� ocupado e se n�o estiver retornar indicando o erro 
	//		Utilizar a fun��o: VerificarSeQuartoLivreOuOcupado
	// 2 - Listar os dados do quarto: andar, quarto, h�spede, valor da di�ria, valor total di�rias,
	//		valor total dos servi�os e total geral utilizando o sprintf_s
	// 3 - Dar uma parada para o operador visualizar a listagem
	// 4 - Retornar indicando que foi tudo bem
	return true;									// !!!!!!!!!!!! para nao acusar erro de compila��o
} // ListarDadosDeUmQuarto

//---[VerificarSeQuartoLivreOuOcupado]-----------------------------------------------------
// Fun��o para verificar se um quarto est� livre ou ocupado por um h�spede
//		
//	Par�metros:
//		Entrada: 
//			int nAndar - n�mero do andar
//			int nQuarto - n�mero do quarto dentro do andar informado
//			int *ptrIndice - valor do �ndice calculado do quarto desejado
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto est� ocupado por um h�spede
//				 bool = false - indica que quarto n�o est� ocupado por nenhum h�spede
bool VerificarSeQuartoLivreOuOcupado(int nAndar, int nQuarto, int *ptrIndice, QUARTO *ptrVetor)
{
	// <<<< 10 >>>>
	//	1 - Calcular o �ndice do quarto em fun��o do andar, quartos por andar e quarto no
	//		andar.
	*ptrIndice = QTDE_ANDARES * (nAndar - 1) + (nQuarto - 1);

	//	2 - Verificar se o quarto est� ocupado e se estiver retornar true
	//		e caso contr�rio retornar false 
	if ((ptrVetor + *ptrIndice)->flgLivreOuOcupado == true)
	{
		return true;
	}
	else
	{
		return false;
	}
} // VerificarSeQuartoLivreOuOcupado


//---[LancarServico]----------------------------------------------------------------------------
// Fun��o para lan�ar servi�os em um quarto do hotel ocupado por um h�spede
//		
//	Par�metros:
//		Entrada: 
//			int nAndar - n�mero do andar
//			int nQuarto - n�mero do quarto dentro do andar informado
//			double dValorServico - valor do servi�o utilizado pelo h�spede do hotel 
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto est� ocupado e o servi�o foi lan�ado corretamente
//				 bool = false - indica que o quarto n�o est� ocupado por nenhum h�spede
bool LancarServico(int nAndar, int nQuarto, double dValorServico, QUARTO *ptrVetor)
{
	int iIndice;
	// <<<< 11 >>>>
	// 1 - Verificar se o quarto n�o est� ocupado e se n�o estiver retornar indicando o erro 
	//		Utilizar a fun��o: VerificarSeQuartoLivreOuOcupado
	if (VerificarSeQuartoLivreOuOcupado(nAndar, nQuarto, &iIndice, ptrVetor))
	{
		(ptrVetor + iIndice)->dValorTotalServicos += dValorServico;
	}
	// 2 - Adicionar o valor do servi�o no totalizador adequado e no total geral do quarto
	// 3 - Retornar indicando que foi tudo bem
	return true;									// !!!!!!!!!!!! para nao acusar erro de compila��o
} // LancarServico

//---[LancarDiarias]----------------------------------------------------------------------------
// Fun��o para lan�ar as di�rias correspondentes em todos os quartos ocupados do hotel
//	Par�metros:
//		Entrada:
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//			int nQtdeQuartos - quantidade de quartos do hotel
//		Retorno: nenhum
void LancarDiarias(QUARTO *ptrVetor, int nQtdeQuartos)
{
	SYSTEMTIME stTime;
	char temp;
	int i;
	// <<<< 12 >>>>
	//	1 - Perguntar ao operador: "Vai lan�ar di�rias �s hh:mm (S ou N): 
	//		Se o operador responder qualquer coisa que n�o S ou s retornar da fun��o
	cout << "Lancar diaria as " << stTime << endl;
	cin >> temp;
	if (temp == 's' || temp == 'S')
	{
		for (i = 0; i < (nQtdeQuartos); i++)
		{
			if (ptrVetor[i].flgLivreOuOcupado == true)
			{
				ptrVetor[i].dValorTotalDiarias += ptrVetor[i].dValorDiaria;
			}
		}
	}
	//	2 - Fazer um loop verificando se cada quarto estiver ocupado. 
	//			Se estiver somar a di�ria que est� em dValorDiaria em
	//				dValorTotalDiarias e dValorTotalDespesas do quarto.
	// 2 - A cada di�ria lan�ada contar mais uma em um contador e somar em um totalizador geral
	// 3 - Ao final do lan�amento de todas as di�rias mostrar ao operador (na tela) quantas di�rias e o total
	//		das di�rias efetuadas...
	return ;												// !!!!!!!!!!!! para nao acusar erro de compila��o
} // LancarDiarias

