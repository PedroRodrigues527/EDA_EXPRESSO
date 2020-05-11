#pragma once
#include <iostream>
#include <string>
#include "Fila.h"
#define NUM_P_NOMES 44
#define NUM_U_NOMES 97
#define NUM_PARAGENS 54 //Cupido 11/05/20
using namespace std;

struct Pessoa { //mai 11/05
	string p_nome;
	string u_nome;
	int numero_bilhete;
};

struct Item { //mai 11/05
	Item* seguinte;
	Pessoa pessoa;
};

// void fila_espera(string u_nome);

Pessoa criaPessoa(string pnomes[], string unomes[]); //mai 11/05

bool saida_passageiros();

void cria_autocarros();

void cria_paragens();

//Cupido 11/05/20
void lerFicheiroPrimeiroNome(string listaprimeironome[]);
void lerFicheiroUltimoNome(string listaultimonome[]);
void lerFicheiroParagens(string listaparagens[]);
