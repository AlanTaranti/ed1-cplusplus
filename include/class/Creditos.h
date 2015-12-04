#ifndef CREDITOS_H
#define CREDITOS_H

#include "Portabilidade.h"
#include "Menu.h"

using namespace std;

class Creditos{

// Classe Abstrata
virtual ~Creditos()=0;

/// Métodos
public: static void showCreditos(){
    Portabilidade::limparTela();
    // Instancia Menu
    Menu creditos;
    creditos.inicializaMenu(4); // 4 Linhas
    // Linhas
    creditos.setEntrada(1,"Copyright (C) 2015 Alan Taranti.");
    creditos.setEntrada(2,"License GPLv3 +: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>");
    creditos.setEntrada(3,"This is free software: you are free to alter it and redistribute it.");
    creditos.setEntrada(4,"NO WARRANTY, to the extent permitted by law.");
    // Titulo
    creditos.setTitulo("LICENSE");
    // Delimitador
    creditos.setDelimitadorBorda('-');
    // Largura
    creditos.setLargura(0);
    // Não mostar: Indices, Sair, Borda Lateral e opçao
    creditos.setMostrarSairVoltar(false);
    creditos.setMostrarIndices(false);
    creditos.setMostrarDelimLateral(false);
    creditos.setMostrarOpcao(false);
    // Mostart menu
    creditos.mostrar();
    Portabilidade::pausarTela();
}
};

#endif // CREDITOS_H
