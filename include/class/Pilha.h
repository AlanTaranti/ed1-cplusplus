#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h>

#include "noPilha.h"

using namespace std;

class Pilha{

    /// Atributos
    private: noPilha *topo;

    /// Metodos
    // Inicializar Fila
    public: void inicializaPilha(){
        this->topo = NULL;
    }

    // Pilha Vazia
    // Verifica se existe algum elemento na Pilha
    public: bool pilhaVazia(){
        return (this->topo == NULL);
    }

    /// Busca Lista
    // Retorna o elemento do topo da pilha
    public: noPilha *buscaTopo(){
        return this->topo;
    }

    /// Inserções
    // Insere um elemento no topo da pilha
    public: void empilha(int info){
        noPilha *novoNo;
        novoNo = new noPilha;
        if ( novoNo != NULL ){
            novoNo->info = info;
            novoNo->prox = this->topo;
            this->topo = novoNo;
        }
        else
            cout<<"Overflow";
    }


    /// Remoçao
    // Retira o elemento do topo da pilha
    public: noPilha *desempilha(){
        noPilha *aux;
        aux = this->buscaTopo();
        if ( aux == NULL )
            cout<<"Underflow";
        else{
            this->topo = this->topo->prox;
        }
        return aux;
    }

};

#endif // PILHA_H
