#include "percurso.h"

void criarPercurso(percurso& pe, string* listaParagens) //diogo, pedro, mai e cupido 22/5
{

    int numParagensIntermedias = rand() % 6 + 4; // de 4 a 9
    int numParagensTotal = numParagensIntermedias + 2; // de 6 a 11
    percurso::paragem* aux = new percurso::paragem;

    aux = pe.inicio;

    aux->nome = listaParagens[rand() % (NUM_PARAGENS - 9) + 9]; // nome da primeira paragem

    percurso::paragem* temp = new percurso::paragem; // passa para a próxima antes de entrar no ciclo for
    aux->seguinte = temp;
    aux = aux->seguinte;

    for (int j = 1; j <= numParagensIntermedias; j++) { // não são aleatórias (não é preciso)

        aux->nome = listaParagens[j-1];
        percurso::paragem* temp = new percurso::paragem;
        aux->seguinte = temp;
        aux = aux->seguinte;

    }

    do {
        aux->nome = listaParagens[rand() % (NUM_PARAGENS - 9) + 9]; // dá um nome à última paragem
    } while (aux->nome == pe.inicio->nome); // se for igual à primeira, repete a atribuição ^ , e verifica denovo
    aux->seguinte = NULL;

}

void imprimirPercurso(percurso& pe) // mai (incompleto, falta a parte de imprimir o autocarro e passageiros)
{
    percurso::paragem* temp = pe.inicio;

    cout << "--- Percurso ---" << endl;

    cout << temp->nome;
    do {
        temp = temp->seguinte;
        cout << " -> " << temp->nome;
    } while (temp->seguinte != NULL);

}

