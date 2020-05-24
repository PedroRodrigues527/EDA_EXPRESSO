#pragma once
#include "inicio.h"
#include "iteracao.h"

using namespace std;

void printItem(string name, int tam); // professor

void inicializaFila(Item* primeiro, string* listaPnomes, string* listaUnomes);
void entraFila(Item* primeiro, Pessoa novapessoa);
void iteraFila(Item* primeiro, string* listaPnomes, string* listaUnomes, int num);

void imprimeFila(Item* primeiro);
int ContaFila(Item* primeiro);

Item* removerInicio(Item* Fila);
Item* removerFim(Item* Fila);
Item* removerMeio(Item* Fila, int bilhete);
Item* RemoverPessoaFiladeEspera(Item* Fila);