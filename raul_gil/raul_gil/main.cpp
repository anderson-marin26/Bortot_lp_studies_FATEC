// Programa de Calouros Raul Gil
// FATEC - MC - Anderson Marin de Ramos - 30/08/2017 - v0.0

#include "header.h"

// entry point
void main(void)
{
	int i, j,
		nTrono = -1,
		iIndice,
		nQtde,
		vetNotas[QTDE_MAXIMA];
	char vetNomes[QTDE_MAXIMA][TAMANHO_NOME + 1],
		vetSexos[QTDE_MAXIMA];
	BRASIL;

	do
	{
		cout << "\n\tQuantidade de calouros (" << QTDE_MINIMA << " e " << QTDE_MAXIMA << ")" << endl << "\tOu zero para cancelar a execução do programa: ";
		cin >> nQtde;
		
		if (nQtde == 0)
		{
			return;
		}
	} while (nQtde < QTDE_MINIMA || nQtde > QTDE_MAXIMA);

	// tratando os calouros
	for (i = 0; i < nQtde; i++)
	{
		cin.ignore(1, EOF);			// limpando
		cout << "Nome do calouro de ordem " << i + 1 << " de " << nQtde << ": ";
		cin.getline(vetNomes[i], TAMANHO_NOME, '\n');

		// Pegando o sexo
		do
		{
			cout << "Sexo do calouro " << vetNomes[i] << " (" << MASCULINO << " - Masculino e " << FEMININO << " - Feminino): ";
			cin >> vetSexos[i];

			vetSexos[i] = toupper(vetSexos[i]);
		} while (vetSexos[i] != MASCULINO && vetSexos[i] != FEMININO);

		// Pegando a nota
		do
		{
			cout << "Nota (0 a 10) : ";
			cin >> vetNotas[i];
		} while (vetNotas[i] < 0 || vetNotas[i] > 10);

		// Verificar posição do calouro
		if (vetNotas[i] > nTrono)
		{
			nTrono = vetNotas[i];
			iIndice = i;
		}
	} // for i

	cout << "\nO vencedor foi : " << vetNomes[iIndice] << "  sexo : " << vetSexos[iIndice] << " nota : " << vetNotas[iIndice] << endl;
	PAUSA;

} // main