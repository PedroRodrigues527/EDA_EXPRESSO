#pragma once
#define NUM_P_NOMES 44
#define NUM_U_NOMES 97
#define NUM_PARAGENS 53 //Cupido 11/05/20
#include <iostream>
using namespace std;

struct Pessoa { //mai 11/05
	string p_nome;
	string u_nome;
	int numero_bilhete;
};

struct Item { //mai 11/05
	Item* seguinte = NULL;
	Pessoa pessoa;
};

void fila_espera(string u_nome);

Pessoa criaPessoa(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES]); //mai 11/05

bool saida_passageiro();

//Cupido 11/05/20
void lerFicheiroPrimeiroNome(string* listaprimeironome);
void lerFicheiroUltimoNome(string* listaultimonome);
void lerFicheiroParagens(string* listaparagens);
