#ifndef CIRCCOMNODUP_H
#define CIRCCOMNODUP_H

#include <stdlib.h>

#include "noCircComNoDup.h"

using namespace std;

class CircComNoDup{

    /// Atributos
    private: noCircComNoDup *ultimo;

    /// Metodos
    // Inicializar Fila
    public: void inicializaLista(){
        this->ultimo = new noCircComNoDup;
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
    public: noCircComNoDup *buscaLista(int x){
        if ( this->listaVazia() ){
            return NULL;
        }
        else{
            noCircComNoDup *aux;
            aux = this->ultimo->prox;
            this->ultimo->info = x;
            while (aux->info != x)
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
        noCircComNoDup *novoNo;
        novoNo = new noCircComNoDup;
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
        noCircComNoDup *novoNo;
        novoNo = new noCircComNoDup;
        if ( novoNo != NULL ){
            novoNo->info = info;
            novoNo->ant = this->ultimo->ant;
            novoNo->prox = this->ultimo;
            this->ultimo->ant->prox;
        }
        else
            cout<<"Overflow";
    }

    // Insere determinado elemento na lista ordenadamente
    public: void insereOrdenado(int info){
        noCircComNoDup *novoNo;
        novoNo = new noCircComNoDup;
        if ( novoNo == NULL )
            cout<<"Overflow";
        else{
            novoNo->info = info;
            this->ultimo->info = info;
            noCircComNoDup *aux;
            while ( aux->prox->info < info )
                aux = aux->prox;
            novoNo->ant = aux;
            novoNo->prox = aux->prox;
            aux->prox = novoNo;
            novoNo->prox->ant = novoNo;
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
    public: noCircComNoDup *removeLista(int info){
        noCircComNoDup *aux;
        aux = this->buscaLista(info);
        if ( aux == NULL ){
            cout<<"Elemento não encontrado";
            return NULL;
        }
        else{
            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
            if ( this->ultimo == aux )
                this->ultimo = aux->ant;
        }
    }

};

#endif // CIRCCOMNODUP_H
