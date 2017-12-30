// Declarações do exame de LP - 14/06/2017
#include <iostream>
#include <Windows.h>
using namespace std;
#define PAUSA							system("pause")
#define LIMPAR_TELA						system("cls")
#define PAIS_BRASIL						setlocale(LC_ALL, "portuguese_brazil")
#define EXTEN_DESCRICAO					40				// extensão da descrição do produto
#define QTDE_MAX_GRUPO					500				// qtde maxima de produtos de cada grupo
#define QTDE_MIN_GRUPO					100				// qtde minima de produtos de cada grupo
//
// definição dos grupos de produtos
//
#define PESADOS						1			// produtos que são vendidos por peso
#define CEREAIS						2			// cereais 
#define ENLATADOS					3			// produtos enlatados
#define EMBUTIDOS					4			// embutidos
#define BEBIDAS						5			// bebidas
#define QTDE_GRUPOS					5			// quantidade de grupos
#define CAMINHO_DO_CADASTRO			"..\\Produtos.arq"
#define CAMINHO_INI_QTDE_GRUPO		"..\\Grupos.qtd"
// Definições do menu do programa
#define CADASTRAR_PRODUTO			'C'	// cadastrar um novo produto
#define EXIBIR_DADOS_PRODUTO		'M'	// exibir dados do produto
#define LISTAGEM_GERAL_GRUPO		'G' // listagem geral do grupo
#define EXCLUIR_PRODUTO				'E'	// excluir um dado produto
#define SAIR_DO_PROGRAMA			'S'	// sair do programa
// struct de cada produto
typedef struct tagPRODUTO
{
	int nCodigoGrupo,					// codigo do Grupo de PESADOS a BEBIDAS (1, 2, 3, 4, 5)
		nCodProdGrupo;					// código do produto dentro do grupo de 1 a qtde de produtos do grupo
	char cDescricaoProd[EXTEN_DESCRICAO + 1], // descrição do produto
		cProdutoAtivo;					// 'A' - produto ativo, 'N' - não está ativo
	double dPrecoUnit;					// preço unitário do produto
} PRODUTO;								// struct de produto
// struct do dimensionamento do programa
typedef struct tagINICIO_QTDE
{
	int	nIniGrupo,						// posição inicial do grupo
		nQtdeGrupo;						// quantidade do grupo
} INICIO_QTDE;							// struct para cada grupo
// dimensionamento do grupos
typedef struct tagGRUPO
{
	INICIO_QTDE vetIniQtde[QTDE_GRUPOS]; // inicio posicional do grupo e qtde produtos do grupo
} GRUPO;
