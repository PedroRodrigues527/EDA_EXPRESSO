#pragma once
#include "inicio.h"
#include "Fila.h"
#include "percurso.h"

// Para fun��es que correr�o em cada itera��o na execu��o

void menuOpcoes();

autocarro cria_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES]);

Item* inserir_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES], percurso pe, Item* Fila);