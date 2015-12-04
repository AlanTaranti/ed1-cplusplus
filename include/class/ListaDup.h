#ifndef LISTADUP_H
#define LISTADUP_H

#include <stdlib.h>

#include "noListaDup.h"

using namespace std;

class ListaDup {

    /// Atributos
    private: noListaDup *primeiro;
    private: noListaDup *ultimo;

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
    public: noListaDup *buscaLista(int info){
        noListaDup *aux;
        aux = this->primeiro;
        while ( aux != NULL && aux->info != info )
            aux = aux->prox;
        return aux;
    }

    /// Inserções

    // Insere determinado elemento no começo da lista
    public: void insereInicio(int info){
        noListaDup *novoNo;
        novoNo = new noListaDup;
        if ( novoNo != NULL ){
            novoNo->info = info;
            if ( this->listaVazia() ){
                this->ultimo = novoNo;
                novoNo->prox = NULL;
            }
            else{
                novoNo->prox = this->primeiro;
                this->primeiro->ant = novoNo;
            }
            this->primeiro = novoNo;
            novoNo->ant = NULL;
        }
        else
            cout<<"Overflow";
    }

    // Insere determinado elemento no fim da lista
    public: void insereFinal(int info){
        noListaDup *novoNo;
        novoNo = new noListaDup;
        if ( novoNo != NULL ){
            novoNo->info = info;
            if ( this->listaVazia() ){
                this->primeiro = novoNo;
                novoNo->ant = NULL;
            }
            else{
                this->ultimo->prox = novoNo;
                novoNo->ant = this->ultimo;
            }
            this->ultimo = novoNo;
            novoNo->prox = NULL;
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
            noListaDup *novoNo;
            novoNo = new noListaDup;
            if ( novoNo != NULL ){
                novoNo->info = info;
                noListaDup *aux;
                aux = this->primeiro->prox;
                while ( aux->info < info )
                    aux = aux->prox;
                novoNo->prox = aux;
                novoNo->ant = aux->ant;
                aux->ant->prox = novoNo;
                aux->ant = novoNo;
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
    public: noListaDup *removeLista(int info){
        noListaDup *no;
        no = NULL;
        if ( this->listaVazia() )
            cout<<"Underflow";
        else{
            no = this->buscaLista(info);
            if ( no == NULL ){
                cout<<"Elemento nao existe!";
            }
            else if ( this->primeiro == this->ultimo ){
                this->inicializaLista();
            }
            else if ( this->primeiro == no ){
                this->primeiro = no->prox;
                this->primeiro->ant = NULL;
            }
            else if ( this->ultimo == no ){
                this->ultimo = no->ant;
                this->ultimo->prox = NULL;
            }
            else{
                no->ant->prox = no->prox;
                no->prox->ant = no->ant;
            }
        }
        return no;
    }

};

#endif // LISTADUP_H
