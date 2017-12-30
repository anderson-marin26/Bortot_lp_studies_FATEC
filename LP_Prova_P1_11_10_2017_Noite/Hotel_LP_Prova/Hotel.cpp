// Hotel.cpp - Programa de Hotel para prova de Linguagem de Programação - 10/10/2017
// FATEC - Mogi das Cruzes Prof.Mestre José Carlos Bortot
#include <iostream>
#include <windows.h>
#include "Hotel.h"
using namespace std;
//
// Função que pede um andar válido e um quarto válido dentro do andar
//	Parâmetros:
//		Entrada: int *ptrAndar - ponteiro de uma inteira que receberá o andar
//								ou zero para cancelar a transação.
//
//				 int *ptrQuarto - ponteiro de uma inteira que receberá um 
//								quarto dentro do andar ou zero para cancelar a
//								transação
//				 char *ptrAcao - ponteiro de um string que contém a ação desejada
//		Retorno: bool - true - foi informado um andar normal (não em reforma) e
//								um quarto válido dentro do andar.
//						false - o operador cancelou a transação
bool PedirAndarQuarto(int *ptrAndar, int *ptrQuarto, char *ptrAcao)
{
	return true;						// para não dar erro
}
//
// Função principal
//
void main(void)
{
	int  i,									// indice genérico
		nAndarHotel,						// para receber o número do andar
		nQuartoHotel;						// para receber o número do quarto dentro do andar
	char cOpcaoOper,						// local para receber a opção escolhida do menu
		cNomeAluno[] = "Informe aqui seu nome", // para ser informado se nome
		cWork[200],							// para o sprintf_s
		cNomeHospede[TAM_NOME_HOSPEDE + 1];	// local para receber o nome do hóspede do hotel
	double dValor;							// local para receber o valor dos serviços do hotel
	QUARTO stQuarto,						// para conter os dados de um quarto
		vetQuartos[QTDE_TOTAL_QUARTOS];		// vetor de todos os quartos do hotel
	SYSTEMTIME stTime;						// para buscar data e hora
	BRASIL;									// acentuação brasileira
	SetConsoleTitle("FATEC-MC - Sistema de Hotel");
	// <<<< 01 >>>>
	// Digite seu nome em cNomeAluno
	//
	// <<<< 02 >>>>
	// Fazer a inicialização do vetor de quarto em um loop apenas:
	//	for.... e for.... aninhado
	//	Dentro deste loop indicar que todos os quartos do hotel estão livres
	//	Dentro deste loop indicar que todos os quartos são normais exceto os 
	//		que estão em reforma
	//	Dentro deste mesmo loop indicar o andar que será de 1 a QTDE_ANDARES
	//	Dentro deste mesmo loop indicar o quarto do andar de 1 a QTDE_TOTAL_QUARTOS
	//	E nesse mesmo loop mover para cada quarto do andar a diária correspondente
	//		que foi definido na tabela de diárias no Hotel.h
	//
	//
	while(true)								// loop infinito
	{
		LIMPAR_TELA;
		GetLocalTime(&stTime);				// busca data e hora do sistema
		// Mostrar o menu de opções para o operador
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
		cin	 >> cOpcaoOper;					// opção escolhida pelo operador
		cOpcaoOper = toupper(cOpcaoOper);	// converte para upper case a opção escolhida
		switch(cOpcaoOper)					// avaliar a opção que foi escolhida pelo operador
		{
			case FAZER_CHECK_IN:
				// <<<< 03 >>>>
				// 1 - Pedir o andar e quarto através da função PedirAndarQuarto 
				// 3 - Chamar a função que verifica se o quarto indicado está livre ou ocupado
				//			Utilizar a função:  VerificarSeQuartoLivreOuOcupado
				//		Se o quarto estiver ocupado voltar ao menu
				// 4 - Pedir o nome do hóspede (Pode ter espaços entre os nomes)
				// 4 - Chamar a função que faz o check-in do hóspede
				//     Se o retorno for true - o check-in foi ok e caso contrário
				//	   avisar ao operador e retornar ao menu
				break;						// para sair do switch e voltar ao menu
			case FAZER_CHECK_OUT:
				// <<<< 03 >>>>
				// 1 - Pedir o andar e o quarto da mesma forma que no item anterior 
				// 2 - Chamar a função que verifica se o quarto está ocupado
				//			Utilizar a função:  VerificarSeQuartoLivreOuOcupado
				//		Se o quarto não estiver ocupado avisar ao operador
				//			e voltar ao menu
				// 3 - Chamar a função que faz o check-out do quarto.
				break;						// para sair do switch e voltar ao menu
			case LANCAR_SERVICO:
				// <<<< 04 >>>>
				// 1 - Pedir o Andar e Quarto da mesma forma que foi feito nos itens anteriores
				// 2 - Verificar se o quarto está ocupado e se não estiver avisar ao operador e
				//		voltar ao menu.
				//			Utilizar a função:  VerificarSeQuartoLivreOuOcupado
				// 3 - Pedir o tipo de serviço que tem que ser um dos que estão no arquivo hotel.h
				//		exceto a diária que lançada de outra forma.
				//		Se não for informado um serviço válido, pedir novamente ao operador
				// 4 - Pedir o valor do serviço 
				// 5 - Chamar a função que lança o serviço no quarto informado
				break;						// para sair do switch e voltar ao menu
			case LANCAR_DIARIA:
				// <<<< 05 >>>>
				//	1 - Chamar a função que lança diária.
				break;						// para sair do switch e voltar ao menu
			case LISTAR_UM_QUARTO:
				// <<<< 06 >>>>
				// 1 - Pedir Andar e Quarto conforme itens anteriores
				// 2 - Verificar se o quarto está ocupado e se não estiver, avisar ao operador e voltar ao menu
				// 3 - Se estiver ocupado, chamar a função que lista os dados do quarto
				break;						// para sair do switch e voltar ao menu
			case SAIR_DO_PROGRAMA:
				cout << "Vai sair realmente? (S ou N): ";
				cin >> cOpcaoOper;			// recebe S ou N ou qualquer outra tecla
				if(cOpcaoOper == 'S' || cOpcaoOper == 's')	// sair realmente?
					return;					// volta ao sistema operacional
				break;						// para sair do switch e decidir se vai sair realmente
			default:
				// Avisar que foi escolhida uma opção errada
				cout << "\nOpcao errada!!!";
		} // switch
		// <<<< 07 >>>> - Valor 0.50
		// 1 - Verificar se a opção escolhida foi sair do programa 
		//     caso não seja, continuar no loop infinito
		// 2 - Pedir a confirmação, ao operador se vai sair realmente do programa através de um S ou N
		//	   Se a resposta do operador foi 'S' encerrar o programa e caso contrário continuar no
		//     loop infinito
	} // while(true)
} // main
