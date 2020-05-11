#pragma once
#include "Fila.h"
#include "inicio.h"
#include <iostream>

using namespace std;

void entraFila(Item* primeiro, Pessoa novapessoa) {
	Item* aux = new Item;
	aux->pessoa = novapessoa;
	aux->seguinte = NULL;
	if (primeiro == NULL)
		primeiro = aux;
	else {
		Item* temp = primeiro;
		while (temp->seguinte != NULL) {
			temp = temp->seguinte;
		}
		temp->seguinte = aux;
	}
}

void inicializaFila(Item* primeiro, string listaPnomes[], string listaUnomes[]) {
	primeiro->pessoa = criaPessoa(listaPnomes, listaUnomes);
	for (int i = 0; i < 30; i++) {
		Pessoa novapessoa = criaPessoa(listaPnomes, listaUnomes);
		entraFila(primeiro, novapessoa);
	}
}