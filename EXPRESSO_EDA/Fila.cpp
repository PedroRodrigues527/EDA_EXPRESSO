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

	int tamanho = ContaFila(primeiro);

	string* arrayUnomes = new string[tamanho];
	int* arrayNumBilhete = new int[tamanho];

	for (int i = 0; i < tamanho; i++) {
		arrayUnomes[i] = temp->pessoa.u_nome;
		arrayNumBilhete[i] = temp->pessoa.numero_bilhete;
		temp = temp->seguinte;
	}

	cout << " --- Fila de Espera --- " << endl;
	for (int j = tamanho-1; j >=0 ; j--) {
		cout << "| " << setw(12) << left << arrayUnomes[j] << " | " << setw(6) << left << arrayNumBilhete[j] << " |";
		if ((tamanho - j) % 3 == 0) {
			cout << endl;
		}
	}
	cout << endl << endl;
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