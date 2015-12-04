/*  Classe: Menu
    Desenvolvido por Alan Taranti

    Gera Menus Automaticamente

    ---------------------------------- LICENSE ----------------------------------
    Copyright (C) 2015 Alan Taranti.
    License GPLv3 +: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to alter it and redistribute it.
    NO WARRANTY, to the extent permitted by law.
    -----------------------------------------------------------------------------

    Funções Principais:
    void inicializaMenu(int);
        ** Primeiro Método a ser usado **
        Recebe como parametro a quantidade de intens no menu

    void setEntrada(int, string);
        Registra as entradas do Menu
        Primeiro parametro: Indice da entrada, maior que 1
        Segundo parametro: Nome da entrada

    void mostrar();
        Mostra na tela o Menu



    Funções Opcionais:

    void setTitulo(string);
        Registra  o titulo do Menu
        Recebe como parametro a nome do titulo

    void setDelimitadorBorda(char);
        Modifica o delimitador padrão do menu '#'

    void setLargura(int);
        Impede que o o menu defina a largura automaticamente
        Caso a largura settada seja menor que a necessária, ela seja ajustada conforme as entradas

    void setMostrarCreditos(bool);
        Define se mostra ou não a opção de credito. Padrão: Não Mostrar

    void setMostrarSairVoltar(bool);
        Define se mostra ou não a opção de Sair. Padrão: Mostrar

    void setMostrarIndices(bool);
        Define se mostra ou não os indices do menu. Padrão: Mostrar

    void setMostrarDelimLateral(bool);
        Define se mostra ou não os delimitadores laterais do menu. Padrão: Mostrar

    void setMostrarOpcao(bool);
        Define se mostra ou não a palvra "Opção: " no fim do menu. Padrão: Mostrar

    void trocarSairPorVoltar();
        Troca a opcao 0 de "Sair" por "Voltar"

*/



#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

class Menu{
    private: int largura;
    private: string *entradas;
    private: string titulo;
    private: int qtdeEntradas;
    private: int indiceSize;
    private: char delimitadorBorda = '#';
    private: int entradaMaxSize = 0;

    /// Chaves
    private: bool isLarguraFixa = false;
    private: bool mostrarCreditos = false;
    private: bool mostrarTitulo = false;
    private: bool mostrarSairVoltar = true;
    private: bool mostrarIndice = true;
    private: bool mostrarDelimLateral = true;
    private: bool mostrarOpcao = true;


    /// Inicialização
    public: void inicializaMenu(int numeroDeEntradas){
        this->qtdeEntradas = numeroDeEntradas;

        // Set Qtde Elementos
        this->entradas = new string[this->qtdeEntradas+2]; // Mais Um pra sair e mais Um pra creditos

        // Set Especiais
        this->setEntrada(0,"Sair");
        this->setEntrada(qtdeEntradas+1,"Creditos");

        // Quantidade de colunas para o Indice
        this->indiceSize = numeroDeEntradas/10 + 1;
    }

    /// Set Delimitador
    public: void setDelimitadorBorda(char delim){
        this->delimitadorBorda = delim;
    }

    /// Set Entradas
    public: void setEntrada(int indice, string entrada){
            this->entradas[indice] = entrada;
            if ( entrada.size() > this->entradaMaxSize)
                this->entradaMaxSize = entrada.size();
    }

    /// Set Titulo
    public: void setTitulo(string titulo){
            this->titulo = titulo;
            this->mostrarTitulo = true;
    }

    /// Set Largura
    public: void setLargura(int largura){
            this->largura = largura;
            this->isLarguraFixa = true;
    }

    /// Set Mostrar Creditos
    public: void setMostrarCreditos(bool estado){
        this->mostrarCreditos = estado;
    }

    /// Set Mostrar Sair
    public: void setMostrarSairVoltar(bool estado){
        this->mostrarSairVoltar = estado;
    }

    /// Set Mostrar Indices
    public: void setMostrarIndices(bool estado){
        this->mostrarIndice = estado;
    }

    /// Set Mostrar Delimitador Lateral
    public: void setMostrarDelimLateral(bool estado){
        this->mostrarDelimLateral = estado;
    }

    /// Set Mostrar Opcao no fim do Menu
    public: void setMostrarOpcao(bool estado){
        this->mostrarOpcao = estado;
    }

    /// Trocar Sair por Voltar
    public: void trocarSairPorVoltar(){
        this->setEntrada(0,"Voltar");
    }

