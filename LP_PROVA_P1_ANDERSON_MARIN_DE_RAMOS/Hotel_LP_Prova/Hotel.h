// Hotel.h - Defini��es do programa de Hotel para prova
#include <iostream>
#include <windows.h>
// defini��es do programa
#define LIMPAR_TELA						system("cls")
#define PAUSA							system("pause")
#define BRASIL							setlocale(LC_ALL, "portuguese_brazil")
#define TAM_NOME_HOSPEDE				40

// Dimensionamento do hotel
#define QTDE_ANDARES					30			// quantidade de andares
#define QTDE_QUARTOS_POR_ANDAR			20			// quantidade de quartos por andar
#define QTDE_TOTAL_QUARTOS				QTDE_ANDARES * QTDE_QUARTOS_POR_ANDAR // Total de quartos

// op��es do menu
#define FAZER_CHECK_IN					'I'			// fazer o check-in do h�spede
#define FAZER_CHECK_OUT					'O'			// fazer o check-out do h�spede
#define LISTAR_UM_QUARTO				'L'			// listar os dados de um dado quarto
#define LANCAR_SERVICO					'S'			// lan�ar um servi�o no quarto
#define LANCAR_DIARIA					'D'			// lan�ar di�rias nos quartos que est�o ocupados
#define SAIR_DO_PROGRAMA				'X'			// sair do programa		

// tabela de di�rias
#define DIARIA_PRIMEIRO_TERCEIRO		120.00		// Di�ria do primeiro andar ao terceiro
#define DIARIA_QUARTO_SEXTO				210.00		// Di�ria do quarto andar ao sexto
#define DIARIA_SETIMO_NONO				380.00		// Di�ria do setimo andar ao nono
#define DIARIA_DECIMO_ACIMA				970.00		// Di�ria do d�cimo andar e acima
// andares que est�o em reforma
#define SETIMO_ANDAR					7			// andar em reforma
#define OITAVO_ANDAR					8			// andar em reforma

// tabela de andares
#define PRIMEIRO_ANDAR					1			// primeiro andar
#define SEGUNDO_ANDAR					2			// segundo andar
#define TERCEIRO_ANDAR					3			// terceiro andar
#define QUARTO_ANDAR					4			// quarto andar
#define QUINTO_ANDAR					5			// quinto andar
#define SEXTO_ANDAR						6			// sexto andar
// S�timo e oitavo est�o em reforma
#define NONO_ANDAR						9			// nono andar
#define DECIMO_ANDAR					10			// d�cimo andar

// defini��es de tipos de servi�os
#define RESTAURANTE						1			// transa��o de restaurante
#define BAR								2			// transa��o de bar
#define PISCINA							3			// transa��o de bar da piscina
#define BOATE							4			// transa��o de bar da boate

// layout da struct de cada quarto do hotel
typedef struct tagQUARTO							// struct de cada quarto
{
	bool flgLivreOuOcupado;							// true - indica que o quarto est� ocupado
	int	nAndar,										// n�mero do andar de 1 a QTDE_ANDARES
		nQuarto;									// n�mero do quarto dentro do andar
													// 1, 2, 3 .......QTDE_QUARTOS_POR_ANDAR
	char	cNomeHospede[TAM_NOME_HOSPEDE + 1],		// nome do h�spede
		cNormal;									// quarto normal = 'N' e 'R' = Reforma
	double	dValorTotalDespesas,					// valor total das despesas do quarto
		dValorTotalDiarias,							// valor total das di�rias do quarto
		dValorTotalServicos,						// valor total dos servi�os
		dValorDiaria;								// valor da diaria do quarto
} QUARTO;

// Prot�tipos das fun��es
bool	CheckIn(int nAndar, int nQuarto, char *ptrHospede, QUARTO *ptrVetor);
bool	CheckOut(int nAndar, int nQuarto, QUARTO *ptrVetor);
bool	ListarDadosDeUmQuarto(int nAndar, int nQuarto, QUARTO *ptrVetor);
bool	VerificarSeQuartoLivreOuOcupado(int nAndar, int nQuarto, int *ptrIndice, QUARTO *ptrVetor);
bool	LancarServico(int nAndar, int nQuarto, double dValorServico, QUARTO *ptrVetor);
void LancarDiarias(QUARTO *ptrVetor, int nQtdeQuartos);
