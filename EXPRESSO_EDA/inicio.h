#pragma once
#define NUM_NOMES 10
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

void cria_passageiros();

void saida_passageiros();

void cria_autocarros();

void cria_paragens();