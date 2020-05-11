#include "Fila.h"
#include "inicio.h"
#include <iostream>

using namespace std;

void inicializaFila(Item* primeiro, string* listaPnomes, string* listaUnomes) {
	primeiro->pessoa = Criapessoa(listaPnomes, listaUnomes);
	for (int i = 0; i < 30; i++) {
		Pessoa novapessoa = Criapessoa(listaPnomes, listaUnomes);
		entraFila(primeiro, novapessoa);
	}
}
void entraFila(Item* primeiro, Pessoa novapessoa) {
	Item* aux = new Item;
	aux->pessoa = novapessoa;
	aux->seguinte = NULL;
	if (primeiro == NULL) {
		primeiro = aux;
	}
	else {
		Item* temp = primeiro;
		while (temp->seguinte != NULL) {
			temp = temp->seguinte;
		}
		temp->seguinte = aux;
	}
}
