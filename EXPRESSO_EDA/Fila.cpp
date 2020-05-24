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
for (int j = tamanho - 1; j >= 0; j--) {
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

Item* removerInicio(Item* Fila) { //cupido
	Item* temp = Fila->seguinte;
	delete Fila;
	return temp;
}

Item* removerFim(Item* Fila) { //cupido
	Item* temp = Fila;
	while (temp->seguinte->seguinte != NULL) {
		temp = temp->seguinte;
	}
	delete temp->seguinte;
	temp->seguinte = NULL;
	return Fila;
}

Item* removerMeio(Item* Fila, int bilhete) { //cupido
	Item* temp = Fila;
	do {
		if (temp->seguinte->pessoa.numero_bilhete == bilhete) {
			temp->seguinte = temp->seguinte->seguinte;
			return Fila;
		}
		temp = temp->seguinte;
	} while (temp->seguinte != NULL);
}

Item* RemoverPessoaFiladeEspera(Item* Fila) { //cupido
	int bilhete;
	cout << "Insere o numero de bilhete para remover passageiro em fila de espera: ";
	cin >> bilhete;
	Item* temp = Fila;
	if (Fila == NULL) {
		cout << "Fila vazia!";
		return NULL;
	}
	else if (temp->pessoa.numero_bilhete == bilhete) {
		return removerInicio(Fila);
	}
	else {
		do {
			temp = temp->seguinte;
			if (temp->seguinte == NULL && temp->pessoa.numero_bilhete == bilhete) {
				//cout << "testes1" << endl;
				return removerFim(Fila);
			}
			else if (temp->pessoa.numero_bilhete == bilhete) {
				//cout << "testes2" << endl;
				//cout << temp->seguinte->pessoa.numero_bilhete << " " << temp->seguinte->pessoa.p_nome << " " << temp->seguinte->pessoa.u_nome << endl;
				return removerMeio(Fila, bilhete);
			}
		} while (temp->seguinte != NULL);
		if (temp->seguinte == NULL && temp->pessoa.numero_bilhete != bilhete) {
			cout << "Numero de Bilhete nao encontrado!" << endl;
			return Fila;
		}
	}
}

void RemoverPessoaAutocarro(percurso::paragem* inicio) { //cupido e mai
	int bilhete;
	bool removido = false;
	cout << "Insere o numero de bilhete para remover passageiro nos autocarros: ";
	cin >> bilhete;
	percurso::paragem* temp = inicio;
	if (!autocarroExiste(temp->autocarro)) {
		cout << "Nao existem autocarros!";
	}
	while ((temp->seguinte != NULL) && (!removido) && autocarroExiste(temp->autocarro)) {
		Item* aux = temp->autocarro.primeiro;
		if (aux->pessoa.numero_bilhete == bilhete) {
			//cout << "foi ao inicio" << endl;
			temp->autocarro.primeiro = removerInicio(temp->autocarro.primeiro);
			temp->autocarro.capacidade -= 1;
			removido = true;
			break;
		}
		for (int i = 0; i < temp->autocarro.capacidade; i++) {
			if (aux->seguinte == NULL && aux->pessoa.numero_bilhete == bilhete) {
				//cout << "foi ao fim" << endl;
				temp->autocarro.primeiro = removerFim(temp->autocarro.primeiro);
				temp->autocarro.capacidade -= 1;
				removido = true;
				break;
			}
			else if (aux->seguinte != NULL && aux->pessoa.numero_bilhete == bilhete) {
				//cout << "foi ao meio" << endl;
				temp->autocarro.primeiro = removerMeio(temp->autocarro.primeiro, bilhete);
				temp->autocarro.capacidade -= 1;
				removido = true;
				break;
			}
			aux = aux->seguinte;
		}
		temp = temp->seguinte;
	}
	if (removido) {
		cout << "Removido com Sucesso!" << endl;
	}
	else {
		cout << "Nao encontrado!" << endl;
	}
}