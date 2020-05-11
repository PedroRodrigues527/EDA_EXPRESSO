#pragma once
#define NUM_P_NOMES 44
#define NUM_U_NOMES 97
#include<iostream>
using namespace std;

struct Pessoa {
	string p_nome;
	string u_nome;
	int numero_bilhete;
};

struct ElementoFila {
	Pessoa* seguinte;
	Pessoa pessoa;
};


void fila_espera(string u_nome);

Pessoa nova_pessoa(string* pnomes, string* unomes);

bool saida_passageiros();

void cria_autocarros();

void cria_paragens();
