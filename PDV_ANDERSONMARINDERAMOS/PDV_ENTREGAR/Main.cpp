// PDV.cpp : Defines the entry point for the console application.
// FATEC - ANDERSON MARIN DE RAMOS - 2017

#include "Header.h"

// funcao que pede o codigo do produto
// parametros:
//		Entrada:
//			char *szAcao - ponteiro com string da acao para o titulo

int pedeProduto(char *szAcao)
{
	int nCodigo = 0;	// Para receber o codigo do produto
	cout << "\n\tAção: " << szAcao << endl;

	do
	{
		cout << "Informe um codigo entre 1 e " << QTDE_PRODUTO << endl << "Ou zero para cancelar e voltar ao menu: ";
		cin >> nCodigo;

		if (nCodigo == 0)
		{// Cancelou
			return 0;
		}
	} while (nCodigo < 1 || nCodigo >> QTDE_PRODUTO);

	return nCodigo;
}

bool lerPosicional(int nCodigo, PRODUTO *ptrProduto, FILE *fdArquivo)
{
	if (fseek(fdArquivo, (nCodigo - 1) * sizeof(PRODUTO), SEEK_SET) != 0)
	{// erro de leitura
		return false;
	}

	if (fread_s(ptrProduto, sizeof(PRODUTO), sizeof(PRODUTO), 1, fdArquivo) == 0)
	{// erro de leitura
		return false;
	}

	// tudo ok
	return true;
}

bool gravaPosicional(int nCodigo, PRODUTO *ptrProduto, FILE *fdArquivo)
{
	if (fseek(fdArquivo, (nCodigo - 1) * sizeof(PRODUTO), SEEK_SET) != 0)
	{// erro
		return false;
	}

	if (fwrite(ptrProduto, sizeof(PRODUTO), 1, fdArquivo) == 0)
	{// erro
		return false;
	}

	// tudo ok
	return true;
}


