#include <iostream>
#include <iomanip> // para importar o setw
#include <string>
#include <windows.h>
#include <locale>
#include "inicio.h"
#include "Fila.h"
using namespace std;

int main() {
	//Inicialização
	locale pt = pt.global(locale("pt-PT.UTF8"));
	string* listaPrimeironome = new string[NUM_P_NOMES];
	string* listaUltimonome = new string[NUM_U_NOMES];
	string* listaParagens = new string[NUM_PARAGENS];
	lerFicheiroPrimeiroNome(listaPrimeironome);
	lerFicheiroUltimoNome(listaUltimonome);
	lerFicheiroParagens(listaParagens);

	Item* Fila = new Item;
	Fila->seguinte = NULL;
	//inicializaFila(Fila, listaPrimeironome, listaUltimonome);
	while (Fila->seguinte != NULL) {
		cout << Fila->pessoa.numero_bilhete << endl;
		Fila = Fila->seguinte;
	}

	return 0;
}
