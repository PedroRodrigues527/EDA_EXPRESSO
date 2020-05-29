#include <iostream>
#include <iomanip> // para importar o setw
#include <stdlib.h>
#include <locale>
#include <Windows.h>
#include "inicio.h"
#include "percurso.h"
#include "Fila.h"
#include "iteracao.h"

using namespace std;

locale pt = pt.global(locale("pt-PT.UTF8"));


int main() {

	//locale pt = pt.global(locale("pt-PT.UTF8"));
	//locale::global(locale(""));
	//setlocale(LC_ALL, "");
	//SetConsoleOutputCP(1254);
	//SetConsoleCP(1254);

	srand((unsigned)time(NULL));



	// ler os ficheiros .txt
	string* listaPrimeironome = new string[NUM_P_NOMES];
	string* listaUltimonome = new string[NUM_U_NOMES];
	string* listaParagens = new string[NUM_PARAGENS];
	lerFicheiroPrimeiroNome(listaPrimeironome);
	lerFicheiroUltimoNome(listaUltimonome);
	lerFicheiroParagens(listaParagens);



	// inicialização da Fila de Espera
	Item* Fila = new Item;
	Fila->seguinte = NULL;
	bilhete* bilhetesUsados = new bilhete; // inicializamos para não ter que atualizar pelo inicializaFila

	inicializaFila(Fila, listaPrimeironome, listaUltimonome, bilhetesUsados);
	bilhete* aux = bilhetesUsados; // removemos o valor "inicializado" que é sempre negativo e, logo, o resto da árvore encontra-se na sua sub-arvore direita
	bilhetesUsados = bilhetesUsados->dir;
	delete aux;

	imprimeFila(Fila);


	// inicialização do Percurso
	percurso pe;
	pe.inicio = new percurso::paragem;
	criarPercurso(pe, listaParagens);
	imprimirPercurso(pe);


	//testes das arvores
	/*bilhete* raiz = NULL;
	raiz = insereArvoreBilhetes(12, raiz);
	raiz = insereArvoreBilhetes(11, raiz);
	raiz = insereArvoreBilhetes(13, raiz);
	raiz = insereArvoreBilhetes(2, raiz);
	raiz = insereArvoreBilhetes(1, raiz);
	raiz = insereArvoreBilhetes(3, raiz);
	raiz = insereArvoreBilhetes(16, raiz);	
	imprimeArvoreBilhetes(raiz);

	imprimeArvoreBilhetes(bilhetesUsados);*/




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

			Fila = menuOpcoes(pe, Fila);
			imprimeFila(Fila);
			imprimirPercurso(pe);

			break;

		case 's': // iterar

			Fila = inserir_autocarro(listaPrimeironome, listaUltimonome, pe, Fila);
			cout << endl;

			iteraFila(Fila, listaPrimeironome, listaUltimonome, 15, bilhetesUsados);
			imprimeFila(Fila);
			imprimirPercurso(pe);
			break;

		default:

			break;
		}

	} while ((escolha_do_utilizador == 'o') || (escolha_do_utilizador == 's')); // repetir até que a opção escolhida não seja 'o' nem 's'

	return 0;
}
