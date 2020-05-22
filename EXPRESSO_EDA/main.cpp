#include <iostream>
#include <iomanip> // para importar o setw
#include <stdlib.h>
#include <locale>
#include "inicio.h"
#include "percurso.h"
#include "Fila.h"
#include "iteracao.h"

using namespace std;
locale pt = pt.global(locale("pt-PT.UTF8"));

int main() {
	srand((unsigned)time(NULL));

	//fila_espera();
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
	//cria_autocarro(listaPrimeironome, listaUltimonome);

	percurso pe;
	pe.inicio = new percurso::paragem;
	criarPercurso(pe, listaParagens);
	imprimirPercurso(pe);
	
	//para testar
	//autocarro ac = cria_autocarro(listaPrimeironome, listaUltimonome);
	//Fila = inserir_autocarro(ac, pe, Fila);
	//cout << endl;
	//imprimeFila(Fila);
	//cout << hex << uppercase << pe.inicio->autocarro.matricula;


	char escolha_do_utilizador;
	do { // (mai e paulo drumond 18/05)
		cout << endl << " -------- " << endl;
		cout << " Pressione 'o' para poder ver as opções disponiveis." << endl;
		cout << " Pressione 's' para seguir para a próxima iteração." << endl;
		cout << " Prima qualquer outra tecla para fechar o programa." << endl;
		cin >> escolha_do_utilizador;

		switch (escolha_do_utilizador)
		{
		case 'o': // aceder às operações
			menuOpcoes();
			break;
		case 's': // iterar
			//incompleto
			break;
		default:
			break;
		}

	} while ((escolha_do_utilizador == 'o') || (escolha_do_utilizador == 's')); // repetir enquanto que a opção escolhida não for 'o' nem 's'

	return 0;
}
