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

void imprimeFila(Item* primeiro, string* listaPnomes, string* listaUnomes) { //Cupido, Pedro e Diogo 18/05
	Item* temp = primeiro;
	//for (int i = 0; i < 10; i++) {
	//	//cout << setw(0);
	//	cout << temp->pessoa.u_nome << setw(10) << endl;
	//	temp = temp->seguinte;
	//	//cout << setw(0);
	//}
	//for (int i = 0; i < 10; i++) {
	//	//cout << setw(10);
	//	cout << temp->pessoa.u_nome << setw(10) << endl;
	//	temp = temp->seguinte;
	//	//cout << setw(10);
	//}
	//for (int i = 0; i < 10; i++) {
	//	//cout << setw(20);
	//	cout << temp->pessoa.u_nome << setw(10) << endl;
	//	temp = temp->seguinte;
	//	//cout << setw(20);
	//}

	string array[30];
	for (int i = 0; i < 30; i++) {
		array[i] = temp->pessoa.u_nome;
		temp = temp->seguinte;
	}

	for (int j = 0; j < 10; j++) {
		cout << array[29 - j] << setw(20) ; //<< array[19 - j] << setw(20) << array[9 - j] << endl;
		cout << array[19 - j] << setw(20);
		cout << array[9 - j] << endl;
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
