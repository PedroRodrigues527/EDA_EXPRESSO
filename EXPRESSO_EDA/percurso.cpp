#include "percurso.h"
#include <iostream>
using namespace std;

void alteraMotorista(percurso& pe)//todos
{
    int index_paragem;
    cout << " Qual o número da paragem onde se encontra o motorista? ";
    cin >> index_paragem;

    percurso::paragem* temp = pe.inicio;

    while (temp != NULL) {
        if (autocarroExiste(temp->autocarro)) {
            if (temp->index == index_paragem) {
                string p_nome;
                string u_nome;
                cout << "Insira o novo primeiro nome: ";
                cin >> p_nome;
                cout << "Insira o novo último nome: ";
                cin >> u_nome;
                temp->autocarro.p_nome_C = p_nome;
                temp->autocarro.u_nome_C = u_nome;
                break;
            }
            else
                temp = temp->seguinte;
        }
        else {
            cout << "O autocarro não existe." << endl;
            break;
        }
    }

    if (temp == NULL) {
        cout << "A paragem não existe." << endl;
    }
    cout << "Pressione ENTER para retornar ao menu principal. ";
    cin.get();
    cin.ignore();
}


bilhete* novoNodoArvoreBilhetes(int num_bilhete) // mai
{
    bilhete* novo = new bilhete;
    novo->num = num_bilhete;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}



