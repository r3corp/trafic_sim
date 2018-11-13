#include "vector"
#include "Orientacao.hpp"
#include "Logger.hpp"

class UT; 

class Pista {
    private:
        int numero;
        float tamanho;

        std::vector<UT *> carros;

        Pista *aDireita, *aEsquerda;

        ~Pista() {}
    public:
        Pista(void) {}
        Pista(int numero) : numero(numero) {}
        void geraCarro(int probabilidade);
        Pista *retornaPista(ORIENTACAO orientacao);
};