#include "inicio.h"
#include <fstream>
#include<iostream>
#include<iomanip>
#include<locale>
#include<string>
using namespace std;

void fila_espera(string u_nome) //cupido e pedro 11/5
{
	
    /*ifstream myFile("ultimo_nome.txt");
    string line = "";
    int i = 0;
    if (myFile.is_open()) {  //verificar se o ficheiro existe
        while (getline(myFile, line)) {
            cout << line;
            i++;
        }
    }
    myFile.close();
	cout << "exemplo";
	cout << setw(10);
	cout << "exemplo1";
	cout << setw(10);
	cout << "exemplo2";//o 10 refere-se á distância entre o anterior;*/
}

Pessoa nova_pessoa(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES]) // mai 11/05
{
    Pessoa novaPessoa;
    novaPessoa.p_nome = pnomes[rand() % NUM_P_NOMES];
    novaPessoa.u_nome = pnomes[rand() % NUM_U_NOMES];
    novaPessoa.numero_bilhete = rand() % 10000 + 1000;
    return novaPessoa;
}

void saida_passageiros() //pedro
{
    //gerar um numero de 1 a 4 e se sair 1 o passageiro sai :)
}

void cria_autocarros()
{
}

void cria_paragens() //pedro e cupido
{
    int Paragens = rand() % 6 + 4; //de 4 a 9
}