bilhete* insereArvoreBilhetes(int num_bilhete, bilhete* raiz) // mai
{
    if (raiz == NULL) {
        return novoNodoArvoreBilhetes(num_bilhete);
    }
    else if (num_bilhete > raiz->num) {
        raiz->dir = insereArvoreBilhetes(num_bilhete, raiz->dir);
    }
    else {
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

bilhete* removerArvoreBilhetes(bilhete* raiz, int num) { // remoção por cópia, procura
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

bilhete* removerArvoreBilhetes(bilhete* root, bilhete* no, bilhete* prev) { // remoção por cópia, remoção propriamente dita

    // remover a raiz

    if (prev == NULL) {
        if (no->esq == NULL && no->dir == NULL)
            root = NULL;
        else if (no->esq != NULL && no->dir == NULL)
            root = no->esq;
        else if (no->esq == NULL && no->dir != NULL)
            root = no->dir;
        else {
            // cópia
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
    // remover outros bilhetes
    else { 
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
        else { // cópia
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

void imprimeArvoreBilhetes(bilhete* raiz) {
    imprimeArvoreBilhetesAux(raiz, 0, false); // para simplificar as chamadas da funçao imprime
}

void imprimeArvoreBilhetesAux(bilhete* raiz, int n, bool esquerda) // mai
{
    if (raiz == NULL) {
        cout << endl;
        return;
    }
    imprimeArvoreBilhetesAux(raiz->dir, n + 1, false);

    for (int i = 0; i < n; i++) {
        cout << ".     ";
    }

    cout << " " << raiz->num;

    // extra, facilita interpretação dos ramos e folhas da árvore, e fica mais bonito :)
    if ((raiz->esq != NULL) && (raiz->dir != NULL))
        cout << " <";
    else {
        if (raiz->esq != NULL)
            cout << " v";
        if (raiz->dir != NULL)
            cout << " ^";
    }
    cout << endl;


    imprimeArvoreBilhetesAux(raiz->esq, n + 1, true);
}

void imprimeArvoreBilhetesInfixa(bilhete* raiz) // mai
{
    if (raiz == NULL) {
        return;
    }
    imprimeArvoreBilhetesInfixa(raiz->esq);
    printItem(to_string(raiz->num) + ";", 6);
    imprimeArvoreBilhetesInfixa(raiz->dir);
}

void apresentarBilhetes(percurso& pe) // mai
{
   
    int index_paragem;
    cout << " Qual o número da paragem cujos bilhetes deseja vizualizar? " << endl;
    cin >> index_paragem;


    bilhete* arvore = NULL;
    percurso::paragem* temp = pe.inicio;
    
    while (temp != NULL) {
        if (temp->index == index_paragem) {
            arvore = temp->arvore_bilhetes;
            break;
        }
        else
            temp = temp->seguinte;
    }

    if (arvore == NULL) {
        cout << "Não existe árvore nessa paragem, ou ela está vazia. " << endl;
    }
    else {
        int escolha;
        cout << " \t 1. Imprimir por Ordem Numérica\n \t 2. Imprimir sob a forma de Árvore" << endl;
        cin >> escolha;

        switch (escolha) {
        case 1:
            cout << " -- Travessia Infixa -- " << endl;
            imprimeArvoreBilhetesInfixa(arvore);
            break;
        case 2:
            cout << " -- Árvore de Pesquisa Binária -- " << endl;
            imprimeArvoreBilhetes(arvore);
            break;
        default:
            cout << "Regressando ao menu principal..." << endl;
            break;
        }
    }
    cout << endl << "Pressione ENTER para continuar.";
    cin.get();
    cin.ignore();
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
    cout << "Insira o número de bilhete do passageiro que deseja ser removido do autocarro: ";
    cin >> bilhete;

    percurso::paragem* temp = inicio;
    Item* aux = NULL;
    Pessoa pessoa_removida;

    if (!autocarroExiste(temp->autocarro)) {
        cout << "Não existem autocarros! " << endl;
    }
    else {

        while ((temp != NULL) && (!removido) && autocarroExiste(temp->autocarro)) {

            aux = temp->autocarro.primeiro;

            //cout << "teste: " << temp->index << endl;

            if (aux != NULL) {
                if (aux->pessoa.numero_bilhete == bilhete) {

                    //cout << "foi ao inicio" << endl;
                    pessoa_removida = aux->pessoa;
                    inserirBilhetePassageiro(bilhete, temp);
                    temp->autocarro.primeiro = removerInicio(temp->autocarro.primeiro);
                    temp->autocarro.capacidade -= 1;

                    removido = true;
                    break;
                }

                for (int i = 0; i < temp->autocarro.capacidade; i++) {
                    if (aux->seguinte == NULL && aux->pessoa.numero_bilhete == bilhete) {

                        //cout << "foi ao fim" << endl;
                        pessoa_removida = aux->pessoa;
                        inserirBilhetePassageiro(bilhete, temp);
                        temp->autocarro.primeiro = removerFim(temp->autocarro.primeiro);
                        temp->autocarro.capacidade -= 1;

                        removido = true;
                        break;
                    }
                    else if (aux->seguinte != NULL && aux->pessoa.numero_bilhete == bilhete) {

                        //cout << "foi ao meio" << endl;
                        pessoa_removida = aux->pessoa;
                        inserirBilhetePassageiro(bilhete, temp);
                        temp->autocarro.primeiro = removerMeio(temp->autocarro.primeiro, bilhete);
                        temp->autocarro.capacidade -= 1;

                        removido = true;
                        break;
                    }
                    aux = aux->seguinte;
                }
            }
            temp = temp->seguinte;
        }


        if (removido) {
            cout << "Passageiro " << pessoa_removida.p_nome << " " << pessoa_removida.u_nome  << "(" << pessoa_removida.numero_bilhete << ")" << " foi removido com sucesso! " << endl;
        }
        else {
            cout << "Passageiro não encontrado! " << endl;
        }
    }

    cout << "Pressione ENTER para continuar.";
    cin.get();
    cin.ignore();
}

bool autocarroExiste(autocarro ac) { // mai
    return (ac.matricula != 0);
}

void inserirBilhetePassageiro(int bilhete, percurso::paragem* pa)
{
    pa->arvore_bilhetes = insereArvoreBilhetes(bilhete, pa->arvore_bilhetes);
}

void RemoverBilheteParagem(percurso& pe) { // todos
    int paragem;
    int numbilhete;
    cout << "Qual é o número da paragem? " << endl;
    cin >> paragem;
    
    percurso::paragem* temp = pe.inicio;

    bool existearvore = false;

    while (temp != NULL) {
        if (autocarroExiste(temp->autocarro)) {
            if (temp->index == paragem && temp->arvore_bilhetes != NULL) {
                existearvore = true;
                break;
            }
        }
        temp = temp->seguinte;
    }

    if (existearvore) 
    {
        cout << "--- Bilhetes da paragem #" << paragem << " ---" << endl;
        imprimeArvoreBilhetes(temp->arvore_bilhetes);

        cout << "Qual o número de bilhete que quer remover? " << endl;
        cin >> numbilhete;
        temp->arvore_bilhetes = removerArvoreBilhetes(temp->arvore_bilhetes, numbilhete);

        cout << "--- Após remoção: ---" << endl;
        imprimeArvoreBilhetes(temp->arvore_bilhetes);
    }
    else {
        cout << "Não existe árvore de bilhetes na paragem #" << paragem << "." << endl;
    }

    cout << "Pressione ENTER para continuar.";
    cin.get();
    cin.ignore();
}

Item* RemoverPessoaFiladeEspera(Item* Fila) { //cupido
    int bilhete;
    cout << "Insere o número de bilhete para remover a pessoa em fila de espera: ";
    cin >> bilhete;
    Item* temp = Fila;
    if (Fila == NULL) {
        cout << "Fila de espera vazia! " << endl;
        return NULL;
    }
    else if (temp->pessoa.numero_bilhete == bilhete) {
        cout << "Pessoa " << temp->pessoa.p_nome << " " << temp->pessoa.u_nome << "(" << temp->pessoa.numero_bilhete << ")" << " foi removido com sucesso! " << endl;
        return removerInicio(Fila);
    }
    else {
        do {
            temp = temp->seguinte;
            if (temp->seguinte == NULL && temp->pessoa.numero_bilhete == bilhete) {
                //cout << "testes1" << endl;
                cout << "Pessoa " << temp->pessoa.p_nome << " " << temp->pessoa.u_nome << "(" << temp->pessoa.numero_bilhete << ")" << " foi removido com sucesso! " << endl;
                return removerFim(Fila);
            }
            else if (temp->pessoa.numero_bilhete == bilhete) {
                //cout << "testes2" << endl;
                //cout << temp->seguinte->pessoa.numero_bilhete << " " << temp->seguinte->pessoa.p_nome << " " << temp->seguinte->pessoa.u_nome << endl;
                cout << "Pessoa " << temp->pessoa.p_nome << " " << temp->pessoa.u_nome << "(" << temp->pessoa.numero_bilhete << ")" << " foi removido com sucesso! " << endl;
                return removerMeio(Fila, bilhete);
            }
        } while (temp->seguinte != NULL);
        if (temp->seguinte == NULL && temp->pessoa.numero_bilhete != bilhete) {
            cout << "Número de bilhete não encontrado! " << endl;
            return Fila;
        }
    }
}

void TextoMenu() {
    cout << endl << "---------------" << endl;
    cout << " Pressione 'o' para poder ver as opções disponiveis." << endl;
    cout << " Pressione 's' para seguir para a próxima iteração." << endl;
    cout << " Prima qualquer outra tecla para fechar o programa e terminar a execução." << endl;
}