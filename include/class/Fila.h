#ifndef FILA_H
#define FILA_H

#include <stdlib.h>

#include "noFila.h"

using namespace std;

class Fila{

    /// Atributos
    private: noFila *primeiro;
    private: noFila *ultimo;

    /// Metodos
    // Inicializar Fila
    public: void inicializaFila(){
        this->primeiro = NULL;
        this->ultimo = NULL;
    }

    // Fila Vazia
    // Verifica se existe algum elemento na Fila
    public: bool filaVazia(){
        return (this->primeiro == NULL);
    }

    /// Busca Primeiro
    // Retorna o primeiro elemento da fila
    public: noFila *buscaPrimeiro(){
        return this->primeiro;
    }

    /// Inserções
    // Insere um elemento no final da fila
    public: void insere(int info){
        noFila *novoNo;
        novoNo = new noFila;
        if ( novoNo != NULL ){
            novoNo->info = info;
            novoNo->prox = NULL;
            if ( this->filaVazia() )
                this->primeiro = novoNo;
            else
                this->ultimo->prox = novoNo;
            this->ultimo = novoNo;
        }
        else
            cout<<"Overflow";
    }


    /// Remoçao
    // Remove o primeiro elemento da fila
    public: noFila *removeFila(){
        noFila *aux;
        aux = this->buscaPrimeiro();
        if ( aux == NULL )
            cout<<"Underflow";
        else{
            this->primeiro = this->primeiro->prox;
        }
        return aux;
    }

};

#endif // FILA_H
