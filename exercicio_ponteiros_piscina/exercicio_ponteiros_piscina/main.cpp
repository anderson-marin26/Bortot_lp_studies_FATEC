// Programa de Escola de Natação
// FATEC - MC - ??? - 27/09/2017 - Versão 0.0
#include "header.h"
//
// entry point do programa
//
void main(void)
{
	bool flgCancel;								// indica ação cancelada - false
	int i,										// indexador e contador
		nPeriodo,								// período desejado
		nRaia,									// raia desejada
		iIndice;								// indice do vetor de raias calculado
	char cOpcao,								// recebe a opção do operador
		cWork[150],								// para o sprintf_s
		cNomeAluno[] = "Raul Ribeiro Bonifácio";	// preencher com seu nome 
	RAIA stRaia,								// para conter os dados de uma raia
		vetRaias[QTDE_TOTAL_RAIAS];				// vetor de raias dos 3 períodos
	SYSTEMTIME stTime;							// recebe a data e hora do sistema

	BRASIL;										// aceita acentuação brasileira
												// <<<< 1 >>>> preencher cNomeAluno com seu nome
												// <<<< 2 >>>> fazer um loop único tornando todas as raias livre e
												//				em nPeriodo colocar o período 1, 2 ou 3,
												//				e na nRaia colocar 1, 2, 3 ........10

												// loop infinito


												//Loop para preencher as raias com os valores default
	for (int i = 0; i < QTDE_RAIAS_DA_PISCINA; i++)
	{
		if ((ptrVetRaia + i)->nPeriodo == nPeriodo && (ptrVetRaia + i)->flgLivreOcupada == true)
		{
			continue;
		}
		else
		{
			*ptrRaiaLivre = (ptrVetRaia + i)->nRaia;

			return true;
		}
	}


	while (true)
	{
		LIMPAR_TELA;
		GetLocalTime(&stTime);					// busca a data e hora do sistema
		sprintf_s(cWork, sizeof(cWork),
			"\n\tFATEC-MC - Escola de Natação - %02d/%02d/%d %02d:%02d",
			stTime.wDay, stTime.wMonth, stTime.wYear,
			stTime.wHour, stTime.wMinute);
		cout << cWork << endl;
		cout << MATRICULAR_ALUNO << " - Matricular aluno" << endl;
		cout << CANCELAR_MATRICULA << " - Cancelar Matrícula" << endl;
		cout << LISTAR_PERIODO << " - Listar período" << endl;
		cout << SAIR_DO_PROGRAMA << " - Sair do programa" << endl;
		cout << "\n\tSelecione: ";
		cin >> cOpcao;							// recebe a opção do operador
		cOpcao = toupper(cOpcao);				// converte para maiúscula
		switch (cOpcao)							// avaliar a opção escolhida
		{
		case MATRICULAR_ALUNO:


			// pedir um periodo válido ou zero para cancelar a 
			//	execução da ação
			do
			{
				cout << "Informe o período desejado, " << endl <<
					"\t1 - Manhã" << endl << "\t2 - Tarde" << endl << "\t3 - Noite" << endl
					<< "Ou zero para cancelar está ação: ";
				cin >> nPeriodo;
			} while (nPeriodo < 0 || nPeriodo > QTDE_PERIODOS);

			// chamar a função que retorna a raia livre no período ou
			//	retorna false se não tem raia livre neste período
			if (!PedirRaiaNoPeriodo(vetRaias, nPeriodo, &nRaia, "Matricular aluno"))
			{	// não tem raia livre neste periodo
				cout << "Sem raia livre no periodo." << endl;
				PAUSA;
				break;
			}


			// Se tiver raia livre pedir primeiro nome com cin.getline e
			cout << "Primeiro nome: " << endl;
			cin.ignore(1, EOF);
			cin.getline()
			//	pedir sobrenome com cin.getline
			//	Calcular o valor da mensalidade sendo que o primeiro da
			//	familia é a mensalidade integral e o segundo da família (mesmo
			//	sobrenome) 10% de desconto; o terceiro da familia com 20%
			//	o quarto com 30% e os demais com 30% de desconto.
			//	Informar ao operador a raia do período em que o aluno irá
			//	 nadar e o valor da sua mensalidade.
			//	Informar que a raia agora está ocupada por um aluno


			break;							// sai do switch e volta ao menu


		case CANCELAR_MATRICULA:
			// chamar a função PedirPeriodoRaiaValidos
			//	verificar se a função foi cancelada 
			if (PedirPeriodoRaiaValidos(vetRaias, &nPeriodo, &flgCancel,
				&nRaia, &iIndice, "Cancelar Matricula") == false ||
				!flgCancel)
			{
				if (!flgCancel)							// cancelou a ação?
					break;								// volta ao menu
														// informar que a raia está livre ao operador
														// e voltar ao menu
			}
			// tem uma raia ocupada
			//	informar os dados da raia e pedir a confirmação do
			//		cancelamento
			//		Se não - voltar ao menu
			//			Se sim - libera a raia e volta ao menu
			break;							// sai do switch e volta ao menu
		case LISTAR_PERIODO:
			// 
			// pedir um periodo válido ou zero para cancelar e
			// fazer um cabeçalho indicando qual é o período
			//	listar todas as raias ocupadas do período indicando
			//		nome e sobrenome e mensalidade (sprintf_s).


			break;


		case SAIR_DO_PROGRAMA:
			cout << "Sair realmente? (S ou N): ";
			cin >> cOpcao;					// decide se sai realmente
			if (cOpcao == 'S' || cOpcao == 's')	// sair realmente?
				return;							// volta ao Sistema Operacional
			break;								// volta ao menu
		default:
			cout << "Digite uma opção válida!" << endl;
			PAUSA;



		} // switch
	} // while
} // main 

