// PDV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void main(void)
{
	int i;					// indice e contador geral
	char cOpcao,			// opcao do operador
		cWork[200];			// edicoes do sprintf_s
	PRODUTO stProduto;		// para conter os dados de um produto
	FILE *fdCadastro;		// file descriptor do cadastro de produto

	BRASIL;

	// Abrir o arquivo em modo r+b (leitura gravacao binaria) precisa existir
	// Se não existir:
	//		1. Abrir o arquivo em modo w+b - primeira vez que o programa é executado
	//		2. Se não abrir, avisar ao operador e voltar ao sistema operacional
	//		3. Se abriu:
	//			3.1. Fazer um loop de gravacao de QTDE_PRODUTOS sendo que codigo 1, 2, 3, ....... e cAtivoInativo = 'I'
	//				podera zerar todas as doubles
	//			3.2. Deixar como esta(não fecha)
	// Se existir - deixa como esta(ja abriu)


	//
	// Loop infinito com opcoes do menu
	//

	// Se for cadastrar:
	//		1. Verificar se o produto a cadastrar ja esta cadastrado
	//		2. Se estiver cadastrado exibir os seus dados, pausa para o operador, volta ao menu
	//		3. Se não estiver cadastrado pede sua descrição, qtde em estoque, preco unitario e calcular o valor do estoque. Zerar os demais valores
	//		4. Gravar o produto

	// Se for excluir:
	//		1. Verificar se o produto esta cadastrado e se nao estiver avisar ao operador e voltar ao menu
	//		2. Se cadastrado exibir os seus dados e pedir a confirmacao para a exclusão logica do produto (trocar o A por I e regravar)

	// Se for mostrar:
	//		1. Se vira

	// Se for vender:
	//		1. Verificar se o produto esta cadastrado e exibir ao operador os seus dados
	//		2. Pedir a quantidade vendida
	//		3. Se a quantidade vendida maior que no estoque avisar ao operador e voltar ao menu
	//		4. Calcular a quantidade * preco unitario e exibir ao operador
	//		5. Atualizar o estoque - o vendido e calcular o valor total do estoque somar na quantidade vendida
	//		6. Regravar o produto
	//		7. Se o produto estiver inativo, avisar o operador e voltar ao menu(acabou o produto)

	// Se for comprar:
	//		1. Verificar se o produto esta cadastrado
	//		2. Informar a quantidade comprada e o valor total
	//		3. Somar a quantidade no estoque
	//		4. Somar no valor do estoque o valor total da compra
	//		5. Calcular o novo preco unitario (valor_total_estoque/estoque) somar na quantidade comprada e informar a data da ultima compra
	//		6. Regravar produto

} // main 

