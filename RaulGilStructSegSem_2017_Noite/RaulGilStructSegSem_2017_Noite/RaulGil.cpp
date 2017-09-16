// Programa de calouros Raul Gil com struct
// FATEC - MC - Anderson Marin de Ramos - 06/09/2017 - Versão 0.0
#include "RaulGil.h"
//
// entry point do programa
//
void main(void)
{
	int i, j,						// indices e contadores
		nNotaTrono = -1,			// nota do trono
		iIndice,					// indice do calouro que esta no trono
		nQtde;						// qtde de calouros que irá cantar hoje
	CALOURO stCalouro,				// struct para conter os dados de um calouro
		vetCalouros[QTDE_MAXIMA];	// vetor de calouros
	BRASIL;

	// Pedir quantidade de calouros
	do
	{
		cout << "Quantidade de calouros que irá cantar hoje (" << QTDE_MINIMA << " e " << QTDE_MAXIMA << ")" << endl << "Ou zero para cancelar a execução do programa: ";
		cin >> nQtde;

		// Cancelar
		if (nQtde == 0)
		{
			return;
		}
	} while (nQtde < QTDE_MINIMA || nQtde > QTDE_MAXIMA);

	// Receber calouros
	for (i = 0; i < nQtde; i++)
	{
		cin.ignore(1, EOF);

		// nome
		do
		{
			cout << "Nome do calouro de ordem " << i + 1 << " de " << nQtde << ": ";
			cin.getline(vetCalouros[i].cNomeCalouro, TAMANHO_NOME, '\n');
		} while (strnlen_s(vetCalouros[i].cNomeCalouro, TAMANHO_NOME) < 5);

		// sexo
		do
		{
			cout << "Sexo do calouro " << vetCalouros[i].cNomeCalouro << "(" << MASCULINO << "-Masculino e " << FEMININO << "-Feminino): ";
			cin >> vetCalouros[i].cSexoCalouro;
			vetCalouros[i].cSexoCalouro = toupper(vetCalouros[i].cSexoCalouro);
		} while (vetCalouros[i].cSexoCalouro != MASCULINO && vetCalouros[i].cSexoCalouro != FEMININO);

		// nota
		do
		{
			cout << "Nota do calouro entre 0 e 10: ";
			cin >> vetCalouros[i].nNotaCalouro;
		} while (vetCalouros[i].nNotaCalouro < 0 || vetCalouros[i].nNotaCalouro > 10);

		/*
		** Verificar se o calouro vai para o trono
		*/
		if (vetCalouros[i].nNotaCalouro > nNotaTrono)
		{
			nNotaTrono = vetCalouros[i].nNotaCalouro;
			iIndice = i;
		}

	}// for i
	

	cout << "O vencedor: " << vetCalouros[iIndice].cNomeCalouro << " Sexo: " << vetCalouros[iIndice].cSexoCalouro << " Nota: " << vetCalouros[iIndice].nNotaCalouro << endl;

	PAUSA;


} // main

void BubbleSort(int nQt, CALOURO vtCalouros[], bool flgTipoSort)
{
	int i;
	bool flgHouveTroca = false;
	CALOURO stAuxiliar;

	do
	{
		for (i = 0, flgHouveTroca = false; i < nQt -1; i++)
		{
			if ((flgTipoSort == true && strcmp(vtCalouros[i].cNomeCalouro, vtCalouros[i + 1].cNomeCalouro) > 0) || (!flgTipoSort && vtCalouros[i].nNotaCalouro > vtCalouros[i + 1].nNotaCalouro))
			{
				// salva elem[i] no auxiliar
				memcpy_s(&stAuxiliar, sizeof(CALOURO), &vtCalouros[i], sizeof(CALOURO));

				// troca o elem[i + 1]
				memcpy_s(&vtCalouros[i], sizeof(CALOURO), &vtCalouros[i + 1], sizeof(CALOURO));

				memcpy_s(&vtCalouros[i + 1], sizeof(CALOURO), &stAuxiliar, sizeof(CALOURO)));

				flgHouveTroca = true;
			}
		}
	} while (flgHouveTroca == true);
}

void ListarCalouros(int nQt, CALOURO vtCalouros[], char szCabecalho[])
{
	int i;
	char cWork[150];

	LIMPAR_TELA;

	cout << "\n\t" << szCabecalho << endl;
	cout << "     Nome                Sexo   Nota" << endl;

	/*
	** Loop da listagem
	*/
	for (i = 0; i < nQt; i++)
	{
		sprintf_s(cWork, sizeof(cWork), "%-30s %c   %2d", vtCalouros[i].cNomeCalouro, vtCalouros[i].cSexoCalouro, vtCalouros[i].nNotaCalouro);
		cout << cWork << endl;
	}// for i

	cout << "\n\tFim da lisagem" << endl;

	PAUSA;

	// Classificar em ordem alfabetica
	BubbleSort(nQt, vtCalouros, true);
	ListarCalouros(nQt, vtCalouros, "Listagem em ordem alfabetica");

	// Classificar em ordem de nota
	BubbleSort(nQt, vtCalouros, false);
	ListarCalouros(nQt, vtCalouros, "Listagem em ordem crescente de nota");
}