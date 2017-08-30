#pragma once
// declarações do programa que ensaia o uso de vetores
#include <iostream>
#include <Windows.h>
using namespace std;
// defines
#define PAUSA							system("pause")
#define LIMPAR_TELA						system("cls")
#define BRASIL							setlocale(LC_ALL, "portuguese_brazil")
#define QTDE_INTEIRAS					1000
#define QTDE_OUTRA						2000
// protótipos das funções
void ListarVetorInteiras(int vetorInteiras[], int nQtde, int nQtdePorLinha);
void BubleSort(int vtInt[], int nQtde, bool flgOrdem);
void ListarVetorChar(char vtChar[], int nQtde, int nQtdePorLinha);


