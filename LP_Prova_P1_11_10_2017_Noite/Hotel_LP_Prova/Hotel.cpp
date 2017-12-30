// Hotel.cpp - Programa de Hotel para prova de Linguagem de Programa��o - 10/10/2017
// FATEC - Mogi das Cruzes Prof.Mestre Jos� Carlos Bortot
#include <iostream>
#include <windows.h>
#include "Hotel.h"
using namespace std;
//
// Fun��o que pede um andar v�lido e um quarto v�lido dentro do andar
//	Par�metros:
//		Entrada: int *ptrAndar - ponteiro de uma inteira que receber� o andar
//								ou zero para cancelar a transa��o.
//
//				 int *ptrQuarto - ponteiro de uma inteira que receber� um 
//								quarto dentro do andar ou zero para cancelar a
//								transa��o
//				 char *ptrAcao - ponteiro de um string que cont�m a a��o desejada
//		Retorno: bool - true - foi informado um andar normal (n�o em reforma) e
//								um quarto v�lido dentro do andar.
//						false - o operador cancelou a transa��o
bool PedirAndarQuarto(int *ptrAndar, int *ptrQuarto, char *ptrAcao)
{
	return true;						// para n�o dar erro
}
//
// Fun��o principal
//
void main(void)
{
	int  i,									// indice gen�rico
		nAndarHotel,						// para receber o n�mero do andar
		nQuartoHotel;						// para receber o n�mero do quarto dentro do andar
	char cOpcaoOper,						// local para receber a op��o escolhida do menu
		cNomeAluno[] = "Informe aqui seu nome", // para ser informado se nome
		cWork[200],							// para o sprintf_s
		cNomeHospede[TAM_NOME_HOSPEDE + 1];	// local para receber o nome do h�spede do hotel
	double dValor;							// local para receber o valor dos servi�os do hotel
	QUARTO stQuarto,						// para conter os dados de um quarto
		vetQuartos[QTDE_TOTAL_QUARTOS];		// vetor de todos os quartos do hotel
	SYSTEMTIME stTime;						// para buscar data e hora
	BRASIL;									// acentua��o brasileira
	SetConsoleTitle("FATEC-MC - Sistema de Hotel");
	// <<<< 01 >>>>
	// Digite seu nome em cNomeAluno
	//
	// <<<< 02 >>>>
	// Fazer a inicializa��o do vetor de quarto em um loop apenas:
	//	for.... e for.... aninhado
	//	Dentro deste loop indicar que todos os quartos do hotel est�o livres
	//	Dentro deste loop indicar que todos os quartos s�o normais exceto os 
	//		que est�o em reforma
	//	Dentro deste mesmo loop indicar o andar que ser� de 1 a QTDE_ANDARES
	//	Dentro deste mesmo loop indicar o quarto do andar de 1 a QTDE_TOTAL_QUARTOS
	//	E nesse mesmo loop mover para cada quarto do andar a di�ria correspondente
	//		que foi definido na tabela de di�rias no Hotel.h
	//
	//
	while(true)								// loop infinito
	{
		LIMPAR_TELA;
		GetLocalTime(&stTime);				// busca data e hora do sistema
		// Mostrar o menu de op��es para o operador
		sprintf_s(cWork, sizeof(cWork),
			"\n\tFATEC-MC-Sistema de Hotel %02d/%02d/%d %02d:%02d\n\tOperador: %s",
			stTime.wDay, stTime.wMonth, stTime.wYear,
			stTime.wHour, stTime.wMinute, cNomeAluno);
		cout << cWork << endl;
		cout << FAZER_CHECK_IN << " - Check-in de um hospede" << endl;
		cout << FAZER_CHECK_OUT << " - Check-out de um hospede" << endl;
		cout << LANCAR_SERVICO << " - Lancar servicos" << endl;
		cout << LANCAR_DIARIA << " - Lancar diarias em todos os quartos ocupados" << endl;
		cout << LISTAR_UM_QUARTO << " - Listar um quarto" << endl;
		cout << SAIR_DO_PROGRAMA <<  " - Sair do programa" << endl;
		cout << "\n\tSelecione: ";
		cin	 >> cOpcaoOper;					// op��o escolhida pelo operador
		cOpcaoOper = toupper(cOpcaoOper);	// converte para upper case a op��o escolhida
		switch(cOpcaoOper)					// avaliar a op��o que foi escolhida pelo operador
		{
			case FAZER_CHECK_IN:
				// <<<< 03 >>>>
				// 1 - Pedir o andar e quarto atrav�s da fun��o PedirAndarQuarto 
				// 3 - Chamar a fun��o que verifica se o quarto indicado est� livre ou ocupado
				//			Utilizar a fun��o:  VerificarSeQuartoLivreOuOcupado
				//		Se o quarto estiver ocupado voltar ao menu
				// 4 - Pedir o nome do h�spede (Pode ter espa�os entre os nomes)
				// 4 - Chamar a fun��o que faz o check-in do h�spede
				//     Se o retorno for true - o check-in foi ok e caso contr�rio
				//	   avisar ao operador e retornar ao menu
				break;						// para sair do switch e voltar ao menu
			case FAZER_CHECK_OUT:
				// <<<< 03 >>>>
				// 1 - Pedir o andar e o quarto da mesma forma que no item anterior 
				// 2 - Chamar a fun��o que verifica se o quarto est� ocupado
				//			Utilizar a fun��o:  VerificarSeQuartoLivreOuOcupado
				//		Se o quarto n�o estiver ocupado avisar ao operador
				//			e voltar ao menu
				// 3 - Chamar a fun��o que faz o check-out do quarto.
				break;						// para sair do switch e voltar ao menu
			case LANCAR_SERVICO:
				// <<<< 04 >>>>
				// 1 - Pedir o Andar e Quarto da mesma forma que foi feito nos itens anteriores
				// 2 - Verificar se o quarto est� ocupado e se n�o estiver avisar ao operador e
				//		voltar ao menu.
				//			Utilizar a fun��o:  VerificarSeQuartoLivreOuOcupado
				// 3 - Pedir o tipo de servi�o que tem que ser um dos que est�o no arquivo hotel.h
				//		exceto a di�ria que lan�ada de outra forma.
				//		Se n�o for informado um servi�o v�lido, pedir novamente ao operador
				// 4 - Pedir o valor do servi�o 
				// 5 - Chamar a fun��o que lan�a o servi�o no quarto informado
				break;						// para sair do switch e voltar ao menu
			case LANCAR_DIARIA:
				// <<<< 05 >>>>
				//	1 - Chamar a fun��o que lan�a di�ria.
				break;						// para sair do switch e voltar ao menu
			case LISTAR_UM_QUARTO:
				// <<<< 06 >>>>
				// 1 - Pedir Andar e Quarto conforme itens anteriores
				// 2 - Verificar se o quarto est� ocupado e se n�o estiver, avisar ao operador e voltar ao menu
				// 3 - Se estiver ocupado, chamar a fun��o que lista os dados do quarto
				break;						// para sair do switch e voltar ao menu
			case SAIR_DO_PROGRAMA:
				cout << "Vai sair realmente? (S ou N): ";
				cin >> cOpcaoOper;			// recebe S ou N ou qualquer outra tecla
				if(cOpcaoOper == 'S' || cOpcaoOper == 's')	// sair realmente?
					return;					// volta ao sistema operacional
				break;						// para sair do switch e decidir se vai sair realmente
			default:
				// Avisar que foi escolhida uma op��o errada
				cout << "\nOpcao errada!!!";
		} // switch
		// <<<< 07 >>>> - Valor 0.50
		// 1 - Verificar se a op��o escolhida foi sair do programa 
		//     caso n�o seja, continuar no loop infinito
		// 2 - Pedir a confirma��o, ao operador se vai sair realmente do programa atrav�s de um S ou N
		//	   Se a resposta do operador foi 'S' encerrar o programa e caso contr�rio continuar no
		//     loop infinito
	} // while(true)
} // main
