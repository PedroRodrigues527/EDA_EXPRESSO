#include "Fila.h"
#include "inicio.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void inicializaFila(Item* primeiro, string* listaPnomes, string* listaUnomes) { //mai 11/05
	primeiro->pessoa = Criapessoa(listaPnomes, listaUnomes);
	for (int i = 0; i < 30; i++) {
		Pessoa novapessoa = Criapessoa(listaPnomes, listaUnomes);
		entraFila(primeiro, novapessoa);
	}
}

void imprimeFila(Item* primeiro) { //Cupido, Pedro e Diogo 18/05 (e mai)
	Item* temp = primeiro;
	int tamanho = 29; //ContaFila(primeiro);
	string* array = new string[tamanho];
	for (int i = 0; i < tamanho; i++) {
		array[i] = temp->pessoa.u_nome;
		temp = temp->seguinte;
	}

	int linhas = ceil((float)tamanho / 3);

	if (tamanho % 3 == 0) {      //27 30 33...
		for (int j = 0; j < linhas; j++) {
			cout << setw(20) << left << array[(3 * linhas - 1) - j];
			cout << setw(20) << left << array[(2 * linhas - 1) - j];
			cout << setw(20) << left << array[(linhas - 1) - j] << endl;
		}
	}
	else if (tamanho % 3 == 1) { //28 31 34...
		for (int j = 0; j < linhas-1; j++) {
			cout << setw(20) << left << array[(3 * linhas - 1) - j];
			cout << setw(20) << left << array[(2 * linhas - 1) - j];
			cout << setw(20) << left << array[(linhas - 1) - j] << endl;
		}
	}
	else if (tamanho % 3 == 2) { //29 32 35...
		for (int j = 0; j < linhas; j++) {
			cout << setw(20) << left << array[(3 * linhas - 1) - j];
			cout << setw(20) << left << array[(2 * linhas - 1) - j];
			cout << setw(20) << left << array[(linhas - 1) - j] << endl;
		}
	}
}

void entraFila(Item* primeiro, Pessoa novapessoa) { //mai 11/05
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

int ContaFila(Item* primeiro) { //mai 18/05
	Item* temp = primeiro;
	int conta = 0;
	while (temp->seguinte != NULL) {
		temp = temp->seguinte;
		conta++;
	}
	return conta;
}