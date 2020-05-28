#include "percurso.h"
#include <iostream>
using namespace std;

void alteraMotorista(percurso& pe)//todos
{
    int index_paragem;
    cout << " Qual o numero da paragem onde se encontra o motorista? ";
    cin >> index_paragem;
    percurso::paragem* temp = pe.inicio;
    while (temp->seguinte != NULL) {
        if (autocarroExiste(temp->autocarro)) {
            if (temp->index == index_paragem) {
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


bilhete* novoNodoArvoreBilhetes(int num_bilhete) // mai
{
    bilhete* novo = new bilhete;

    novo->num = num_bilhete;
    novo->esq = NULL;
    novo->dir = NULL;

    //cout << "new: " << num_bilhete << " -> " << novo << endl;

    return novo;
}

bilhete* insereArvoreBilhetes(int num_bilhete, bilhete* raiz) // mai
{
    //cout << " " << num_bilhete << " " << raiz << endl;
    if (raiz == NULL) {
        //cout << "   " << num_bilhete  << " " << raiz << endl;
        return novoNodoArvoreBilhetes(num_bilhete);
    }
    else if (num_bilhete > raiz->num) {
        //cout << " went right" << endl;
        raiz->dir = insereArvoreBilhetes(num_bilhete, raiz->dir);
    }
    else {
        //cout << " went left" << endl;
        raiz->esq = insereArvoreBilhetes(num_bilhete, raiz->esq);
    }
    return raiz;
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

bilhete* removerArvoreBilhetes(bilhete* raiz, int num) {
    bilhete* no = raiz;
    bilhete* prev = NULL;
    while (no != NULL) {
        if (num == no->num) {
            return removerArvoreBilhetes(raiz, no, prev);
        }
        else if (num < no->num) {
            prev = no;
            no = no->esq;
        }
        else {
            prev = no;
            no = no->dir;
        }

    }
    return raiz;
}

bilhete* removerArvoreBilhetes(bilhete* root, bilhete* no, bilhete* prev) {
    //removing the root
    if (prev == NULL) {
        if (no->esq == NULL && no->dir == NULL)
            root = NULL;
        else if (no->esq != NULL && no->dir == NULL)
            root = no->esq;
        else if (no->esq == NULL && no->dir != NULL)
            root = no->dir;
        else {
            //copy step
            bilhete* temp = no->esq;
            prev = root;
            while (temp->dir != NULL) {
                prev = temp;
                temp = temp->dir;
            }
            swap(temp->num, root->num);
            if (prev->num >= root->num || prev == root)
                prev->esq = temp->esq;
            else
                prev->dir = temp->esq;

            no = temp;
        }
    }
    else { // any other bilhete
        if (no->esq == NULL && no->dir == NULL) {
            if (prev->num > no->num)
                prev->esq = NULL;
            else
                prev->dir = NULL;
        }
        else if (no->esq == NULL && no->dir != NULL) {
            if (prev->num > no->num)
                prev->esq = no->dir;
            else
                prev->dir = no->dir;
        }
        else if (no->esq != NULL && no->dir == NULL) {
            if (prev->num > no->num)
                prev->esq = no->esq;
            else
                prev->esq = no->esq;
        }
        else { // copy step
            bilhete* temp = no->esq;
            prev = no;
            while (temp->dir != NULL) {
                prev = temp;
                temp = temp->dir;
            }
            swap(temp->num, no->num);
            if (prev->num > no->num || prev == no)
                prev->esq = temp->esq;
            else
                prev->dir = temp->esq;

            no = temp;
        }
    }
    delete no;
    return root;
}

void imprimeArvoreBilhetes(bilhete* raiz, int n) // mai
{
    if (raiz == NULL) {
        cout << endl;
        return;
    }
    imprimeArvoreBilhetes(raiz->dir, n + 1);

    for (int i = 0; i < n; i++) {
        cout << ".   ";
    }
    cout << raiz->num << endl;

    imprimeArvoreBilhetes(raiz->esq, n + 1);
}

void imprimeArvoreBilhetesInfixa(bilhete* raiz) // mai
{
    if (raiz == NULL) {
        return;
    }
    imprimeArvoreBilhetesInfixa(raiz->esq);
    cout << raiz->num << "; ";
    imprimeArvoreBilhetesInfixa(raiz->dir);
}

void criarPercurso(percurso& pe, string* listaParagens) //diogo, pedro, mai e cupido 22/5
{

    int numParagensIntermedias = rand() % 6 + 4; // de 4 a 9
    pe.numParagensTotal = numParagensIntermedias + 2; // de 6 a 11
    percurso::paragem* aux = new percurso::paragem;

    aux = pe.inicio;
    int i = 1; // será o index da paragem, utilizado quando o utilizador precisa de escolher uma paragem

    //criação das paragens propriamente ditas

    aux->nome = listaParagens[rand() % (NUM_PARAGENS - 9) + 9]; // nome da primeira paragem
    aux->index = i;

    percurso::paragem* temp = new percurso::paragem; // passa para a próxima antes de entrar no ciclo for
    aux->seguinte = temp;
    aux = aux->seguinte;

    for (int j = 1; j <= numParagensIntermedias; j++) { // não são aleatórias (não é preciso)

        aux->nome = listaParagens[j-1];
        i++;
        aux->index = i;
        percurso::paragem* temp = new percurso::paragem;
        aux->seguinte = temp;
        aux = aux->seguinte;

    }

    do {
        aux->nome = listaParagens[rand() % (NUM_PARAGENS - 9) + 9]; // dá um nome à última paragem
    } while (aux->nome == pe.inicio->nome); // se for igual à primeira, repete a atribuição ^ , e verifica denovo

    aux->seguinte = NULL;

    i++;
    aux->index = i;

}

void imprimirPercurso(percurso& pe) // mai
{
    percurso::paragem* temp = pe.inicio;

    cout << " -= Percurso =-" << endl;

    do {

        cout << "Paragem #" << temp->index << ": " << temp->nome << endl;


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


void RemoverPessoaAutocarro(percurso::paragem* inicio) { //cupido e mai
    int bilhete;
    bool removido = false;
    cout << "Insere o numero de bilhete para remover passageiro nos autocarros: ";
    cin >> bilhete;
    percurso::paragem* temp = inicio;
    if (!autocarroExiste(temp->autocarro)) {
        cout << "Nao existem autocarros!";
    }
    while ((temp != NULL) && (!removido) && autocarroExiste(temp->autocarro)) {
        Item* aux = temp->autocarro.primeiro;
        if (aux->pessoa.numero_bilhete == bilhete) {
            //cout << "foi ao inicio" << endl;
            temp->autocarro.primeiro = removerInicio(temp->autocarro.primeiro);
            temp->autocarro.capacidade -= 1;
            removido = true;
            break;
        }
        for (int i = 0; i < temp->autocarro.capacidade; i++) {
            if (aux->seguinte == NULL && aux->pessoa.numero_bilhete == bilhete) {
                //cout << "foi ao fim" << endl;
                temp->autocarro.primeiro = removerFim(temp->autocarro.primeiro);
                temp->autocarro.capacidade -= 1;
                removido = true;
                break;
            }
            else if (aux->seguinte != NULL && aux->pessoa.numero_bilhete == bilhete) {
                //cout << "foi ao meio" << endl;
                temp->autocarro.primeiro = removerMeio(temp->autocarro.primeiro, bilhete);
                temp->autocarro.capacidade -= 1;
                removido = true;
                break;
            }
            aux = aux->seguinte;
        }
        temp = temp->seguinte;
    }
    if (removido) {
        cout << "Removido com Sucesso!" << endl;
    }
    else {
        cout << "Nao encontrado!" << endl;
    }
}

bool autocarroExiste(autocarro ac) { // mai
    return (ac.matricula != 0);
}
