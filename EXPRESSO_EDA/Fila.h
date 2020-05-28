#pragma once
//#include "inicio.h"
#include <string>

using namespace std;

struct Pessoa { //mai 11/05
	string p_nome;
	string u_nome;
	int numero_bilhete;
};

struct Item { //mai 11/05
	Item* seguinte = NULL;
	Pessoa pessoa;
};

void printItem(string name, int tam); // professor


void entraFila(Item* primeiro, Pessoa novapessoa);

void imprimeFila(Item* primeiro);
int ContaFila(Item* primeiro);

Item* removerInicio(Item* Fila);
Item* removerFim(Item* Fila);
Item* removerMeio(Item* Fila, int bilhete);
Item* RemoverPessoaFiladeEspera(Item* Fila);