#pragma once
#include "inicio.h"
using namespace std;


struct autocarro { // mai
	struct passageiro {
		Pessoa pessoa;
		passageiro* seguinte;
	};
	passageiro* primeiro; // apontador para lista ligada de passageiros

	char matricula[4];
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
		paragem* seguinte;
	};
	paragem* inicio;
};


void criarPercurso(percurso& pe, string* listaParagens);
void imprimirPercurso(percurso& pe);