    // Configurar largura automaticamente
    private: void setLarguraAutomaticamente(){
        string auxS = this->entradas[1];
        int maiorString = auxS.size();
        for ( int i = 2; i <= this->qtdeEntradas; i ++){
            auxS = this->entradas[i];
            if ( auxS.size() > maiorString )
                maiorString = auxS.size();
        }
        this->largura = maiorString + 6 + this->indiceSize + 10; // Quantidade Minima + 10 espaços livres
    }


    /// Gerar Menu
    public: void mostrar(){
        // Verificar se largura está setada
        if ( ! this->isLarguraFixa)
            this->setLarguraAutomaticamente();
        else{
            // Verificar se a largura setada eh menor do que a necessaria
            // Caso seja, largura fica exatamente igual a necessaria
            int larguraNecessaria = this->entradaMaxSize;
            if ( mostrarIndice ){ larguraNecessaria += (this->indiceSize + 3); }
            if ( mostrarDelimLateral ){ larguraNecessaria += 4; }
            if ( larguraNecessaria > this->largura ){ this->largura = larguraNecessaria; }
        }

        // Printar Titulo
        this->printTitulo();
        // Print Linha em Branco
        this->printLinhaEmBranco();
        // Print Entradas
        for ( int i = 1; i <= qtdeEntradas; i++ )
            this->printEntrada(i);

        // Printar Creditos
        if ( this->mostrarCreditos ){
            // Print Linha em Branco
            this->printLinhaEmBranco();
            this->printEntrada(this->qtdeEntradas+1);
        }

        // Printar Sair
        if ( this->mostrarSairVoltar ){
            // Print Linha em Branco
            this->printLinhaEmBranco();
            this->printEntrada(0);
        }

        // Print Linha em Branco
        this->printLinhaEmBranco();
        // Print Linha Inferior
        this->printDelimitadoresInf();
        // Opcao
        if ( this->mostrarSairVoltar )
            cout<<"Opcao: ";
        else
            cout<<endl;

    }

    // Printar Titulo
    private: void printTitulo(){
        // Se o titulo não estiver setado, printa o mesmo que a linha inferior
        if ( ! this->mostrarTitulo ){
            this->printDelimitadoresInf();
        }
        else{
            // Determina as metades a serem preenchudas pelos delimitadores
            int metade = ( this->largura - this->titulo.size() )/2 - 1; // Menos um por causa do espaço
            int outraMetade = this->largura - metade - 2 - this->titulo.size(); // Os dos a menos são relativos aos espaços

            // Printar primeira metade
            for (int i = 0; i < metade ; i++)
                cout<<this->delimitadorBorda;
            // Printa Titulo
            cout<<" "<<this->titulo<<" ";
            // Printar outra metade
            for (int i = 0; i < outraMetade  ; i++)
                cout<<this->delimitadorBorda;
            cout<<endl;
        }
    }


    // Printar Delimitador Inferior
    private: void printDelimitadoresInf(){
        for (int i = 0; i < this->largura; i++)
            cout<<this->delimitadorBorda;
        cout<<endl; // Nao usar por ser o maximo da tela
    }

    // Printar Linha em Branco
    private: void printLinhaEmBranco(){
        if ( this->mostrarDelimLateral ){
            cout<<this->delimitadorBorda;
            for (int i = 0; i < this->largura-2; i++)
                cout<<" ";
            cout<<this->delimitadorBorda;
        }
        cout<<endl;
    }

    // Printar Entrada
    private: void printEntrada(int indice){
        // Borda + Espaco
        if ( this->mostrarDelimLateral ){
            cout<<this->delimitadorBorda<<" ";
        }
        // Indice
        int espacoIndiceUsado = 0;
        if ( this->mostrarIndice ){
            espacoIndiceUsado = this->indiceSize + 3 ;
            int atualIndiceSize = indice/10 +1;
            int difenrencaIndiceSize = this->indiceSize - atualIndiceSize;
            for (int i = 0; i < difenrencaIndiceSize; i++ )
                cout<<"0";
            cout<<indice;
            // Espaco + Delimitador + Espaco
            cout<<" - ";
        }
        // Entrada
        cout<<this->entradas[indice];
        // Restante dos Espaços
        int espacosUsados = 2 + espacoIndiceUsado + this->entradas[indice].size(); // Borda + Espaco + Indice + Espaco + Delimitador + Espaco + Entrada.size
        for ( int i = espacosUsados; i < this->largura-2; i++)
            cout<<" ";
        // Borda
        if ( this->mostrarDelimLateral ){
            cout<<" "<<this->delimitadorBorda;
        }
        // Proxima Linha
        cout<<endl;
    }

};

#endif // MENU_H
