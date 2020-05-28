#pragma once
#include "Fila.h"
#define NUM_PARAGENS 53 //Cupido 11/05/20

using namespace std;

struct autocarro { // mai

	Item* primeiro; // apontador para lista ligada de passageiros

	int matricula = 0; // inicializado a 0, mas é um numero hexadecimal de 1000 a FFFF (4096 a 65535);
	int capacidade; // tamanho da lista ligada

	string p_nome_C; // do condutor
	string u_nome_C;
};

// arvore de procura binária // mai
struct bilhete {
	int num;
	struct bilhete* esq = NULL;
	struct bilhete* dir = NULL;
};

struct percurso { //pedro e mai

	struct paragem {
		autocarro autocarro;
		bilhete* arvore_bilhetes = new bilhete; // apontador para o inicio da arvore binária
		string nome;
		paragem* seguinte = NULL;
		int index; // será o index da paragem, utilizado quando o utilizador precisa de escolher uma paragem
	};

	int numParagensTotal;
	paragem* inicio;
};

bilhete* novoNodoArvoreBilhetes(int num_bilhete);
bilhete* insereArvoreBilhetes(int num_bilhete, bilhete* raiz);
bool procuraArvoreBilhetes(int num_bilhete, bilhete* raiz);
void imprimeArvoreBilhetes(bilhete* raiz, int nivel);
void imprimeArvoreBilhetesInfixa(bilhete* raiz);

void criarPercurso(percurso& pe, string* listaParagens);
void imprimirPercurso(percurso& pe);

bool autocarroExiste(autocarro ac);
void RemoverPessoaAutocarro(percurso::paragem* inicio);

void alteraMotorista(percurso& pe);