// Entry point
void main(void)
{
	int i,					// indice e contador geral
		nCodigo,
		quantidade_produto;
	double total_venda;
	char cOpcao,			// opcao do operador
		cWork[200];			// edicoes do sprintf_s
	PRODUTO stProduto;		// para conter os dados de um produto
	FILE *fdCadastro;		// file descriptor do cadastro de produto
	SYSTEMTIME stTime;

	BRASIL;

	// Abrir o arquivo em modo r+b (leitura gravacao binaria) precisa existir
	// Se não existir:
	//		1. Abrir o arquivo em modo w+b - primeira vez que o programa é executado
	if(fopen_s(&fdCadastro,CAMINHO_CADASTRO, "r+b") != 0)
	{
		if (fopen_s(&fdCadastro, CAMINHO_CADASTRO, "w+b") != 0)
		{
			//		2. Se não abrir, avisar ao operador e voltar ao sistema operacional
			cout << "Erro de abertura do arquivo " << endl;
			PAUSA;
			exit(-1);
		}
	}
	//		3. Se abriu:
	//			3.1. Fazer um loop de gravacao de QTDE_PRODUTOS sendo que codigo 1, 2, 3, ....... e cAtivoInativo = 'I'
	//				podera zerar todas as doubles
	for (i = 0; i < QTDE_PRODUTO; i++)
	{
		stProduto.nCodProduto = i + 1;
		stProduto.cAtivoInativo = 'I';
		stProduto.dPrecoUnit = 0.0;
		stProduto.dVlrTotalEstoque = 0.0;
		stProduto.cDescricao[0] = NULL;

		if(fwrite(&stProduto,sizeof(PRODUTO),1,fdCadastro) == 0)
		{
			fclose(fdCadastro);
			cout << "Erro de gravação" << endl;
			PAUSA;
			exit(-1);
		}
	}
	//			3.2. Deixar como esta(não fecha)
	// Se existir - deixa como esta(ja abriu)


	//
	// Loop infinito com opcoes do menu
	//
	while (true) {
		LIMPAR_TELA;

		GetLocalTime(&stTime);
		sprintf_s(cWork, sizeof(cWork), "\n\tPonto de Venda %02d/%02d/%04d às %02d:%02d:%02d",
			stTime.wDay,
			stTime.wMonth,
			stTime.wYear,
			stTime.wHour,
			stTime.wMinute,
			stTime.wSecond
		);

		cout << cWork << endl;

		cout << CADASTRAR_PRODUTO << " - Cadastrar um novo produto" << endl;
		cout << EXCLUIR_PRODUTO << "- Excluir um produto existente" << endl;
		cout << MOSTRAR_PRODUTO << " - Exibir dados de um produto" << endl;
		cout << VENDER_PRODUTO << " - Vender um produto" << endl;
		cout << COMPRAR_PRODUTO << " - Comprar um produto" << endl;
		cout << SAIR_DO_PROGRAMA << " - Sair do programa" << endl;
		cout << "\tSelecione:";
		cin >> cOpcao;
		cOpcao = toupper(cOpcao);
		switch (cOpcao) {
		case CADASTRAR_PRODUTO:
			// Se for cadastrar:
			//		1. Verificar se o produto a cadastrar ja esta cadastrado
			nCodigo = pedeProduto("Codigo do produto");
			if (nCodigo == 0)
			{// Cancelado
				break;
			}

			if (lerPosicional(nCodigo, &stProduto, fdCadastro) == false)
			{// erro de leitura
				cout << "Erro de leitura do codigo: " << nCodigo << endl;
				PAUSA;
				break;
			}

			// Codigo lido no arquivo
			if (stProduto.cAtivoInativo == 'A')
			{// Produto ja cadastrado
			 //		2. Se estiver cadastrado exibir os seus dados, pausa para o operador, volta ao menu
				cout << "Produto " << stProduto.cDescricao << " de preço " << stProduto.dPrecoUnit << " já cadastrado!" << endl;
				PAUSA;
				break;
			}

			// Produto vai ser cadastrado
			//		3. Se não estiver cadastrado pede sua descrição, qtde em estoque, preco unitario e calcular o valor do estoque. Zerar os demais valores
			stProduto.nCodProduto = nCodigo;
			cin.ignore(1, EOF);
			cout << "Descrição do produto: " << endl;
			cin.getline(stProduto.cDescricao, TAM_DESCRICAO, '\n');
			cout << "Digite a quantidade em estoque:" << endl;
			cin >> stProduto.dEstoque;

			if (stProduto.dEstoque < 1)
			{
				cout << "Quantidade invalida!" << endl;
				PAUSA;
				break;
			}

			cout << "Digite o preco unitario:" << endl;
			cin >> stProduto.dPrecoUnit;

			if (stProduto.dPrecoUnit <= 0)
			{
				cout << "Preco invalido" << endl;
				PAUSA;
				break;
			}

			stProduto.dVlrTotalEstoque += stProduto.dEstoque * stProduto.dPrecoUnit;
			stProduto.cAtivoInativo = 'A';
			stProduto.dTotCompras = 0;
			stProduto.dTotVendas = 0;
			stProduto.stDtUltCompra.nDia = stTime.wDay;
			stProduto.stDtUltCompra.nMes = stTime.wMonth;
			stProduto.stDtUltCompra.nAno = stTime.wYear;

			//		4. Gravar o produto
			if (gravaPosicional(nCodigo, &stProduto, fdCadastro) == false)
			{// erro 
				cout << "Erro de gravação do produto " << nCodigo << endl;
				PAUSA;
				break;
			}

			cout << "Produto " << nCodigo << " - " << stProduto.cDescricao << "  Gravado com sucesso!" << endl;
			PAUSA;
			break;
		case EXCLUIR_PRODUTO:
			// Se for excluir:
			//		1. Verificar se o produto esta cadastrado e se nao estiver avisar ao operador e voltar ao menu
			//		2. Se cadastrado exibir os seus dados e pedir a confirmacao para a exclusão logica do produto (trocar o A por I e regravar)
			nCodigo = pedeProduto("Exclusão de produto");

			if (nCodigo == 0)
			{// cancelou
				break;
			}

			if (lerPosicional(nCodigo, &stProduto, fdCadastro) == false)
			{ // erro
				cout << "Erro de leitura do produto " << nCodigo << endl;
				PAUSA;
				break;
			}

			if (stProduto.cAtivoInativo == 'I')
			{
				cout << "Produto não cadastrado!" << endl;
				PAUSA;
				break;
			}
			
			// tudo ok
			cout << "Produto " << stProduto.nCodProduto << " - " << stProduto.cDescricao << " sera excluido, tem certeza? (S ou N)" << endl;
			cin >> cOpcao;
			if (cOpcao == 's' || cOpcao == 'S')
			{// excluir
				stProduto.cAtivoInativo = 'I';
				stProduto.dVlrTotalEstoque -= stProduto.dPrecoUnit * stProduto.dEstoque;

				if (gravaPosicional(nCodigo, &stProduto, fdCadastro) == false)
				{// erro
					cout << "Erro ao excluir produto " << nCodigo << endl;
				}

				cout << "Produto " << nCodigo << " - " << stProduto.cDescricao << " Excluido com sucesso!" << endl;
				PAUSA;
			}

			break;								//volta ao menu
		case MOSTRAR_PRODUTO:
			nCodigo = pedeProduto("Mostrar dados do produto");

			if (nCodigo == 0)
			{// cancelou
				break;
			}

			if(lerPosicional(nCodigo, &stProduto, fdCadastro) == false)
			{// erro
				cout << "Erro de leitura do produto " << nCodigo << endl;
			}

			if (stProduto.cAtivoInativo == 'I')
			{// Produto inativo
				cout << "Nenhum produto com o codigo inserido!" << endl;
				PAUSA;
				break;
			}

			cout << "Produto " << stProduto.nCodProduto << " - " << stProduto.cDescricao << endl
				<< "Com preço unitario de: " << stProduto.dPrecoUnit << ". Com " << stProduto.dEstoque << " em estoque." << endl
				<< "Total de vendas do produto: " << stProduto.dTotVendas << ". Ultima compra em: " << stProduto.stDtUltCompra.nDia << " do " << stProduto.stDtUltCompra.nMes << " de " << stProduto.stDtUltCompra.nAno << endl;
			PAUSA;
			break;
		case VENDER_PRODUTO:
			// Se for vender:
			//		1. Verificar se o produto esta cadastrado e exibir ao operador os seus dados
			//		2. Pedir a quantidade vendida
			//		3. Se a quantidade vendida maior que no estoque avisar ao operador e voltar ao menu
			//		4. Calcular a quantidade * preco unitario e exibir ao operador
			//		5. Atualizar o estoque - o vendido e calcular o valor total do estoque somar na quantidade vendida
			//		6. Regravar o produto
			//		7. Se o produto estiver inativo, avisar o operador e voltar ao menu(acabou o produto)
			nCodigo = pedeProduto("Vender Produto");

			if (nCodigo == 0)
			{// cancelou
				break;
			}

			if (lerPosicional(nCodigo, &stProduto, fdCadastro) == false)
			{// erro
				cout << "Erro de leitura do codigo: " << nCodigo << endl;
				PAUSA;
				break;
			}

			if (stProduto.cAtivoInativo == 'I')
			{
				cout << "Nenhum produto cadastrado com o codigo informado" << endl;
				PAUSA;
				break;
			}

			cout << "Produto " << stProduto.nCodProduto << " - " << stProduto.cDescricao << endl << "Com " << stProduto.dEstoque << " em estoque." << endl;
			cout << "Digite a quantidade a ser vendida: " << endl;
			cin >> quantidade_produto;

			if (quantidade_produto > stProduto.dEstoque)
			{// mais do que tem em estoque
				cout << "Quantidade em estoque insuficiente. Atualmente existem " << stProduto.dEstoque << " em estoque do produto." << endl;
				PAUSA;
				break;
			}
			else if (quantidade_produto < 1)
			{
				cout << "Quantidade invalida!" << endl;
				PAUSA;
				break;
			}

			total_venda = quantidade_produto * stProduto.dPrecoUnit;
			cout << "Total : " << total_venda << endl;
			PAUSA;

			stProduto.dVlrTotalEstoque -= total_venda;
			stProduto.dEstoque -= quantidade_produto;

			if (stProduto.dEstoque == 0)
			{
				cout << "Estoque do produto vazio!" << endl;
				stProduto.cAtivoInativo = 'I';
				PAUSA;
			}

			stProduto.dTotVendas++;

			if (gravaPosicional(nCodigo, &stProduto, fdCadastro) == false)
			{// erro
				cout << "Erro na leitura do codigo: " << nCodigo << endl;
				PAUSA;
				break;
			}

			cout << "Venda realizada com sucesso!" << endl;
			PAUSA;
			break;

		case COMPRAR_PRODUTO:
			// Se for comprar:
			//		1. Verificar se o produto esta cadastrado
			//		2. Informar a quantidade comprada e o valor total
			//		3. Somar a quantidade no estoque
			//		4. Somar no valor do estoque o valor total da compra
			//		5. Calcular o novo preco unitario (valor_total_estoque/estoque) somar na quantidade comprada e informar a data da ultima compra
			//		6. Regravar produto

			nCodigo = pedeProduto("Comprar um produto");

			if (nCodigo == 0)
			{// cancelou
				break;
			}

			if (lerPosicional(nCodigo, &stProduto, fdCadastro) == false)
			{// erro
				cout << "Erro com o codigo: " << nCodigo << endl;
				PAUSA;
				break;
			}

			if (stProduto.cAtivoInativo == 'I')
			{
				cout << "Produto não cadastrado!" << endl;
				PAUSA;
				break;
			}

			cout << "Digite a quantidade a ser comprada:" << endl;
			cin >> quantidade_produto;
			if (quantidade_produto < 1)
			{
				cout << "Quantidade invalida!" << endl;
				PAUSA;
				break;
			}
			cout << "Digite o valor total da compra:" << endl;
			cin >> total_venda;
			if (total_venda < 1)
			{
				cout << "Quantidade invalida!" << endl;
				PAUSA;
				break;
			}

			stProduto.dEstoque += quantidade_produto;
			stProduto.dVlrTotalEstoque += total_venda;
			stProduto.dPrecoUnit = stProduto.dVlrTotalEstoque / stProduto.dEstoque;
			stProduto.stDtUltCompra.nDia = stTime.wDay;
			stProduto.stDtUltCompra.nMes = stTime.wMonth;
			stProduto.stDtUltCompra.nAno = stTime.wYear;
			stProduto.dTotCompras++;

			if (gravaPosicional(nCodigo, &stProduto, fdCadastro) == false)
			{// erro
				cout << "Erro ao gravar o produto!" << endl;
				PAUSA;
				break;
			}

			cout << "Compra realizada com sucesso!" << endl;
			PAUSA;
			break;
		case SAIR_DO_PROGRAMA:
			cout << "Sair realmente? (S ou N): ";
			cin >> cOpcao;
			if (cOpcao == 's' || cOpcao == 'S') {
				fclose(fdCadastro);
				exit(0);						//retorna ao S.O sem erro
			}
			break;								//volta ao menu
		default:
			cout << "\n\tOpção invalida!" << endl;
			PAUSA;
		}
	}// while

} // main 

