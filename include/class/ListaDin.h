#ifndef LISTADIN_H
#define LISTADIN_H

#include <stdlib.h>

#include "noListaDin.h"

using namespace std;

class ListaDin{

    /// Atributos
    private: noListaDin *primeiro;
    private: noListaDin *ultimo;

    /// Metodos
    // Inicializar Fila
    public: void inicializaLista(){
        this->primeiro = NULL;
        this->ultimo = NULL;
    }

    // Lista Vazia
    // Verifica se exite alguma elemento na lista
    public: bool listaVazia(){
        return (this->primeiro == NULL);
    }

    /// Busca Lista
    // Procura por determinado elemento na lista
    public: noListaDin *buscaLista(int info){
        noListaDin *aux;
        aux = this->primeiro;
        while ( aux != NULL && aux->info != info )
            aux = aux->prox;
        return aux;
    }

    /// Inserções

    // Insere determinado elemento no começo da lista
    public: void insereInicio(int info){
        noListaDin *novoNo;
        novoNo = new noListaDin;
        if ( novoNo != NULL ){
            novoNo->info = info;
            novoNo->prox = this->primeiro;
            if ( this->listaVazia() )
                this->ultimo = novoNo;
            this->primeiro = novoNo;
        }
        else
            cout<<"Overflow";
    }

    // Insere determinado elemento no fim da lista
    public: void insereFinal(int info){
        noListaDin *novoNo;
        novoNo = new noListaDin;
        if ( novoNo != NULL ){
            novoNo->info = info;
            novoNo->prox = NULL;
            this->ultimo->prox = novoNo;
            this->ultimo = novoNo;
            if ( this->listaVazia() )
                this->primeiro = this->ultimo;
        }
        else
            cout<<"Overflow";
    }

    // Insere determinado elemento na lista ordenadamente
    public: void insereOrdenado(int info){
        if ( this->listaVazia() || info <= this->primeiro->info )
            this->insereInicio(info);
        else if ( info >= this->ultimo->info )
            this->insereFinal(info);
        else{
            noListaDin *novoNo;
            novoNo = new noListaDin;
            if ( novoNo != NULL ){
                novoNo->info = info;
                noListaDin *atual;
                atual = this->primeiro;
                while ( atual->prox->info < info )
                    atual = atual->prox;
                novoNo->prox = atual->prox;
                atual->prox = novoNo;
            }
            else
                cout<<"Overflow";
        }
    }

    // Insere determinado elemento sem repetir outro já existente
    public: void insereSemRepeticao(int info){
        if ( this->buscaLista(info) == NULL)
            this->insereInicio(info);
        else
            cout<<"Elemento jah existe na Lista!";
    }

    /// Remoçao
    // Remove o elemento que contem o valor informado
    public: noListaDin *removeLista(int info){
        noListaDin *aux;
        aux = this->buscaLista(info);
        if ( aux == NULL )
            cout<<"Elemento nao esta na Lista!";
        else if ( this->primeiro == this->ultimo )
            this->inicializaLista();
        else if ( info == this->primeiro->info )
            this->primeiro = this->primeiro->prox;
        else{
            noListaDin *atual;
            atual = this->primeiro;
            while ( atual->prox->info != info )
                atual = atual->prox;
            if ( atual->prox == NULL ){
                this->ultimo = atual;
                atual->prox = NULL;
            }
            else
                atual->prox = aux->prox;
        }
        return aux;
    }

};

#endif // LISTADIN_H
