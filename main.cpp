#include <iostream>

/// Classes
#include "include/class/ListaDin.h"
#include "include/class/ListaDup.h"
#include "include/class/CircSemNoSimp.h"
#include "include/class/CircComNoSimp.h"
#include "include/class/CircComNoDup.h"
#include "include/class/CircSemNoDup.h"
#include "include/class/Pilha.h"
#include "include/class/Fila.h"

// Controles Gerais
#include "include/class/ControleTela.h"
#include "include/class/Menu.h"
#include "include/class/Creditos.h"

using namespace std;

/// Declaração de Funções
// Menus
Menu menuMain();
Menu menuListaEnc(int); // 0 - Simplesmente Encadeada --- 1 - Duplamente Encadeada
Menu menuLista();
Menu menuFila();
Menu menuPilha();
Menu menuListaCircular();
Menu menuListaCircularEnc(int);

void opListaSimp();
void opListaDup();
void opLista();
void opListaCircular();
void opListaCircularSimpSemNO();
void opListaCircularDupSemNO();
void opListaCircularSimpComNO();
void opListaCircularDupComNO();
void opFila();
void opPilha();

void definicaoEstruturas();
void estruturas();

/// Variageis Globais das Estruturas
ListaDin listaDin;
ListaDup listaDup;
CircSemNoSimp lcsesd;
CircComNoSimp lcsecd;
CircComNoDup lcdecd;
CircSemNoDup lcdesd;
Fila f;
Pilha p;


int main(){
    // Menu Principal
    Menu menu = menuMain();
    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:
            definicaoEstruturas();
            break;
        case 2:
            estruturas();
            break;
        case 3:
            Creditos::showCreditos();
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}

