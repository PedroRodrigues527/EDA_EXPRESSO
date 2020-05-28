#include "inicio.h"
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <locale>
//#include <string>

using namespace std;

Pessoa criaPessoa(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES], bilhete* bilhetesUsados) // mai 11/05 e 28/05
{
    Pessoa novaPessoa;
    novaPessoa.p_nome = pnomes[rand() % NUM_P_NOMES];
    novaPessoa.u_nome = unomes[rand() % NUM_U_NOMES];

    // os bilhetes têm que ser sempre únicos, logo guardamos todos os bilhetes numa árvore de procura binária "bilhetesUsados"
    int num_bilhete = rand() % 10000 + 1000;

    while (procuraArvoreBilhetes(num_bilhete, bilhetesUsados)) { // só irá sair deste loop se a procura retornar falsa, ou seja, se não encontrar na árvore de bilhetes
        num_bilhete = rand() % 10000 + 1000;
    }

    insereArvoreBilhetes(num_bilhete, bilhetesUsados);
    novaPessoa.numero_bilhete = num_bilhete;
    return novaPessoa;
}

void inicializaFila(Item* primeiro, string* listaPnomes, string* listaUnomes, bilhete* bilhetesUsados) { //mai 11/05
    primeiro->pessoa = criaPessoa(listaPnomes, listaUnomes, bilhetesUsados);
    for (int i = 1; i < 30; i++) {
        Pessoa novapessoa = criaPessoa(listaPnomes, listaUnomes, bilhetesUsados);
        entraFila(primeiro, novapessoa);
    }
}


void lerFicheiroPrimeiroNome(string* listaprimeironome) { //Cupido 11/05
    ifstream myFile("primeiro_nome.txt");
    string line = "";
    int i = 0;
    if (myFile.is_open()) {  //verificar se o ficheiro existe
        while (getline(myFile, line)) {
            listaprimeironome[i] = line;
            i++;
        }
    }
    myFile.close();
    /*for (int j = 0; j < NUM_P_NOMES; j++) {
        cout << listaprimeironome[j] << endl;
    }*/
}

void lerFicheiroUltimoNome(string* listaultimonome) { //Cupido 11/05/20
    ifstream myFile("ultimo_nome.txt");
    string line = "";
    int i = 0;
    if (myFile.is_open()) {  //verificar se o ficheiro existe
        while (getline(myFile, line)) {
            listaultimonome[i] = line;
            i++;
        }
    }
    myFile.close();
    /*for (int j = 0; j < NUM_U_NOMES; j++) {
        cout << listaultimonome[j] << endl;
    }*/
}

void lerFicheiroParagens(string* listaparagens) { //Cupido 11/05/20
    ifstream myFile("paragens.txt");
    string line = "";
    int i = 0;
    if (myFile.is_open()) {  //verificar se o ficheiro existe
        while (getline(myFile, line)) {
            listaparagens[i] = line;
            i++;
        }
    }
    myFile.close();
    /*for (int j = 0; j < NUM_PARAGENS; j++) {
        cout << listaparagens[j] << endl;
    }*/
}
