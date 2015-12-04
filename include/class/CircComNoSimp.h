#ifndef CIRCCOMNOSIMP_H
#define CIRCCOMNOSIMP_H

#include <stdlib.h>

#include "noCircComNoSimp.h"

using namespace std;

class CircComNoSimp{

    /// Atributos
    private: noCircComNoSimp *ultimo;

    /// Metodos
    // Inicializar Fila
    public: void inicializaLista(){
        this->ultimo = new noCircComNoSimp;
        if (this->ultimo == NULL)
            cout<<"Overflow";
        else
            this->ultimo->prox = this->ultimo;
    }

    // Lista Vazia
    // Verifica se exite alguma elemento na lista
    public: bool listaVazia(){
        return (this->ultimo->prox == this->ultimo);
    }

    /// Busca Lista
    // Procura por determinado elemento na lista
    public: noCircComNoSimp *buscaLista(int x){
        if ( this->listaVazia() ){
            return NULL;
        }
        else{
            noCircComNoSimp *aux;
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
        noCircComNoSimp *novoNo;
        novoNo = new noCircComNoSimp;
        if ( novoNo != NULL ){
            novoNo->info = info;
            novoNo->prox = this->ultimo->prox;
            this->ultimo->prox = novoNo;
        }
        else
            cout<<"Overflow";
    }

    // Insere determinado elemento no fim da lista
    public: void insereFinal(int info){
        noCircComNoSimp *novoNo;
        novoNo = new noCircComNoSimp;
        if ( novoNo != NULL ){
            novoNo->info = info;
            noCircComNoSimp *aux;
            aux = this->ultimo->prox;
            while ( aux->prox != this->ultimo )
                aux = aux->prox;
            novoNo->prox = aux->prox;
            aux->prox = novoNo;
        }
        else
            cout<<"Overflow";
    }

    // Insere determinado elemento na lista ordenadamente
    public: void insereOrdenado(int info){
        noCircComNoSimp *novoNo;
        novoNo = new noCircComNoSimp;
        if ( novoNo == NULL )
            cout<<"Overflow";
        else{
            novoNo->info = info;
            this->ultimo->info = info;
            noCircComNoSimp *aux;
            while ( aux->prox->info < info )
                aux = aux->prox;
            novoNo->prox = aux->prox;
            aux->prox = novoNo;
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
    public: noCircComNoSimp *removeLista(int info){
        if ( this->listaVazia() ){
            cout<<"Underflow";
            return NULL;
        }
        else{
            noCircComNoSimp *aux;
            aux = this->ultimo->prox;
            while (aux->info != info && aux->prox != this->ultimo )
                aux = aux->prox;
            if ( aux->info != info )
                return NULL;
            else{
                aux->prox = aux->prox->prox;
                if ( aux->prox == aux )
                    this->inicializaLista();
                return aux;
            }
        }
    }

};

#endif // CIRCCOMNOSIMP_H
