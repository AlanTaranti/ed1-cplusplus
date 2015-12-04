#ifndef PORTABILIDADE_H
#define PORTABILIDADE_H

#include <stdlib.h>

class Portabilidade{

// Classe Abstrata
virtual ~Portabilidade()=0;

/// Métodos
public: static void limparTela(){
    #ifdef _WIN32
        char cls[] = "cls";
    #elif __linux__
        char cls[] = "clear";
    #endif
    system(cls);
}

public: static void pausarTela(){
    #ifdef _WIN32
        char pause[] = "pause";
    #elif __linux__
        char pause[] = "";
    #endif
    system(pause);
}
};

#endif // PORTABILIDADE_H