/// Define o menus
Menu menuMain(){
    Menu menu;
    menu.inicializaMenu(2);
    menu.setTitulo("Testa Estruturas");
    menu.setEntrada(1,"Definicao do Problema");
    menu.setEntrada(2,"Execucao");
    menu.setLargura(60);
    menu.setDelimitadorBorda('+');
    menu.setMostrarCreditos(true);
    return menu;
}
// 0 - Simplesmente Encadeada --- 1 - Duplamente Encadeada
Menu menuListaEnc(int i){
    Menu menu;
    menu.inicializaMenu(6);
    if ( i == 0 )
        menu.setTitulo("Menu Lista Simplesmente Encadeada");
    else if ( i == 1 )
        menu.setTitulo("Menu Lista Duplamente Encadeada");
    menu.setEntrada(1,"Inicializar Lista");
    menu.setEntrada(2,"Inserir no Inicio da Lista");
    menu.setEntrada(3,"Inserir no Fim da Lista");
    menu.setEntrada(4,"Inserir em Lista Ordenada");
    menu.setEntrada(5,"Inserir sem Repeticao em Lista");
    menu.setEntrada(6,"Remover da Lista");
    menu.setLargura(60);
    menu.setDelimitadorBorda('-');
    menu.trocarSairPorVoltar();
    return menu;
}
Menu menuEstruturas(){
    Menu menu;
    menu.inicializaMenu(4);
    menu.setTitulo("Menu Alocacao Dinamica");
    menu.setEntrada(1,"Lista");
    menu.setEntrada(2,"Lista Circular");
    menu.setEntrada(3,"Fila");
    menu.setEntrada(4,"Pilha");
    menu.setLargura(60);
    menu.setDelimitadorBorda('-');
    menu.trocarSairPorVoltar();
    return menu;
}
Menu menuLista(){
    Menu menu;
    menu.inicializaMenu(2);
    menu.setTitulo("Menu Lista");
    menu.setEntrada(1,"Simplesmente Encadeada");
    menu.setEntrada(2,"Duplamente Encadeada");
    menu.setLargura(60);
    menu.setDelimitadorBorda('-');
    menu.trocarSairPorVoltar();
    return menu;
}
Menu menuListaCircular(){
    Menu menu;
    menu.inicializaMenu(4);
    menu.setTitulo("Menu Lista Circular");
    menu.setEntrada(1,"Simplesmente Encadeada sem no Descritor");
    menu.setEntrada(2,"Duplamente Encadeada sem no Descritor");
    menu.setEntrada(3,"Simplesmente Encadeada com no Descritor");
    menu.setEntrada(4,"Duplamente Encadeada com no Descritor");
    menu.setLargura(60);
    menu.setDelimitadorBorda('-');
    menu.trocarSairPorVoltar();
    return menu;
}
// 1 - Simplesmente Encadeada sem no Descritor --- 2 - Duplamente Encadeada sem no Descritor
// 3 - Simplesmente Encadeada com no Descritor --- 4 - Duplamente Encadeada com no Descritor
Menu menuListaCircularEnc(int i){
    Menu menu;
    menu.inicializaMenu(6);
    if ( i == 1 )
        menu.setTitulo("Simplesmente Encadeada sem no Descritor");
    else if ( i == 2 )
        menu.setTitulo("Duplamente Encadeada sem no Descritor");
    else if ( i == 3 )
        menu.setTitulo("Simplesmente Encadeada com no Descritor");
    else if ( i == 4 )
        menu.setTitulo("Duplamente Encadeada com no Descritor");
    menu.setEntrada(1,"Inicializar Lista");
    menu.setEntrada(2,"Inserir no Inicio da Lista");
    menu.setEntrada(3,"Inserir no Fim da Lista");
    menu.setEntrada(4,"Inserir em Lista Ordenada");
    menu.setEntrada(5,"Inserir sem Repeticao em Lista");
    menu.setEntrada(6,"Remover da Lista");
    menu.setLargura(60);
    menu.setDelimitadorBorda('-');
    menu.trocarSairPorVoltar();
    return menu;
}
Menu menuFila(){
    Menu menu;
    menu.inicializaMenu(4);
    menu.setTitulo("Menu Fila");
    menu.setEntrada(1,"Inicializar Fila");
    menu.setEntrada(2,"Inserir");
    menu.setEntrada(3,"Remover");
    menu.setEntrada(4,"Busca Primeiro");
    menu.setLargura(60);
    menu.setDelimitadorBorda('-');
    menu.trocarSairPorVoltar();
    return menu;
}
Menu menuPilha(){
    Menu menu;
    menu.inicializaMenu(4);
    menu.setTitulo("Menu Pilha");
    menu.setEntrada(1,"Inicializar Pilha");
    menu.setEntrada(2,"Empilha");
    menu.setEntrada(3,"Desempilha");
    menu.setEntrada(4,"Busca Topo");
    menu.setLargura(60);
    menu.setDelimitadorBorda('-');
    menu.trocarSairPorVoltar();
    return menu;
}

