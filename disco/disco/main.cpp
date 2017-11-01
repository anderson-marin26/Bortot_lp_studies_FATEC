#include "Header.h"

// main
void main(void)
{
	FILE *fdArquivo;				// file descriptor
	char cBuffer[200],				// buffer de gracavao
		cBuffLeitura;				// buffer de leitura
	BRASIL;

	if (fopen_s(&fdArquivo, CAMINHO_ARQUIVO, "w") != 0)
	{
		cout << "Erro de abertura do arquivo: " << CAMINHO_ARQUIVO << endl;
		PAUSA;
		return;
	}

	while (true)
	{
		cout << "Digite um texto e termine com a tecla enter" << endl << "Ou 9999999 para encerrar a digitação" << endl;
		cin.getline(cBuffer, sizeof(cBuffer), '\n');

		if (strcmp(cBuffer, "9999999") == 0)
		{
			fclose(fdArquivo);
			cout << "\n\tFim da gravaçao!" << endl;

			PAUSA;

			if (fopen_s(&fdArquivo, CAMINHO_ARQUIVO, "r") != 0)
			{
				cout << "Erro de abertura arquivo " << CAMINHO_ARQUIVO << endl;
				PAUSA;
				return;
			}

			//abriu
			while (true)
			{
				if (fread_s(&cBuffLeitura, 1, 1, 1, fdArquivo) != 0)
				{
					fclose(fdArquivo);
					cout << "\nFim da listagem!" << endl;
					PAUSA;
					return;
				}

				cout << cBuffLeitura;
			}

			return;
		}

		// texto para gravação ok
		strcat_s(cBuffer, sizeof(cBuffer), "\n");
		if (fwrite(cBuffer, strlen(cBuffer), 1, fdArquivo) == 0)
		{
			fclose(fdArquivo);
			cout << "Erro de gravação" << endl;
			PAUSA;
			return;
		}
	}
} // main