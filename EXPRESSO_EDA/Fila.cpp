#include "Fila.h"
#include "percurso.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printItem(string name, int tam) { // professor
	unsigned int i;
	int count_n = 0;
	for (i = 0; i < name.size(); ++i)
	{
		std::cout << name[i];
		if ((int)name[i] < 0)
			count_n++;

	}

	count_n = (int)count_n / 2;
	i = i - count_n;
	while (i <= tam) {
		cout << " ";
		i++;
	}
}

void inicializaFila(Item* primeiro, string* listaPnomes, string* listaUnomes) { //mai 11/05
	primeiro->pessoa = criaPessoa(listaPnomes, listaUnomes);
	for (int i = 1; i < 30; i++) {
		Pessoa novapessoa = criaPessoa(listaPnomes, listaUnomes);
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

	cout << endl << " --- Fila de Espera (" << ContaFila(primeiro) << ") --- " << endl;
	for (int j = tamanho-1; j >=0 ; j--) {
		cout << "| ";
		printItem(arrayUnomes[j], 12);
		cout << " :";
		printItem(to_string(arrayNumBilhete[j]), 6);
		cout << " |";
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

void iteraFila(Item* primeiro, string* listaPnomes, string* listaUnomes, int num) // mai 23/05
{
	for (int i = 0; i < num; i++) {
		Pessoa novapessoa = criaPessoa(listaPnomes, listaUnomes);
		entraFila(primeiro, novapessoa);
	}
}

int ContaFila(Item* primeiro) { //mai 18/05
	Item* temp = primeiro;
	int conta = 0;
	do {
		temp = temp->seguinte;
		conta++;
	} while (temp != NULL);
	return conta;
}