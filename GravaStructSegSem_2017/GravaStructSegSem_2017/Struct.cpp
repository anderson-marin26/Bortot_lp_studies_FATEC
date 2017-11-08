// Primeiro programa de gravação com struct
// FATEC-MC - ???? 18/10/2017
#include "Disco.h"
// entry point do programa
void main(void)
{
	PRODUTO stProduto;
	char cWork[200],							// sprintf_s
		cContinua;								// decisão do operador
	FILE *fdArquivo;							// file descriptor
	int i,										// contador e indexador
		nCodigo;								// para receber o código do produto

	// abrir o arquivo em modo gravação e leitura em binário
	// preencher a struct stProduto sendo o codigo 1, 2, 3, ......QTDE_PRODUTOS
	// descrição vai ser "Produto de codigo:codigo do produto"
	// o preço unitário será o código * 0.03456
	// gravar esta struct
	// quando completar a QTDE_PRODUTOS fechar o arquivo e abrir em modo
	//	leitura e binário.
	// listar o arquivo de 5 em 5 linhas e perguntar se vai continuar ou não
	// se não vai continuar fechar o arquivo e voltar ao sistema operacional
	BRASIL;										// acentuação brasileira
	if (fopen_s(&fdArquivo, CAMINHO_ARQUIVO, "w+b") != 0)	// erro de gravação?
	{
		cout << "Erro de abertura do arquivo: " << CAMINHO_ARQUIVO << endl;
		PAUSA;
		return;
	}
	for (i = 0; i < QTDE_PRODUTOS; i++)			// loop de gravação
	{
		stProduto.nCodigo = i + 1;				// codigo
		stProduto.dPrecoUnit = stProduto.nCodigo * 0.03456;
		sprintf_s(stProduto.cDescricao, sizeof(stProduto.cDescricao),
			"Produto de código:%5d", i + 1);	// formata descrição do produto
		if (fwrite(&stProduto, sizeof(stProduto), 1, fdArquivo) == 0) // erro de gravação?
		{
			fclose(fdArquivo);					// fechar o arquivo
			cout << "Erro de gravação" << endl;	// avisa o operador
			PAUSA;
			return;
		}
	} // for i
	// gravou-se os registros pedidos
	/*
	fclose(fdArquivo);						// fechar o arquivo
	if (fopen_s(&fdArquivo, CAMINHO_ARQUIVO, "rb") != 0) // erro de abertura?
	{
		cout << "Erro de abertura em modo leitura!" << endl;
		PAUSA;
		return;								// volta ao Sistema Operacional
	}
	*/
	// listagem de 5 em 5 registros
	// reposicionar o arquivo na posição inicial

	if (fseek(fdArquivo, 0, SEEK_SET) != 0) // Voltando pra primeira posição do ponteiro do arquivo
	{
		fclose(fdArquivo);					// fechar o arquivo
		cout << "Erro de seek!" << endl;
		PAUSA;
		return;								// volta ao sistema operacional
	}

	while (true)
	{
		LIMPAR_TELA;						// limpar a tela
		sprintf_s(cWork, sizeof(cWork), "\n\tListagem de 5 em 5 registros");
		cout << cWork << endl;
		sprintf_s(cWork, sizeof(cWork),
			"Código Descrição                               Preço Unitário");
		cout << cWork << endl;
		for (i = 0; i < 5; i++)				// loop de leitura
		{
			if (fread_s(&stProduto, sizeof(stProduto), sizeof(stProduto), 1, fdArquivo) == 0) // fim arquivo?
			{
				cout << "\n\tFim do arquivo!" << endl;
				PAUSA;
				break;						// cai for do for i
			}
			sprintf_s(cWork, sizeof(cWork),
				"%6d %-40s %8.2f",
				stProduto.nCodigo, stProduto.cDescricao, stProduto.dPrecoUnit);
			cout << cWork << endl;
		} // for i
		if (i == 5)						// Listou os 5 registros?
		{
			cout << "Continuar a listagem? (S ou N):";
			cin >> cContinua;					// continuar a listagem?
			if (cContinua == 'S' || cContinua == 's') // vai continuar a listagem?
				continue;						// continuar na listagem
			else
				break;							// cai fora do while
		}
		else									// foi fim da listagem
			break;								// cai fora do while
	} // while true
	// loop da mostra de um produto de forma posicional. (cobol read key)
	while (true)
	{
		do
		{
			LIMPAR_TELA;
			cout << "\nDigite o código do produto de 1 a " << QTDE_PRODUTOS << endl
				<< "Ou zero para encerrar a execução do programa: ";
			cin >> nCodigo;						// recebe o código
			if (nCodigo == 0)					// encerrar execução?
			{
				fclose(fdArquivo);				// fechar arquivo
				return;							// volta ao Sistema Operacional
			}
		} while (nCodigo < 1 || nCodigo > QTDE_PRODUTOS);
		if (fseek(fdArquivo, (nCodigo - 1) * sizeof(PRODUTO), SEEK_SET) != 0) // erro de seek?
		{
			fclose(fdArquivo);					// fechar o arquivo
			cout << "Erro de seek!" << endl;
			PAUSA;
			return;								// volta ao sistema operacional
		}
		if (fread_s(&stProduto, sizeof(PRODUTO), sizeof(PRODUTO), 1, fdArquivo) == 0) // erro leitura?
		{
			cout << "Erro de leitura!" << endl;
			PAUSA;
			continue;							// continua no loop infinito
		}
		// leitura com sucesso
		// formata um cabeçalho
		sprintf_s(cWork, sizeof(cWork),
			"\n\nCódigo Descrição                               Preço Unitário");
		cout << cWork << endl;
		sprintf_s(cWork, sizeof(cWork),
			"%6d %-40s %8.2f",
			stProduto.nCodigo, stProduto.cDescricao, stProduto.dPrecoUnit);
		cout << cWork << endl;
		PAUSA;
	} // while true
} // main




