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


struct arvore_bilhetes { // arvore de procura binária // mai
	struct bilhete {
		int num;
		bilhete* esq;
		bilhete* dir;
	};
	bilhete* raiz;
};


struct percurso { //pedro e mai

	struct paragem {
		autocarro autocarro;
		arvore_bilhetes lista_bilhetes;
		string nome;
		paragem* seguinte = NULL;
	};

	int numParagensTotal;
	paragem* inicio;
};


void criarPercurso(percurso& pe, string* listaParagens);
void imprimirPercurso(percurso& pe);

bool autocarroExiste(autocarro ac);
