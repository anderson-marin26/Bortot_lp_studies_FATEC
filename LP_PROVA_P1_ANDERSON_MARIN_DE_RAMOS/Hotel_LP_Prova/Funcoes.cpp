// Funções do programa de hotel
#include <iostream>
#include <windows.h>
#include "Hotel.h"
using namespace std;

//---[CheckIn]--------------------------------------------------------------------
// Função para fazer o check-in de um hóspede em um quarto do hotel
//		
//	Parâmetros:
//		Entrada: 
//			int nAndar - número do andar
//			int nQuarto - número do quarto dentro do andar informado
//			char *ptrHospede - ponteiro para o nome do hóspede
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto foi ocupado corretamente
//				 bool = false - indica que quarto está ocupado por outro hóspede
//								e não foi liberado por um check-out anterior
bool	CheckIn(int nAndar, int nQuarto, char *ptrHospede, QUARTO *ptrVetor)
{
	// <<<< 08 >>>>
	// 1 - Verificar se o quarto está ocupado e se estiver 
	//		informar o nome do hóspede dar uma pausa e retornar indicando o erro 
	int iIndice;
	iIndice = QTDE_ANDARES * (nAndar - 1) + (nQuarto - 1); // pegando indice

	if ((ptrVetor + iIndice)->flgLivreOuOcupado == true)
	{
		cout << "Quarto ocupado por " << (ptrVetor + iIndice)->cNomeHospede;
		PAUSA;

		return false;
	}

	// 2 - Associar o quarto ao hóspede: ocupando o quarto, movendo o nome do hóspede 
	//	e zerar os valores de totais de diárias, de serviços e despesas
	strcpy_s((ptrVetor + iIndice)->cNomeHospede, ptrHospede);
	(ptrVetor + iIndice)->flgLivreOuOcupado = true;
	(ptrVetor + iIndice)->dValorTotalDespesas = 0;
	(ptrVetor + iIndice)->dValorTotalDiarias = 0;
	(ptrVetor + iIndice)->dValorTotalServicos = 0;

	// 3 - Retornar indicando que foi tudo bem
	return true;			// !!!!!!!!!!!! para nao acusar erro de compilação
} // CheckIn

//---[CheckOut]--------------------------------------------------------------------
// Função para fazer o check-out de um quarto que tem um hóspede
//		
//	Parâmetros:
//		Entrada: 
//			int nAndar - número do andar
//			int nQuarto - número do quarto dentro do andar informado
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto foi desocupado corretamente
//				 bool = false - indica que quarto não está ocupado por nenhum hóspede
bool	CheckOut(int nAndar, int nQuarto, QUARTO *ptrVetor)
{
	int iIndice;
	char cWork[200],
		temp;
	// <<<< 08 >>>>
	//	1 - Verificar se o quarto está ocupado e se não estiver, retornar indicando o erro 
	//		Utilizar a função: VerificarSeQuartoLivreOuOcupad
	if (VerificarSeQuartoLivreOuOcupado(nAndar, nQuarto, &iIndice, ptrVetor))
	{
		cout << iIndice;
		PAUSA;
		//	2 - Se estiver ocupado exibir todos os dados do quarto com sprintf_s
		//			e pedir a confirmação do operador com S ou N.
		sprintf_s(cWork, sizeof(cWork),
			"Quarto ocupado por %d. Total de despesas: %d  Total de Diarias: %d  Total de Servicos: %d",
			(ptrVetor + iIndice)->cNomeHospede, (ptrVetor + iIndice)->dValorTotalDespesas, (ptrVetor + iIndice)->dValorTotalDiarias, (ptrVetor + iIndice)->dValorTotalServicos);
		cout << cWork << endl << "Confirmar checkout?" << endl;
		cin >> temp;

		PAUSA;

		if (temp == 's' || temp == 'S')
		{
			// 2 - Liberar o quarto para um novo hóspede somente se for digitado S ou s
			(ptrVetor + iIndice)->flgLivreOuOcupado = true;
		}
	}

	// 3 - Retornar indicando que foi tudo bem
	return true;									// !!!!!!!!!!!! para nao acusar erro de compilação
} // CheckOut

