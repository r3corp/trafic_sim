#ifndef PISTA_HEADER
#define PISTA_HEADER

#include "vector"
#include "Orientacao.hpp"
#include "Logger.hpp"

class UT; 

class Pista {
    private:
        int numero;

        std::vector<UT *> carros;

        Pista *aDireita, *aEsquerda;

        ~Pista() {}
    public:
		float tamanho = 200; // tamanho da pista. Inicialmente 3km.
        Pista(void) {}
        Pista(int numero) : numero(numero) {}
        bool geraCarro(int probabilidade);
        Pista *retornaPista(ORIENTACAO orientacao);
		int getId() { return numero; }
};

#endif