/// Operações em Menus
void estruturas(){
    // Definir e mostrar menu
    Menu menu = menuEstruturas();

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:
            opLista();
            break;
        case 2:
            opListaCircular();
            break;
        case 3:
            opFila();
            break;
        case 4:
            opPilha();
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
void opLista(){
    // Definir e mostrar menu
    Menu menu = menuLista();

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:
            opListaSimp();
            break;
        case 2:
            opListaDup();
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
void opListaCircular(){
    // Definir e mostrar menu
    Menu menu = menuListaCircular();

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:
            opListaCircularSimpSemNO();
            break;
        case 2:
            opListaCircularDupSemNO();
            break;
        case 3:
            opListaCircularSimpComNO();
            break;
        case 4:
            opListaCircularDupComNO();
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
// 1 - Simplesmente Encadeada sem no Descritor --- 2 - Duplamente Encadeada sem no Descritor
// 3 - Simplesmente Encadeada com no Descritor --- 4 - Duplamente Encadeada com no Descritor
/// Operações em Estruturas
void opListaCircularSimpSemNO(){
    // Definir e mostrar menu
    Menu menu = menuListaCircularEnc(1);

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:{
            cout<<endl<<endl<<"Lista Inicializada."<<endl;
            lcsesd.inicializaLista();
            ControleTela::pausa(0);
            }
            break;
        case 2:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcsesd.insereInicio(x);
            ControleTela::pausa(0);
            }
            break;
        case 3:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcsesd.insereFinal(x);
            ControleTela::pausa(0);
            }
            break;
        case 4:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcsesd.insereOrdenado(x);
            ControleTela::pausa(0);
            }
            break;
        case 5:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcsesd.insereSemRepeticao(x);
            ControleTela::pausa(0);
            }
            break;
        case 6:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Removido: ";
            cin>>x;
            noCircSemNoSimp *valor;
            valor = lcsesd.removeLista(x);
            if ( valor != NULL ){
                cout<<endl<<"Valor Removido: "<<valor->info;
            }
            ControleTela::pausa(0);
            }
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
void opListaCircularDupSemNO(){
    // Definir e mostrar menu
    Menu menu = menuListaCircularEnc(2);

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:{
            cout<<endl<<endl<<"Lista Inicializada."<<endl;
            lcdesd.inicializaLista();
            ControleTela::pausa(0);
            }
            break;
        case 2:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcdesd.insereInicio(x);
            ControleTela::pausa(0);
            }
            break;
        case 3:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcdesd.insereFinal(x);
            ControleTela::pausa(0);
            }
            break;
        case 4:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcdesd.insereOrdenado(x);
            ControleTela::pausa(0);
            }
            break;
        case 5:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcdesd.insereSemRepeticao(x);
            ControleTela::pausa(0);
            }
            break;
        case 6:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Removido: ";
            cin>>x;
            noCircSemNoDup *valor;
            valor = lcdesd.removeLista(x);
            if ( valor != NULL ){
                cout<<endl<<"Valor Removido: "<<valor->info;
            }
            ControleTela::pausa(0);
            }
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
void opListaCircularSimpComNO(){
    // Definir e mostrar menu
    Menu menu = menuListaCircularEnc(3);

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:{
            cout<<endl<<endl<<"Lista Inicializada."<<endl;
            lcsecd.inicializaLista();
            ControleTela::pausa(0);
            }
            break;
        case 2:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcsecd.insereInicio(x);
            ControleTela::pausa(0);
            }
            break;
        case 3:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcsecd.insereFinal(x);
            ControleTela::pausa(0);
            }
            break;
        case 4:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcsecd.insereOrdenado(x);
            ControleTela::pausa(0);
            }
            break;
        case 5:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcsecd.insereSemRepeticao(x);
            ControleTela::pausa(0);
            }
            break;
        case 6:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Removido: ";
            cin>>x;
            noCircComNoSimp *valor;
            valor = lcsecd.removeLista(x);
            if ( valor != NULL ){
                cout<<endl<<"Valor Removido: "<<valor->info;
            }
            ControleTela::pausa(0);
            }
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
void opListaCircularDupComNO(){
    // Definir e mostrar menu
    Menu menu = menuListaCircularEnc(4);

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:{
            cout<<endl<<endl<<"Lista Inicializada."<<endl;
            lcdecd.inicializaLista();
            ControleTela::pausa(0);
            }
            break;
        case 2:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcdecd.insereInicio(x);
            ControleTela::pausa(0);
            }
            break;
        case 3:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcdecd.insereFinal(x);
            ControleTela::pausa(0);
            }
            break;
        case 4:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcdecd.insereOrdenado(x);
            ControleTela::pausa(0);
            }
            break;
        case 5:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            lcdecd.insereSemRepeticao(x);
            ControleTela::pausa(0);
            }
            break;
        case 6:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Removido: ";
            cin>>x;
            noCircComNoDup *valor;
            valor = lcdecd.removeLista(x);
            if ( valor != NULL ){
                cout<<endl<<"Valor Removido: "<<valor->info;
            }
            ControleTela::pausa(0);
            }
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
void opFila(){
    Menu menu = menuFila();

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:{
            cout<<endl<<endl<<"Fila Inicializada."<<endl;
            f.inicializaFila();
            ControleTela::pausa(0);
            }
            break;
        case 2:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            f.insere(x);
            ControleTela::pausa(0);
            }
            break;
        case 3:{
            noFila *valor;
            valor = f.removeFila();
            if ( valor != NULL ){
                cout<<endl<<"Valor Removido: "<<valor->info;
            }
            ControleTela::pausa(0);
            }
            break;
        case 4:{
            noFila *valor;
            valor = f.buscaPrimeiro();
            if ( valor != NULL )
                cout<<endl<<"Valor Primeiro: "<<valor->info;
            else
                cout<<endl<<"Vazio";
            ControleTela::pausa(0);
            }
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
void opPilha(){
    Menu menu = menuPilha();

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:{
            cout<<endl<<endl<<"Pilha Inicializada."<<endl;
            p.inicializaPilha();
            ControleTela::pausa(0);
            }
            break;
        case 2:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            p.empilha(x);
            ControleTela::pausa(0);
            }
            break;
        case 3:{
            noPilha *valor;
            valor = p.desempilha();
            if ( valor != NULL )
                cout<<endl<<"Valor Removido: "<<valor->info;
            ControleTela::pausa(0);
            }
            break;
        case 4:{
            noPilha *valor;
            valor = p.buscaTopo();
            if ( valor != NULL )
                cout<<endl<<"Valor Topo: "<<valor->info;
            else
                cout<<endl<<"Vazio";
            ControleTela::pausa(0);
            }
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
void opListaSimp(){
    // Definir e mostrar menu
    Menu menu = menuListaEnc(0);

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:{
            cout<<endl<<endl<<"Lista Inicializada."<<endl;
            listaDin.inicializaLista();
            ControleTela::pausa(0);
            }
            break;
        case 2:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            listaDin.insereInicio(x);
            ControleTela::pausa(0);
            }
            break;
        case 3:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            listaDin.insereFinal(x);
            ControleTela::pausa(0);
            }
            break;
        case 4:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            listaDin.insereOrdenado(x);
            ControleTela::pausa(0);
            }
            break;
        case 5:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            listaDin.insereSemRepeticao(x);
            ControleTela::pausa(0);
            }
            break;
        case 6:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Removido: ";
            cin>>x;
            noListaDin *valor;
            valor = listaDin.removeLista(x);
            if ( valor != NULL )
                cout<<endl<<"Valor Removido: "<<valor->info;
            ControleTela::pausa(0);
            }
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}
void opListaDup(){
    // Definir e mostrar menu
    Menu menu = menuListaEnc(0);

    int op = -1;
    while ( op != 0 ){
        Portabilidade::limparTela();
        menu.mostrar();
        cin>>op;

        switch (op){
        case 1:{
            cout<<endl<<endl<<"Lista Inicializada."<<endl;
            listaDup.inicializaLista();
            ControleTela::pausa(0);
            }
            break;
        case 2:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            listaDup.insereInicio(x);
            ControleTela::pausa(0);
            }
            break;
        case 3:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            listaDup.insereFinal(x);
            ControleTela::pausa(0);
            }
            break;
        case 4:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            listaDup.insereOrdenado(x);
            ControleTela::pausa(0);
            }
            break;
        case 5:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Inserido: ";
            cin>>x;
            listaDup.insereSemRepeticao(x);
            ControleTela::pausa(0);
            }
            break;
        case 6:{
            int x;
            cout<<endl<<endl<<"Informe o Valor a ser Removido: ";
            cin>>x;
            noListaDup *valor;
            valor = listaDup.removeLista(x);
            if ( valor != NULL ){
                cout<<endl<<"Valor Removido: "<<valor->info;
            }
            ControleTela::pausa(0);
            }
            break;
        case 0:
            break;
        default:
            // Opcao Invalida
            ControleTela::pausa(1);
            break;
        }
    }
}

/// Definicao
void definicaoEstruturas(){
    Menu definicao;
    definicao.inicializaMenu(2);
    definicao.setEntrada(1,"Testa operacoes em diversos tipos de");
    definicao.setEntrada(2,"estruturas em alocacao dinamica");
    definicao.setTitulo("Definicao");
    definicao.setDelimitadorBorda('-');
    definicao.setLargura(0);
    definicao.setMostrarSairVoltar(false);
    definicao.setMostrarIndices(false);
    definicao.setMostrarDelimLateral(false);
    definicao.setMostrarOpcao(false);

    Portabilidade::limparTela();
    definicao.mostrar();
    ControleTela::pausa(0);
}