//---[ListarDadosDeUmQuarto]-----------------------------------------------------------------------
// Função para listar os dados de um quarto ocupado por um hóspede
//		
//	Parâmetros:
//		Entrada: 
//			int nAndar - número do andar
//			int nQuarto - número do quarto dentro do andar informado
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto foi listado corretamente
//				 bool = false - indica que quarto não está ocupado por nenhum hóspede
bool ListarDadosDeUmQuarto(int nAndar, int nQuarto, QUARTO *ptrVetor)
{
	char cWork[150];								// para o sprintf_s
	// <<<< 09 >>>> - Valor 0.5
	// 1 - Verificar se o quarto não está ocupado e se não estiver retornar indicando o erro 
	//		Utilizar a função: VerificarSeQuartoLivreOuOcupado
	// 2 - Listar os dados do quarto: andar, quarto, hóspede, valor da diária, valor total diárias,
	//		valor total dos serviços e total geral utilizando o sprintf_s
	// 3 - Dar uma parada para o operador visualizar a listagem
	// 4 - Retornar indicando que foi tudo bem
	return true;									// !!!!!!!!!!!! para nao acusar erro de compilação
} // ListarDadosDeUmQuarto

//---[VerificarSeQuartoLivreOuOcupado]-----------------------------------------------------
// Função para verificar se um quarto está livre ou ocupado por um hóspede
//		
//	Parâmetros:
//		Entrada: 
//			int nAndar - número do andar
//			int nQuarto - número do quarto dentro do andar informado
//			int *ptrIndice - valor do índice calculado do quarto desejado
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto está ocupado por um hóspede
//				 bool = false - indica que quarto não está ocupado por nenhum hóspede
bool VerificarSeQuartoLivreOuOcupado(int nAndar, int nQuarto, int *ptrIndice, QUARTO *ptrVetor)
{
	// <<<< 10 >>>>
	//	1 - Calcular o índice do quarto em função do andar, quartos por andar e quarto no
	//		andar.
	*ptrIndice = QTDE_ANDARES * (nAndar - 1) + (nQuarto - 1);

	//	2 - Verificar se o quarto está ocupado e se estiver retornar true
	//		e caso contrário retornar false 
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
// Função para lançar serviços em um quarto do hotel ocupado por um hóspede
//		
//	Parâmetros:
//		Entrada: 
//			int nAndar - número do andar
//			int nQuarto - número do quarto dentro do andar informado
//			double dValorServico - valor do serviço utilizado pelo hóspede do hotel 
//			QUARTO *ptrVetor - ponteiro para o vetor de quartos
//		Retorno: bool = true - indica que o quarto está ocupado e o serviço foi lançado corretamente
//				 bool = false - indica que o quarto não está ocupado por nenhum hóspede
bool LancarServico(int nAndar, int nQuarto, double dValorServico, QUARTO *ptrVetor)
{
	int iIndice;
	// <<<< 11 >>>>
	// 1 - Verificar se o quarto não está ocupado e se não estiver retornar indicando o erro 
	//		Utilizar a função: VerificarSeQuartoLivreOuOcupado
	if (VerificarSeQuartoLivreOuOcupado(nAndar, nQuarto, &iIndice, ptrVetor))
	{
		(ptrVetor + iIndice)->dValorTotalServicos += dValorServico;
	}
	// 2 - Adicionar o valor do serviço no totalizador adequado e no total geral do quarto
	// 3 - Retornar indicando que foi tudo bem
	return true;									// !!!!!!!!!!!! para nao acusar erro de compilação
} // LancarServico

//---[LancarDiarias]----------------------------------------------------------------------------
// Função para lançar as diárias correspondentes em todos os quartos ocupados do hotel
//	Parâmetros:
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
	//	1 - Perguntar ao operador: "Vai lançar diárias às hh:mm (S ou N): 
	//		Se o operador responder qualquer coisa que não S ou s retornar da função
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
	//			Se estiver somar a diária que está em dValorDiaria em
	//				dValorTotalDiarias e dValorTotalDespesas do quarto.
	// 2 - A cada diária lançada contar mais uma em um contador e somar em um totalizador geral
	// 3 - Ao final do lançamento de todas as diárias mostrar ao operador (na tela) quantas diárias e o total
	//		das diárias efetuadas...
	return ;												// !!!!!!!!!!!! para nao acusar erro de compilação
} // LancarDiarias

