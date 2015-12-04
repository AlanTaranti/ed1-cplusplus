#ifndef CONTROLETELA_H
#define CONTROLETELA_H

#include <iostream>

#include "Portabilidade.h"

using namespace std;

class ControleTela{

    // Classe Abstrata
    virtual ~ControleTela()=0;

    // Valores:
    // 0 - Pausa comun
    // 1 - Opcao Invalida
    public: static void pausa(int x){
        switch (x){
        case 0:
            cout<<endl<<endl;
            break;
        case 1:
            cout<<endl<<"Opcao Invalida!"<<endl;
            break;
        default:
            break;
        }
        Portabilidade::pausarTela();
    }

};

#endif // CONTROLETELA_H
