#pragma once
#include "inicio.h"
#include "Fila.h"
#include "percurso.h"

// Para funções que correrão em cada iteração na execução

void menuOpcoes();

autocarro cria_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES]);

Item* inserir_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES], percurso pe, Item* Fila);