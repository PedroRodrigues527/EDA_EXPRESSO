#pragma once
#include "inicio.h"
#include "Fila.h"
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
	struct bilhete* esq;
	struct bilhete* dir;
};

struct percurso { //pedro e mai

	struct paragem {
		autocarro autocarro;
		bilhete* arvore_bilhetes; // apontador para o inicio da arvore binária
		string nome;
		paragem* seguinte = NULL;
	};

	int numParagensTotal;
	paragem* inicio;
};


bilhete* novoNodo_ArvoreBilhetes(int num_bilhete);
bilhete* insereArvoreBilhetes(int num_bilhete, bilhete* raiz);

void criarPercurso(percurso& pe, string* listaParagens);
void imprimirPercurso(percurso& pe);

bool autocarroExiste(autocarro ac);

void alteraMotorista(percurso& pe);