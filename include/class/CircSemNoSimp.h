#ifndef CIRCSEMNOSIMP_H
#define CIRCSEMNOSIMP_H

#include <stdlib.h>

#include "noCircSemNoSimp.h"

using namespace std;

class CircSemNoSimp{

    /// Atributos
    private: noCircSemNoSimp *ultimo;

    /// Metodos
    // Inicializar Fila
    public: void inicializaLista(){
        this->ultimo = NULL;
    }

    // Lista Vazia
    // Verifica se exite alguma elemento na lista
    public: bool listaVazia(){
        return (this->ultimo == NULL);
    }

    /// Busca Lista
    // Procura por determinado elemento na lista
    public: noCircSemNoSimp *buscaLista(int x){
        if ( this->listaVazia() ){
            return NULL;
        }
        else{
            noCircSemNoSimp *aux;
            aux = this->ultimo->prox;
            while (aux->info != x && aux != this->ultimo )
                aux = aux->prox;
            if ( aux->info == x )
                return aux;
            else
                return NULL;
        }
    }

    /// Inserções

    // Insere determinado elemento no começo da lista
    public: void insereInicio(int info){
        noCircSemNoSimp *novoNo;
        novoNo = new noCircSemNoSimp;
        if ( novoNo != NULL ){
            novoNo->info = info;
            if ( this->listaVazia() ){
                novoNo->prox = novoNo;
                this->ultimo = novoNo;
            }
            else{
                novoNo->prox = this->ultimo->prox;
                this->ultimo->prox = novoNo;
            }
        }
        else
            cout<<"Overflow";
    }

    // Insere determinado elemento no fim da lista
    public: void insereFinal(int info){
        noCircSemNoSimp *novoNo;
        novoNo = new noCircSemNoSimp;
        if ( novoNo != NULL ){
            novoNo->info = info;
            if ( this->listaVazia() ){
                novoNo->prox = novoNo;
                this->ultimo = novoNo;
            }
            else{
                novoNo->prox = this->ultimo->prox;
                this->ultimo->prox = novoNo;
                this->ultimo = novoNo;
            }
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
            noCircSemNoSimp *novoNo;
            novoNo = new noCircSemNoSimp;
            if ( novoNo != NULL ){
                novoNo->info = info;
                noCircSemNoSimp *aux;
                aux = this->ultimo->prox;
                while ( aux->prox->info < info )
                    aux = aux->prox;
                novoNo->prox = aux->prox;
                aux->prox = novoNo;
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
    public: noCircSemNoSimp *removeLista(int info){
        if ( this->listaVazia() ){
            cout<<"Underflow";
            return NULL;
        }
        else{
            noCircSemNoSimp *aux;
            aux = this->ultimo;
            while (aux->prox->info != info && aux != this->ultimo )
                aux = aux->prox;
            if ( aux->info != info )
                return NULL;
            else{
                noCircSemNoSimp *aux2;
                aux2 = aux->prox;
                aux->prox = aux->prox->prox;
                if ( aux2 == this->ultimo )
                    this->ultimo = aux;
                if( aux->prox = aux )
                    this->inicializaLista();
                return aux2;

            }
        }
    }

};

#endif // CIRCSEMNOSIMP_H
