#pragma once
#include "percurso.h"
#include "Fila.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <locale>
#define NUM_P_NOMES 44
#define NUM_U_NOMES 97

using namespace std;


Pessoa criaPessoa(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES], bilhete* bilhetesUsados);
void inicializaFila(Item* primeiro, string* listaPnomes, string* listaUnomes, bilhete* bilhetesUsados);

//Cupido 11/05/20
void lerFicheiroPrimeiroNome(string* listaprimeironome);
void lerFicheiroUltimoNome(string* listaultimonome);
void lerFicheiroParagens(string* listaparagens);
