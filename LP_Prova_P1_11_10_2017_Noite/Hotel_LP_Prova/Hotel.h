// Hotel.h - Definições do programa de Hotel para prova
#include <iostream>
#include <windows.h>
// definições do programa
#define LIMPAR_TELA						system("cls")
#define PAUSA							system("pause")
#define BRASIL							setlocale(LC_ALL, "portuguese_brazil")
#define TAM_NOME_HOSPEDE				40

// Dimensionamento do hotel
#define QTDE_ANDARES					30			// quantidade de andares
#define QTDE_QUARTOS_POR_ANDAR			20			// quantidade de quartos por andar
#define QTDE_TOTAL_QUARTOS				QTDE_ANDARES * QTDE_QUARTOS_POR_ANDAR // Total de quartos

// opções do menu
#define FAZER_CHECK_IN					'I'			// fazer o check-in do hóspede
#define FAZER_CHECK_OUT					'O'			// fazer o check-out do hóspede
#define LISTAR_UM_QUARTO				'L'			// listar os dados de um dado quarto
#define LANCAR_SERVICO					'S'			// lançar um serviço no quarto
#define LANCAR_DIARIA					'D'			// lançar diárias nos quartos que estão ocupados
#define SAIR_DO_PROGRAMA				'X'			// sair do programa		

// tabela de diárias
#define DIARIA_PRIMEIRO_TERCEIRO		120.00		// Diária do primeiro andar ao terceiro
#define DIARIA_QUARTO_SEXTO				210.00		// Diária do quarto andar ao sexto
#define DIARIA_SETIMO_NONO				380.00		// Diária do setimo andar ao nono
#define DIARIA_DECIMO_ACIMA				970.00		// Diária do décimo andar e acima
// andares que estão em reforma
#define SETIMO_ANDAR					7			// andar em reforma
#define OITAVO_ANDAR					8			// andar em reforma

// tabela de andares
#define PRIMEIRO_ANDAR					1			// primeiro andar
#define SEGUNDO_ANDAR					2			// segundo andar
#define TERCEIRO_ANDAR					3			// terceiro andar
#define QUARTO_ANDAR					4			// quarto andar
#define QUINTO_ANDAR					5			// quinto andar
#define SEXTO_ANDAR						6			// sexto andar
// Sétimo e oitavo estão em reforma
#define NONO_ANDAR						9			// nono andar
#define DECIMO_ANDAR					10			// décimo andar

// definições de tipos de serviços
#define RESTAURANTE						1			// transação de restaurante
#define BAR								2			// transação de bar
#define PISCINA							3			// transação de bar da piscina
#define BOATE							4			// transação de bar da boate

// layout da struct de cada quarto do hotel
typedef struct tagQUARTO							// struct de cada quarto
{
	bool flgLivreOuOcupado;							// true - indica que o quarto está ocupado
	int	nAndar,										// número do andar de 1 a QTDE_ANDARES
		nQuarto;									// número do quarto dentro do andar
													// 1, 2, 3 .......QTDE_QUARTOS_POR_ANDAR
	char	cNomeHospede[TAM_NOME_HOSPEDE + 1],		// nome do hóspede
		cNormal;									// quarto normal = 'N' e 'R' = Reforma
	double	dValorTotalDespesas,					// valor total das despesas do quarto
		dValorTotalDiarias,							// valor total das diárias do quarto
		dValorTotalServicos,						// valor total dos serviços
		dValorDiaria;								// valor da diaria do quarto
} QUARTO;

// Protótipos das funções
bool	CheckIn(int nAndar, int nQuarto, char *ptrHospede, QUARTO *ptrVetor);
bool	CheckOut(int nAndar, int nQuarto, QUARTO *ptrVetor);
bool	ListarDadosDeUmQuarto(int nAndar, int nQuarto, QUARTO *ptrVetor);
bool	VerificarSeQuartoLivreOuOcupado(int nAndar, int nQuarto, int *ptrIndice, QUARTO *ptrVetor);
bool	LancarServico(int nAndar, int nQuarto, double dValorServico, QUARTO *ptrVetor);
void LancarDiarias(QUARTO *ptrVetor, int nQtdeQuartos);
