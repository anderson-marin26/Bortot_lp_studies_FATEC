// Programa de ponto de venda exame - 06/12/2017
// FATEC - MC - Prof. Bortot - Linguagem de Programação


#include "Prova.h"
// variáveis globais
// Dimensionamento dos grupos
GRUPO stGrupo;									// contém o inicio e quantidade de cada grupo
//
int vetGrupos[] =							    // tabela de grupos de produtos
{
	PESADOS, 
	CEREAIS,
	ENLATADOS,
	EMBUTIDOS,
	BEBIDAS
};

char vetNomesGrupos[5][10] =					// tabela de nomes dos grupos
{
	"Pesados",
	"Cereais",
	"Enlatados",
	"Embutidos",
	"Bebidas"
};
// Função que pede um grupo e um código de produto válido para o grupo
//	vai devolver o posicional do produto dentro do arquivo de produtos
//	Parâmetros:
//		Entrada: int *ptrGrupo - ponteiro de uma inteira que receberá o grupo desejado
//				 int *ptrCodigo - ponteiro de uma inteira que receberá o código dentro do grupo
//				 int *ptrPosicao - idem a receber o cálculo do posicional do produto dentro
//									do arquivo
//				 char *ptrTransacao - transação que está sendo executada
//		Retorno: bool = true - indica que o grupo, código e posicional foram informados
//						false - indica que foi escolhido um grupo zero ou código zero
//								para cancelar a transação
bool PedeValidaGrupoCodigoProduto(int *ptrGrupo, int *ptrCodigo, int *ptrPosicao, char *ptrTransacao)
{
	// Pedir um grupo válido ou zero para cancelar a transação  do....while
	//  Exibir o código do grupo e o nome do grupo e zero para cancelar
	//		1 - Pesados
	//		2 - Cereais
	//			.....
	//		0 - Cancelar
	//				Selecione: ?
	//		Dependendo do grupo escolhido dentro de stGrupo tem a quantidade de produtos do grupo
	//			Pedir o código do produto entre 1 e a qtde de produtos do grupo com do...while
	//			ou zero para cancelar a transação.
	//		Não cancelando a transação e sendo informados o grupo e o código e sabendo o inicio do 
	//			grupo calcular o posicional para a leitura posicional deste produto e informar este 
	//			valor no endereço passado em ptrPosicao
	int i;												// contador e indice genérico
	cout << endl << "\n\t" << ptrTransacao << endl;
	do
	{
		for(i = 0; i < QTDE_GRUPOS; i++)
		{
			cout << (i + 1) << " - " << vetNomesGrupos[i] << endl;
		}
		cout << "0 - Para cancelar a transação" << endl <<
			"\n\tSelecione: ";
		cin >> *ptrGrupo;
		if(*ptrGrupo == 0)						// cancelar?
			return false;
	} while(*ptrGrupo < 1 || *ptrGrupo > QTDE_GRUPOS);
	do
	{
		cout << "Código do produto entre 1 e " << stGrupo.vetIniQtde[*ptrGrupo - 1].nQtdeGrupo << endl
			<< "Ou zeros para cancelar a transação: ";
		cin >> *ptrCodigo;
		if(*ptrCodigo == 0)						// cancelar?
			return false;
	} while(*ptrCodigo < 1 || *ptrCodigo > stGrupo.vetIniQtde[*ptrGrupo - 1].nQtdeGrupo);
	*ptrPosicao = stGrupo.vetIniQtde[*ptrGrupo - 1].nIniGrupo + *ptrCodigo - 1;  // devolve a posição a ser gravada
	return true;
}
// Função que lê posicional um produto dentro de um grupo e verifica se o grupo e o código são 
//	realmente os que eram desejados
//	Parâmetros:
//		Entrada: int nGrupo - grupo a ser verificado dentro do registro
//				 int nCodigo - idem código
//				 int nPosicional - posicional do produto dentro do arquivo
//				 PRODUTO *ptrStProduto - endereço da struct a receber os dados do produto
//				 FILE *fdProduto - file descriptor do arquivo de produto
//		Retorno: bool - true - foi lido ok
//						false - erro de seek ou leitura ou grupo ou código invalidos
bool LerPosicional(int nGrupo, int nCodigo, int nPosicional, PRODUTO *ptrStProduto, FILE *fdProduto)
{
	if(fseek(fdProduto, nPosicional * sizeof(PRODUTO), SEEK_SET) != 0)	// erro?
		return false;										// avisa o erro
	if(fread_s(ptrStProduto, sizeof(PRODUTO), sizeof(PRODUTO), 1, fdProduto) == 0) // erro?
		return false;										// avisa o erro
	if((nGrupo != ptrStProduto->nCodigoGrupo) ||
		(nCodigo != ptrStProduto->nCodProdGrupo))			// grupo ou código diferentes?
		return false;										// avisa o erro
	return true;											// avisa que tudo OK
}
// Função que grava posicional
//	Parâmetros:
//		Entrada: int nPosicional - posicional do produto a ser gravado
//				 PRODUTO *ptrStProduto - endereço dos dados do produto a ser gravado
//				 FILE *fdProduto - file descriptor do arquivo de produto
//		Retorno: bool - true - foi tudo OK
//						false - erro de fseek ou de fwrite
bool GravaPosicional(int nPosicional, PRODUTO *ptrStProduto, FILE *fdProduto)
{
	if(fseek(fdProduto, nPosicional * sizeof(PRODUTO), SEEK_SET) != 0)	// erro?
		return false;										// avisa o erro
	if(fwrite(ptrStProduto, sizeof(PRODUTO), 1, fdProduto) == 0) // erro?
		return false;										// avisa o erro
	return true;											// avisa que tudo OK
}
// 
// entry point do programa
//
void main(void)
{
	PRODUTO stProduto;							// struct para conter os dados de um produto
	FILE *fdProduto,							// file descriptor do cadastro de produtos
		*fdGrupo;								// file descriptor do grupo
	SYSTEMTIME stTime;							// para receber data e hora do sistema
	char cOpcao,								// Opção do menu informada pelo operador
		szNomeAluno[] = "Anderson Marin de Ramos",	// local para o nome do aluno
		cWork[200];								// para formatar os sprintf
	int i,										// índice genérico
		j,
		nGrupo,									// para receber o grupo do produto
		nCodigo,								// para receber o código produto
		nPosicao,								// para receber o posicional do produto dentro do arquivo
		nPosicional;							// para estabelecer o posicional de cada grupo
	/*
	No momento da entrega do projeto que foi copiado da pasta publica como: LP_ProvaP2_SegSem2017 
	renomear para LP_ProvaP2_SeuNome o SeuNome com Letras Maiúscula e minúsculas.
	Cuidado: renomear apenas o Diretório da pasta que foi copiado da pasta pública.
	*/

	PAIS_BRASIL;								// acentuação brasileira
	// abrir o arquivo de grupos em modo rb
	if(fopen_s(&fdGrupo, CAMINHO_INI_QTDE_GRUPO, "rb") != 0)	// não existe o arquivo?
	{	// não existe o arquivo - primeira vez da execução do programa
		if(fopen_s(&fdGrupo, CAMINHO_INI_QTDE_GRUPO, "wb") != 0)	// erro irrecuperável?
		{	// erro irrecuperavel
			cout << "Erro abertura arquivo: " << CAMINHO_INI_QTDE_GRUPO << endl;
			PAUSA;
			return;									// volta ao sistema operacional
		}
		cout << "\n\tDimensionamento do arquivo de produtos" << endl;
		// loop para dimensionar o inicio posicional de cada grupo e quantidade de 
		//	produtos de cada grupo
		for(i = nPosicional = 0; i < QTDE_GRUPOS; i++)
		{
			do
			{
				cout << "Qtde produtos do grupo " << vetNomesGrupos[i] << " (" 
					<< QTDE_MIN_GRUPO << " a " << QTDE_MAX_GRUPO << "): ";
				cin >> stGrupo.vetIniQtde[i].nQtdeGrupo;
			} while(stGrupo.vetIniQtde[i].nQtdeGrupo < QTDE_MIN_GRUPO ||
				stGrupo.vetIniQtde[i].nQtdeGrupo > QTDE_MAX_GRUPO);
			stGrupo.vetIniQtde[i].nIniGrupo = nPosicional;				// posicional deste grupo
			nPosicional += stGrupo.vetIniQtde[i].nQtdeGrupo;			// posicional do proximo
		} // for i
		if(fwrite(&stGrupo, sizeof(GRUPO), 1, fdGrupo) == 0)			// erro de gravação?
		{
			fclose(fdGrupo);											// fechar arquivo
			cout << "Erro de gravação dimensionamento grupos!" << endl;
			PAUSA;
			return;														// voltar ao S.O.
		}
		fclose(fdGrupo);												// fechar arquivo
		// Abrir o arquivo de produtos em modo "w+b" - se houver erro
		if (fopen_s(&fdProduto, CAMINHO_DO_CADASTRO, "w+b") != 0)	// não existe o arquivo?
		{	// não existe o arquivo - primeira vez da execução do programa
			//	avisar ao operador e sair do programa
			cout << "Erro abertura arquivo: " << CAMINHO_DO_CADASTRO << endl;
			PAUSA;
			return;
		}
		// fazer um loop de gravação sequencial gravando cada grupo em sequência indicando o
		//	grupo e o produto dentro do grupo (1 a quantidade de produtos do grupo). Indicar
		//		também que o produto está inativo
		//		Não utilizar a gravação posicional porque terá nota  baixa

			for (i = 0; i < QTDE_GRUPOS; i++)
			{
				//for (j = stGrupo.vetIniQtde[i].nIniGrupo; j <= stGrupo.vetIniQtde[i].nQtdeGrupo; j++)
				for (j = 0; j < stGrupo.vetIniQtde[i].nQtdeGrupo; j++)
				{
					stProduto.cProdutoAtivo = 'I';
					stProduto.nCodigoGrupo = i;
					stProduto.nCodProdGrupo = j;
					stProduto.dPrecoUnit = 0;

					if (fwrite(&stProduto, sizeof(PRODUTO), 1, fdProduto) == 0)
					{ // write error
						fclose(fdProduto);
						cout << "Erro escrita arquivo: " << CAMINHO_DO_CADASTRO << endl;
						PAUSA;
						return;
					}
				}
			}

		// Deixar o arquivo aberto
	}
	else
	{	// o arquivo de grupos existe 
		// Ler o registro para stGrupo e considerar que houve erro de leitura
		//		avisando o operador e voltando ao Sistema Operacional
		if (fread_s(&stGrupo, sizeof(GRUPO), sizeof(GRUPO), 1, fdGrupo) == 0)
		{// error
			cout << "Erro leitura arquivo(fread): " << CAMINHO_INI_QTDE_GRUPO << endl;
			PAUSA;
			return;
		}
		
		// Fechar o arquivo de grupos
		fclose(fdGrupo);
		// Abrir o arquivo de produto em modo "r+b"
		if (fopen_s(&fdProduto, CAMINHO_DO_CADASTRO, "r+b") != 0)	// não existe o arquivo?
		{	// não existe o arquivo - primeira vez da execução do programa
			//	avisar ao operador e sair do programa
			cout << "Erro abertura arquivo: " << CAMINHO_DO_CADASTRO << endl;
			PAUSA;
			return;
		}
		// Deixar o arquivo aberto
	}
	//
	//	loop infinito
	//
	while(true)								// loop infinito
	{
		// exibir o menu de ações a serem realizadas pelo operador
		LIMPAR_TELA;
		GetLocalTime(&stTime);
		sprintf(cWork, "\n\tFATEC-MC - Produtos %02d/%02d/%04d às %02d:%02d\n\tOperador:%s",
			stTime.wDay, stTime.wMonth, stTime.wYear,
			stTime.wHour, stTime.wMinute,
			szNomeAluno);
		cout << cWork << endl;
		cout << CADASTRAR_PRODUTO << " - Cadastrar um novo produto" << endl;
		cout << EXIBIR_DADOS_PRODUTO << " - Mostrar os dados de um produto" << endl;
		cout << LISTAGEM_GERAL_GRUPO << " - Listagem de um grupo válido" << endl;
		cout << EXCLUIR_PRODUTO << " - Excluir um dado produto" << endl;
		cout << SAIR_DO_PROGRAMA << " - Sair do programa" << endl;
		cout << "\tSelecione: ";
		cin		>> cOpcao;						// escolha do operador
		cOpcao = toupper(cOpcao);				// converte sempre para maiúsculo
		// analisar a opção feita pelo operador
		switch(cOpcao)							// avalia a opção escolhida
		{
			case CADASTRAR_PRODUTO:
				// <<<<4>>>>. Buscar o índice do produto dentro do arquivo
				//				através da função PedeValidaGrupoCodigoProduto
				//				Verificar se a transação foi cancelada e voltar ao menu
				if (!PedeValidaGrupoCodigoProduto(&nGrupo, &nCodigo, &nPosicao, "Cadastrar Produto"))
				{// canceled operation
					break;
				}
				
				if (!LerPosicional(nGrupo, nCodigo, nPosicao, &stProduto, fdProduto))
				{// read error
					cout << "Erro de leitura do arquivo " << CAMINHO_DO_CADASTRO << endl;
					PAUSA;
					break;
				}

				//			Se o produto já existe avisar ao operador exibindo os
				//				dados do produto e 
				//			aguardar sua visualização e voltar ao menu
				if (stProduto.cProdutoAtivo = 'A')
				{// product already saved
					cout << "Produto " << stProduto.nCodProdGrupo << " - " << stProduto.cDescricaoProd << " de preco " << stProduto.dPrecoUnit << " ja cadastrado!" << endl;
					PAUSA;
					break;
				}
				//			Caso não exista pedir os dados do novo produto
				//				Descrição e preço unitário ao operador. 
				cin.ignore(1, EOF);
				cout << "Descrição do produto: " << endl;
				cin.getline(stProduto.cDescricaoProd, EXTEN_DESCRICAO, '\n');
				cout << "Digite o preco unitario do produto: " << endl;
				cin >> stProduto.dPrecoUnit;
				//			Indicar que o produto está ativo 
				stProduto.cProdutoAtivo = 'A';
				//			Gravar o novo produto através da função GravaPosicional 
				if (!GravaPosicional(nPosicao, &stProduto, fdProduto))
				{// write error
					cout << "Erro de gravacao do arquivo " << CAMINHO_DO_CADASTRO << endl;
					PAUSA;
					break;
				}
				//			analisar o seu retorno e voltar ao menu
				//			Sempre testar os erros possíveis e avisar ao
				//			perador caso haja erro.
				// ....

				break;							// cai fora do switch e volta ao menu
			case EXIBIR_DADOS_PRODUTO:
				// <<<<5>>>>. Buscar o índice do produto dentro do arquivo
				//				através da função PedeValidaGrupoCodigoProduto
				//				Verificar se a transação foi cancelada e voltar ao menu
				if (!PedeValidaGrupoCodigoProduto(&nGrupo, &nCodigo, &nPosicao, "Cadastrar Produto"))
				{// canceled operation
					break;
				}

				//			Se o produto não está cadastrado ou não existe 
				//				avisar ao operador e voltar ao menu
				if (!LerPosicional(nGrupo, nCodigo, nPosicao, &stProduto, fdProduto))
				{// read error
					cout << "Erro de leitura do arquivo " << CAMINHO_DO_CADASTRO << endl;
					PAUSA;
					break;
				}
				//			Caso esteja cadastrado, exibir os seus dados e
				//			aguardar a visualização do operador para voltar ao menu
				if (stProduto.cProdutoAtivo == 'I')
				{
					cout << "Produto não cadastrado!" << endl;
				}
				//			Formate com o sprintf uma visualização agradável.
				cout << "Produto " << stProduto.nCodProdGrupo << " - " << stProduto.cDescricaoProd << " de preco " << stProduto.dPrecoUnit;
				PAUSA;
				// ......

				break;							// cai fora do switch
			case LISTAGEM_GERAL_GRUPO:
				// <<<<9>>>> - Pedir o grupo a ser listado 1 - Pesados  (com do....while)
				//			   							   2 - Cereais
				//										   .......
				//										   0 - Cancelar
				//												Selecione: ?
				do
				{
					for (i = 0; i < QTDE_GRUPOS; i++)
					{
						cout << (i + 1) << " - " << vetNomesGrupos[i] << endl;
					}
					cout << "0 - Para cancelar a transação" << endl <<
						"\n\tSelecione: ";
					cin >> nGrupo;
					if (nGrupo == 0)						// cancelar?
					{
						break;
					}
				} while (nGrupo < 1 || nGrupo > QTDE_GRUPOS);
				//				Em função do grupo informado, buscar em stProduto o posicional
				//					inicial deste grupo.
				nPosicao = stGrupo.vetIniQtde[nGrupo].nIniGrupo;

				
				i = 0;
				for (; i <5; i++)
				{
					if (fseek(fdProduto, nPosicao * sizeof(PRODUTO), SEEK_SET) != 0)	// erro?
					{
						break;										// avisa o erro
					}

					if (fread_s(&stProduto, sizeof(PRODUTO), sizeof(PRODUTO), 1, fdProduto) == 0) // erro?
					{
						break;
					}
					nPosicao++;
				}
				cout << "Continuar listagem?" << endl;
				cin >> cOpcao;					// pegar opção do operador
				cOpcao = toupper(cOpcao);		// converte para maiúscula
				if (cOpcao == 'S')				// sair realmente?
				{
					cout << "Encerrado pelo operador!!!" << endl;
					system("pause");
					break;						// sai do programa
				}
				//				Codificar um fseek para posicionar no primeiro produto do
				//				grupo. Fazer um loop de leitura sequencial e exibição de 5 produtos
				//					ativos do grupo
				//				Perguntar se vai continuar com sim ou não.
				//				Se disser continuar, continuar com a listagem de até mais 5
				//					produtos ativos.
				//				Fazer um cabeçalho indicando o nome do grupo sendo listado


				break;
			case EXCLUIR_PRODUTO:
				// <<<<5>>>>. Buscar o índice do produto dentro do arquivo
				//				através da função PedeValidaGrupoCodigoProduto
				if (!PedeValidaGrupoCodigoProduto(&nGrupo, &nCodigo, &nPosicao, "Cadastrar Produto"))
				{// canceled operation
					break;
				}
				//				Verificar se a transação foi cancelada e voltar ao menu
				//			Se o produto não está cadastrado ou não existe 
				//				avisar ao operador e voltar ao menu
				if (!LerPosicional(nGrupo, nCodigo, nPosicao, &stProduto, fdProduto))
				{// read error
					cout << "Erro de leitura do arquivo " << CAMINHO_DO_CADASTRO << endl;
					PAUSA;
					break;
				}

				if (stProduto.cProdutoAtivo == 'I')
				{
					cout << "Produto não cadastradp!" << endl;
					PAUSA;
					break;
				}
				cout << "Produto " << stProduto.nCodProdGrupo << " - " << stProduto.cDescricaoProd << " de preco " << stProduto.dPrecoUnit << endl << "Certeza que deseja excluir?";
				PAUSA;
				cin >> cOpcao;					// pegar opção do operador
				cOpcao = toupper(cOpcao);		// converte para maiúscula
				if (cOpcao == 'N')				// sair realmente?
				{	
					cout << "Encerrado pelo operador!!!" << endl;
					system("pause");
					break;					
				}

				stProduto.cProdutoAtivo = 'I';
				if (!GravaPosicional(nPosicao, &stProduto, fdProduto))
				{// write error
					cout << "Erro de gravacao do arquivo " << CAMINHO_DO_CADASTRO << endl;
					PAUSA;
					break;
				}

				//			Caso esteja cadastrado, exibir os seus dados e
				//			aguardar a visualização e a confirmação da exclusão pelo
				//			operador.
				//			Se o operador não confirmar volte ao menu
				//			e caso contrário torne o produto inativo e
				//			grave o mesmo com a função GravaPosicional
				//			Analisar erro e voltar ao menu
				// ....

				break;
			case SAIR_DO_PROGRAMA:
				cout << "Deseja mesmo sair do programa? (S ou N):";
				cin	 >> cOpcao;					// pegar opção do operador
				cOpcao = toupper(cOpcao);		// converte para maiúscula
				if (cOpcao == 'S')				// sair realmente?
				{	// vai sair realmente
					fclose(fdProduto);			// fechar o arquivo
					cout << "Encerrado pelo operador!!!" << endl;
					system("pause");
					return;						// sai do programa
				}
				break;							// cai fora do switch
			default:							// opção errada!
				cout << "Opcao do menu errada!!!" <<
					endl;
				system("pause");
		} //switch
	} // while
} // main