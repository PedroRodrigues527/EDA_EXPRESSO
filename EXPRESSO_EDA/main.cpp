#include <iostream>
#include <iomanip> // para importar o setw
#include "inicio.h"
using namespace std;

locale pt = pt.global(locale("pt-PT.UTF8"));

int main() {
	//fila_espera();
	string* listaPrimeironome = new string[NUM_P_NOMES];
	string* listaUltimonome = new string[NUM_U_NOMES];
	string* listaParagens = new string[NUM_PARAGENS];
	lerFicheiroPrimeiroNome(listaPrimeironome);
	lerFicheiroUltimoNome(listaUltimonome);
	lerFicheiroParagens(listaParagens);
	return 0;
}
