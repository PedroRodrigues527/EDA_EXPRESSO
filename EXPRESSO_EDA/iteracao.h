#pragma once
#include "inicio.h"
#include "percurso.h"
#include "Fila.h"
#include <string>
using namespace std;

// Para funções que correrão em cada iteração na execução

Item* menuOpcoes(percurso pe, Item* Fila);

void iteraFila(Item* primeiro, string* listaPnomes, string* listaUnomes, int num, bilhete* bilhetesUsados);

autocarro cria_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES]);
Item* inserir_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES], percurso pe, Item* Fila);

bool saida_passageiro();