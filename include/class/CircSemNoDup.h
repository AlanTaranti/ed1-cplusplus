#ifndef CIRCSEMNODUP_H
#define CIRCSEMNODUP_H

#include <stdlib.h>

#include "noCircSemNoDup.h"

using namespace std;

class CircSemNoDup{

    /// Atributos
    private: noCircSemNoDup *ultimo;

    /// Metodos
    // Inicializar Fila
    public: void inicializaLista(){
        this->ultimo = new noCircSemNoDup;
        if (this->ultimo == NULL)
            cout<<"Overflow";
        else{
            this->ultimo->prox = this->ultimo;
            this->ultimo->ant = this->ultimo;
        }
    }

    // Lista Vazia
    // Verifica se exite alguma elemento na lista
    public: bool listaVazia(){
        return (this->ultimo->prox == this->ultimo);
    }

    /// Busca Lista
    // Procura por determinado elemento na lista
    public: noCircSemNoDup *buscaLista(int info){
        if ( this->listaVazia() ){
            return NULL;
        }
        else{
            noCircSemNoDup *aux;
            aux = this->ultimo->prox;
            this->ultimo->info = info;
            while (aux->info != info)
                aux = aux->prox;
            if ( aux != this->ultimo )
                return aux;
            else
                return NULL;
        }
    }

    /// Inserções

    // Insere determinado elemento no começo da lista
    public: void insereInicio(int info){
        noCircSemNoDup *novoNo;
        novoNo = new noCircSemNoDup;
        if ( novoNo != NULL ){
            novoNo->info = info;
            novoNo->prox = this->ultimo->prox;
            novoNo->ant = this->ultimo;
            this->ultimo->prox->ant = novoNo;
            this->ultimo->prox = novoNo;
        }
        else
            cout<<"Overflow";
    }

    // Insere determinado elemento no fim da lista
    public: void insereFinal(int info){
        noCircSemNoDup *novoNo;
        novoNo = new noCircSemNoDup;
        if ( novoNo != NULL ){
            novoNo->info = info;
            novoNo->prox = this->ultimo->prox;
            novoNo->ant = this->ultimo;
            this->ultimo->prox->ant = novoNo;
            this->ultimo->prox = novoNo;
            this->ultimo = novoNo;
        }
        else
            cout<<"Overflow";
    }

    // Insere determinado elemento na lista ordenadamente
    public: void insereOrdenado(int info){
        if ( this->listaVazia() || info <= this->ultimo->prox->info )
            this->insereInicio(info);
        else if ( info >= this->ultimo->info )
            this->insereFinal(info);
        else{
            noCircSemNoDup *novoNo;
            novoNo = new noCircSemNoDup;
            if ( novoNo != NULL ){
                novoNo->info = info;
                noCircSemNoDup *aux;
                aux = this->ultimo->prox;
                while ( aux->prox->info < info )
                    aux = aux->prox;
                novoNo->ant = aux;
                novoNo->prox = aux->prox;
                aux->prox = novoNo;
                novoNo->prox->ant = novoNo;
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
    public: noCircSemNoDup *removeLista(int info){
        noCircSemNoDup *aux;
        aux = this->buscaLista(info);
        if ( aux == NULL )
            cout<<"Elemento nao esta na Lista!";
        else if ( aux->prox == aux )
            this->inicializaLista();
        else{
            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
            if (this->ultimo == aux )
                this->ultimo = aux->ant;
        }
        return aux;
    }

};

#endif // CIRCSEMNODUP_H
