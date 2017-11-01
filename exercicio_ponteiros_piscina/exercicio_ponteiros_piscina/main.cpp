// Programa de Escola de Nata��o
// FATEC - MC - ??? - 27/09/2017 - Vers�o 0.0
#include "header.h"
//
// entry point do programa
//
void main(void)
{
	bool flgCancel;								// indica a��o cancelada - false
	int i,										// indexador e contador
		nPeriodo,								// per�odo desejado
		nRaia,									// raia desejada
		iIndice;								// indice do vetor de raias calculado
	char cOpcao,								// recebe a op��o do operador
		cWork[150],								// para o sprintf_s
		cNomeAluno[] = "Raul Ribeiro Bonif�cio";	// preencher com seu nome 
	RAIA stRaia,								// para conter os dados de uma raia
		vetRaias[QTDE_TOTAL_RAIAS];				// vetor de raias dos 3 per�odos
	SYSTEMTIME stTime;							// recebe a data e hora do sistema

	BRASIL;										// aceita acentua��o brasileira
												// <<<< 1 >>>> preencher cNomeAluno com seu nome
												// <<<< 2 >>>> fazer um loop �nico tornando todas as raias livre e
												//				em nPeriodo colocar o per�odo 1, 2 ou 3,
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
			"\n\tFATEC-MC - Escola de Nata��o - %02d/%02d/%d %02d:%02d",
			stTime.wDay, stTime.wMonth, stTime.wYear,
			stTime.wHour, stTime.wMinute);
		cout << cWork << endl;
		cout << MATRICULAR_ALUNO << " - Matricular aluno" << endl;
		cout << CANCELAR_MATRICULA << " - Cancelar Matr�cula" << endl;
		cout << LISTAR_PERIODO << " - Listar per�odo" << endl;
		cout << SAIR_DO_PROGRAMA << " - Sair do programa" << endl;
		cout << "\n\tSelecione: ";
		cin >> cOpcao;							// recebe a op��o do operador
		cOpcao = toupper(cOpcao);				// converte para mai�scula
		switch (cOpcao)							// avaliar a op��o escolhida
		{
		case MATRICULAR_ALUNO:


			// pedir um periodo v�lido ou zero para cancelar a 
			//	execu��o da a��o
			do
			{
				cout << "Informe o per�odo desejado, " << endl <<
					"\t1 - Manh�" << endl << "\t2 - Tarde" << endl << "\t3 - Noite" << endl
					<< "Ou zero para cancelar est� a��o: ";
				cin >> nPeriodo;
			} while (nPeriodo < 0 || nPeriodo > QTDE_PERIODOS);

			// chamar a fun��o que retorna a raia livre no per�odo ou
			//	retorna false se n�o tem raia livre neste per�odo
			if (!PedirRaiaNoPeriodo(vetRaias, nPeriodo, &nRaia, "Matricular aluno"))
			{	// n�o tem raia livre neste periodo
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
			//	familia � a mensalidade integral e o segundo da fam�lia (mesmo
			//	sobrenome) 10% de desconto; o terceiro da familia com 20%
			//	o quarto com 30% e os demais com 30% de desconto.
			//	Informar ao operador a raia do per�odo em que o aluno ir�
			//	 nadar e o valor da sua mensalidade.
			//	Informar que a raia agora est� ocupada por um aluno


			break;							// sai do switch e volta ao menu


		case CANCELAR_MATRICULA:
			// chamar a fun��o PedirPeriodoRaiaValidos
			//	verificar se a fun��o foi cancelada 
			if (PedirPeriodoRaiaValidos(vetRaias, &nPeriodo, &flgCancel,
				&nRaia, &iIndice, "Cancelar Matricula") == false ||
				!flgCancel)
			{
				if (!flgCancel)							// cancelou a a��o?
					break;								// volta ao menu
														// informar que a raia est� livre ao operador
														// e voltar ao menu
			}
			// tem uma raia ocupada
			//	informar os dados da raia e pedir a confirma��o do
			//		cancelamento
			//		Se n�o - voltar ao menu
			//			Se sim - libera a raia e volta ao menu
			break;							// sai do switch e volta ao menu
		case LISTAR_PERIODO:
			// 
			// pedir um periodo v�lido ou zero para cancelar e
			// fazer um cabe�alho indicando qual � o per�odo
			//	listar todas as raias ocupadas do per�odo indicando
			//		nome e sobrenome e mensalidade (sprintf_s).


			break;


		case SAIR_DO_PROGRAMA:
			cout << "Sair realmente? (S ou N): ";
			cin >> cOpcao;					// decide se sai realmente
			if (cOpcao == 'S' || cOpcao == 's')	// sair realmente?
				return;							// volta ao Sistema Operacional
			break;								// volta ao menu
		default:
			cout << "Digite uma op��o v�lida!" << endl;
			PAUSA;



		} // switch
	} // while
} // main 

// Par�metros:
//	Entrada: RAIA *ptrVetRaia - ponteiro da primeira raia da escola de nata��o
//			 int nPeriodo - per�odo desejado
//			 int *ptrRaiaLivre - ponteiro a receber a raia livre ou zero
//								 se n�o existir nenhuma raia livre no per�odo
//			 char *ptrAcao - ponteiro para a��o sendo executada (Tutela da a��o)
//	Retorno: bool - true - tem uma raia livre no per�odo informada em ptrRaiaLivre
//				    false - n�o tem raia livre no per�odo desejado
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

	return true;			// para n�o dar erro
}

// Par�metros:
//	Entrada: RAIA *ptrVetRaia - ponteiro da primeira raia da escola de nata��o
//			 int *ptrPeriodo - ponteiro a receber o per�odo desejado
//			 bool *ptrCancel - false - foi informado um per�odo zero ou 
//									raia zero indicando que a a��o foi cancelada
//			 int *ptrRaia - ponteiro a receber a raia desejada
//			 int *ptrIndice - ponteiro a receber o indice da raia calculada em 
//							fun��o do per�odo e da raia desejada se raia ocupada
//			 char *ptrAcao - ponteiro para o string que cont�m a tutela da a��o
//	Retorno: bool - true - foram informadas um per�odo e uma raia com um
//							aluno matriculado
//					false - o que foi digitado como periodo e raia indica que
//							a raia n�o tem aluno matriculado
bool PedirPeriodoRaiaValidos(RAIA *ptrVetRaia, int *ptrPeriodo, bool *ptrCancel, int *ptrRaia, int *ptrIndice, char *ptrAcao)
{
	return true;
	/*
	for (int i = 0; i < QTDE_PERIODOS; i++)
	{
		if ()
	}
	*/


	return true;				// para n�o dar erro
}
