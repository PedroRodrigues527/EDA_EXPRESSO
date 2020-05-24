#pragma once
#include "Fila.h"
#include "iteracao.h"
#include "percurso.h"
#include <iostream>
using namespace std;


Item* menuOpcoes(percurso pe, Item* Fila) //paulo drumond 18/05
{
    int num_opcao; // opção de 1 a 5 escolhida pelo utilizador
   
    cout << "1.Remover passageiros nos autocarros." << endl;
    cout << "2.Remover passageiros em fila de espera" << endl;
    cout << "3.Apresentar bilhetes por paragem" << endl;
    cout << "4.Alterar motorista" << endl;
    cout << "5.Remover bilhete da paragem" << endl;
    cout << "-- Introduza o numero da opção a que pretende aceder --" << endl;

    cin >> num_opcao;

    switch (num_opcao)
    {

    case 1:
        cout << "Escolheu a opção: 1.Remover passageiros nos autocarros." << endl;
        break;
    case 2:
        cout << "Escolheu a opção: 2.Remover passageiros em fila de espera" << endl;
        Fila = RemoverPessoaFiladeEspera(Fila);
        imprimeFila(Fila);
        break;
    case 3:
        cout << "Escolheu a opção : 3.Apresentar bilhetes por paragem" << endl;
        break;
    case 4:
        cout << "Escolheu a opção: 4.Alterar motorista" << endl;
        alteraMotorista(pe);
        imprimeFila(Fila);
        break;
    case 5:
        cout << "Escolheu a opção: 5.Remover bilhete da paragem" << endl;
        break;
    default:
        break;
    }
    return Fila;
}

autocarro cria_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES]) //Cupido e Pedro 18/05 e mai 22/05
{
    autocarro novo;
    // hexadecimal: 0123456789ABCDEF (base 16)
    novo.matricula = rand() % (65535 - 4096 + 1) + 4096;

    //Motorista
    novo.p_nome_C = pnomes[rand() % NUM_P_NOMES];
    novo.u_nome_C = unomes[rand() % NUM_U_NOMES];

    //capacidade
    novo.capacidade = rand() % 6 + 5; //de 5 a 10

    //inicialização da lista ligada de passageiros
    novo.primeiro = new Item;

    return novo;
}

Item* inserir_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES], percurso pe, Item* Fila) // mai com ajuda do cupido
{
    autocarro novo = cria_autocarro(pnomes, unomes);
    Item* temp1 = Fila;
    novo.primeiro = temp1;
    for (int i = 1; i < novo.capacidade; i++) {
        temp1 = temp1->seguinte;
    }

    Fila = temp1->seguinte;
    temp1->seguinte = NULL;

    percurso::paragem* temp = pe.inicio;
    percurso::paragem* paragem1 = pe.inicio;


    if (!autocarroExiste(paragem1->autocarro)) {
        paragem1->autocarro = novo;
    }
    else {
        while (autocarroExiste(paragem1->autocarro)) {
            temp = paragem1;
            while (temp->seguinte->seguinte != NULL && autocarroExiste(temp->seguinte->autocarro)) {
                temp = temp->seguinte;
            }
            temp->seguinte->autocarro = temp->autocarro; // trocar o na posição atual com o vazio
            temp->autocarro.matricula = 0;
        }
        pe.inicio->autocarro = novo;
    }

    return Fila; // porque atualizámos o apontador para o inicio da fila
}
