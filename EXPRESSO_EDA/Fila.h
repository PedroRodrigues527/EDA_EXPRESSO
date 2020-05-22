#pragma once
#include <iostream>
#include "inicio.h"

using namespace std;

void printItem(string name, int tam); // professor

void inicializaFila(Item* primeiro, string* listaPnomes, string* listaUnomes);
void entraFila(Item* primeiro, Pessoa novapessoa);

void imprimeFila(Item* primeiro);
int ContaFila(Item* primeiro);