// Parâmetros:
//	Entrada: RAIA *ptrVetRaia - ponteiro da primeira raia da escola de natação
//			 int nPeriodo - período desejado
//			 int *ptrRaiaLivre - ponteiro a receber a raia livre ou zero
//								 se não existir nenhuma raia livre no período
//			 char *ptrAcao - ponteiro para ação sendo executada (Tutela da ação)
//	Retorno: bool - true - tem uma raia livre no período informada em ptrRaiaLivre
//				    false - não tem raia livre no período desejado
bool PedirRaiaNoPeriodo(RAIA *ptrVetRaia, int nPeriodo, int *ptrRaiaLivre, char *ptrAcao)
{
	// inicializar vetor
	for (int i = 0; i < QTDE_RAIAS_DA_PISCINA; i++)
	{
		if ((ptrVetRaia + i)->nPeriodo == nPeriodo && (ptrVetRaia + i)->flgLivreOcupada == true)
		{
			continue;
		}
		else
		{
			*ptrRaiaLivre = (ptrVetRaia + i)->nRaia;

			return true;
		}
	}

	*ptrRaiaLivre = 0;

	return true;			// para não dar erro
}

// Parâmetros:
//	Entrada: RAIA *ptrVetRaia - ponteiro da primeira raia da escola de natação
//			 int *ptrPeriodo - ponteiro a receber o período desejado
//			 bool *ptrCancel - false - foi informado um período zero ou 
//									raia zero indicando que a ação foi cancelada
//			 int *ptrRaia - ponteiro a receber a raia desejada
//			 int *ptrIndice - ponteiro a receber o indice da raia calculada em 
//							função do período e da raia desejada se raia ocupada
//			 char *ptrAcao - ponteiro para o string que contém a tutela da ação
//	Retorno: bool - true - foram informadas um período e uma raia com um
//							aluno matriculado
//					false - o que foi digitado como periodo e raia indica que
//							a raia não tem aluno matriculado
bool PedirPeriodoRaiaValidos(RAIA *ptrVetRaia, int *ptrPeriodo, bool *ptrCancel, int *ptrRaia, int *ptrIndice, char *ptrAcao)
{
	return true;
	/*
	for (int i = 0; i < QTDE_PERIODOS; i++)
	{
		if ()
	}
	*/


	return true;				// para não dar erro
}
