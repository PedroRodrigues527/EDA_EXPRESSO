#include <iostream>
#include <iomanip> // para importar o setw
#include <stdlib.h>
#include <locale>
#include "inicio.h"
#include "percurso.h"
#include "Fila.h"
#include "iteracao.h"

using namespace std;

//PORQUE O ITERACAO.H NAO FUNCIONA (?)
void menuOpcoes(percurso pe);
Item* inserir_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES], percurso pe, Item* Fila);

int main() {

	locale pt = pt.global(locale("pt-PT.UTF8"));
	srand((unsigned)time(NULL));

	string* listaPrimeironome = new string[NUM_P_NOMES];
	string* listaUltimonome = new string[NUM_U_NOMES];
	string* listaParagens = new string[NUM_PARAGENS];
	lerFicheiroPrimeiroNome(listaPrimeironome);
	lerFicheiroUltimoNome(listaUltimonome);
	lerFicheiroParagens(listaParagens);

	Item* Fila = new Item;
	Fila->seguinte = NULL;
	inicializaFila(Fila, listaPrimeironome, listaUltimonome);

	imprimeFila(Fila);

	percurso pe;
	pe.inicio = new percurso::paragem;
	criarPercurso(pe, listaParagens);
	imprimirPercurso(pe);

	
	char escolha_do_utilizador;
	do { // (mai e paulo drumond 18/05)
		cout << endl << "---------------" << endl;
		cout << " Pressione 'o' para poder ver as opções disponiveis." << endl;
		cout << " Pressione 's' para seguir para a próxima iteração." << endl;
		cout << " Prima qualquer outra tecla para fechar o programa e terminar a execução." << endl;
		cin >> escolha_do_utilizador;

		switch (escolha_do_utilizador)
		{
		case 'o': // aceder às operações
			menuOpcoes(pe);
			imprimeFila(Fila);
			imprimirPercurso(pe);
			break;
		case 's': // iterar
			//incompleto
			Fila = inserir_autocarro(listaPrimeironome, listaUltimonome, pe, Fila);
			cout << endl;

			iteraFila(Fila, listaPrimeironome, listaUltimonome, 15);
			imprimeFila(Fila);
			imprimirPercurso(pe);
			break;
		default:
			break;
		}

	} while ((escolha_do_utilizador == 'o') || (escolha_do_utilizador == 's')); // repetir enquanto que a opção escolhida não for 'o' nem 's'

	return 0;
}
