#pragma once
#include "inicio.h"
#include "Fila.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <locale>
#include <string>

using namespace std;
//
//void fila_espera(string u_nome) //cupido e pedro 11/5
//{
//	
//    /*ifstream myFile("ultimo_nome.txt");
//    string line = "";
//    int i = 0;
//    if (myFile.is_open()) {  //verificar se o ficheiro existe
//        while (getline(myFile, line)) {
//            cout << line;
//            i++;
//        }
//    }
//    myFile.close();
//	cout << "exemplo";
//	cout << setw(10);
//	cout << "exemplo1";
//	cout << setw(10);
//	cout << "exemplo2";//o 10 refere-se á distância entre o anterior;*/
//}

Pessoa criaPessoa(string pnomes[], string unomes[]) // mai 11/05
{
    Pessoa novaPessoa;
    novaPessoa.p_nome = pnomes[rand() % NUM_P_NOMES];
    novaPessoa.u_nome = unomes[rand() % NUM_U_NOMES];
    // NOTA: os ultimos nomes tem que ser diferentes
    novaPessoa.numero_bilhete = rand() % 10000 + 1000;

    return novaPessoa;
}

bool saida_passageiros() //pedro
{
    //numero aleatorio de 1 a 4
    return ((rand() % 4 + 1) == 1);
    // se sair 1 o passageiro sai caso contrario nao sai
}

void cria_autocarros()
{
}

void cria_paragens() //pedro e cupido
{
    int Paragens = rand() % 6 + 4; //de 4 a 9
}

void lerFicheiroPrimeiroNome(string listaprimeironome[]) { //Cupido 11/05/20
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

void lerFicheiroUltimoNome(string listaultimonome[]) { //Cupido 11/05/20
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

void lerFicheiroParagens(string listaparagens[]) { //Cupido 11/05/20
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
