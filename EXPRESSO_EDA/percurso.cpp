#include "percurso.h"
#include <iostream>
using namespace std;

void alteraMotorista(percurso& pe)//todos
{
    string n_paragem;
    cout << " Qual o nome da paragem onde se encontra o motorista? ";
    cin.ignore();
    getline(cin, n_paragem);
    percurso::paragem* temp = pe.inicio;
    while (temp->seguinte != NULL) {
        if (autocarroExiste(temp->autocarro)) {
            if (temp->nome == n_paragem) {
                string p_nome;
                string u_nome;
                cout << "Primeiro nome: ";
                cin >> p_nome;
                cout << "Ultimo nome: ";
                cin >> u_nome;
                temp->autocarro.p_nome_C = p_nome;
                temp->autocarro.u_nome_C = u_nome;
                break;
            }
            else
                temp = temp->seguinte;
        }
        else {
            cout << "O autocarro não existe. Pressione ENTER para retornar ao menu anterior. "<<endl;
            cin.get();
            break;
        }
    }
    if (temp->seguinte == NULL) {
        cout << "Paragem não existe. Pressione ENTER para retornar ao menu anterior. ";
        cin.get();
    }
}


bilhete* novoNodo_ArvoreBilhetes(int num_bilhete) // mai
{
    bilhete* novo = new bilhete;

    novo->num = num_bilhete;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

bilhete* insereArvoreBilhetes(int num_bilhete, bilhete* raiz) // mai
{
    bilhete* aux = raiz;
    bilhete* prev = NULL;

    if (aux == NULL) {
        aux = novoNodo_ArvoreBilhetes(num_bilhete);
    }
    else
    {
        while (raiz != NULL) {
            prev = raiz;
            raiz = (raiz->num < num_bilhete ? raiz->dir : raiz->esq);
        }

        if (prev->num < num_bilhete) {
            prev->dir = novoNodo_ArvoreBilhetes(num_bilhete);
        }
        else {
            prev->esq = novoNodo_ArvoreBilhetes(num_bilhete);
        }
    }

    return aux;
}

bool procuraArvoreBilhetes(int num_bilhete, bilhete* raiz)  // mai 28/05
{
    bool existe = false;
    if (raiz == NULL) {
        return false;
    }
    if (num_bilhete == raiz->num) {
        existe = true;
    }
    else {
        if (num_bilhete > raiz->num) {
            return procuraArvoreBilhetes(num_bilhete, raiz->dir);
        }
        else {
            return procuraArvoreBilhetes(num_bilhete, raiz->esq);
        }
    }
    return existe;
}

void criarPercurso(percurso& pe, string* listaParagens) //diogo, pedro, mai e cupido 22/5
{

    int numParagensIntermedias = rand() % 6 + 4; // de 4 a 9
    pe.numParagensTotal = numParagensIntermedias + 2; // de 6 a 11
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

void imprimirPercurso(percurso& pe) // mai
{
    percurso::paragem* temp = pe.inicio;

    cout << " -= Percurso =-" << endl;

    do {

        cout << "Paragem : " << temp->nome << endl;


        cout << "Autocarro : ";
        if (autocarroExiste(temp->autocarro)) {
            cout << hex << uppercase << temp->autocarro.matricula << dec;
        }
        else {
            cout << "Ainda vazio!";
        }
        cout << " | Motorista : " << temp->autocarro.p_nome_C << " " << temp->autocarro.u_nome_C << endl;


        cout << "Passageiros ";
        if (autocarroExiste(temp->autocarro))
        {
            cout << "(" << temp->autocarro.capacidade << ")";
        }
        cout << " : ";

        if (autocarroExiste(temp->autocarro))
        {
            Item* aux = temp->autocarro.primeiro;
            while (aux != NULL) {
                cout << aux->pessoa.u_nome << " " << aux->pessoa.numero_bilhete;
                if (aux->seguinte != NULL)
                    cout << ", ";
                aux = aux->seguinte;
            }
        }

        cout << endl << endl;
        temp = temp->seguinte;

    } while (temp != NULL);

}

bool autocarroExiste(autocarro ac) { // mai
    return (ac.matricula != 0);
}
